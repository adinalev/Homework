#include "Tree.h"
//#include "DiscussionList.h"
#include "Node.h"
#include <list>
#include <queue>
using namespace std;

void Tree::addRoot(string str)
{
	Node* myRoot = new Node(str); // create a node with the given contents
	if (root != nullptr) // check if that node already has sons
		deleteAllSubTree(root); // if so then delete them all
	root = myRoot; // set the root equal to the created node
}

Node* Tree::search(Node* p, string str, Node*& parent)
{
	if (p->content == str)
		return p;
	if (p->responses.empty()) // MAYBE FOR THIS FONE DO RESPONSES.EMPTY
		return nullptr;
	for (auto it = p->responses.begin(); it != p->responses.end(); ++it) {// traverse through the responses
		Node* node = search(*it, str, node);
		if (node != nullptr)
			return node;
	}
	return nullptr;
}

bool Tree::searchAndPrintPath(Node* p, string val)
{
	if (p->content == val) {//s is current node
		//cout << n->content;//print the content
		return true;
	}
	if (p->responses.empty())//n has no responses
		return false;
	for (auto it = p->responses.begin(); it != p->responses.end(); ++it) {
		if (searchAndPrintPath(*it, val)) {
			cout << (*it)->content;//print node content
			cout << "=>";
			return true;
		}
	}
	return false;
}


bool Tree::addSon(string fatherNode, string childNode)
{
	Node* parent;
	Node* ptr = search(root, fatherNode, parent); // this is the tree calling
	if (ptr != nullptr)
	{
		Node* child = new Node(childNode); // create a new child node with the given string
		ptr->responses.push_back(child);
		ptr->isLeaf = false;
		return true;
	}
	return false;
}

bool Tree::deleteSubTree(string str)
{
	Node* parent;
	Node* p = search(root, str, parent); // find the str in the tree
	if (p)
	{
		deleteAllSubTree(p); // delete everything after that node
		return true;
	}
	return false;
}

void Tree::print(Node* p, int level)
{
	if (p)
	{
		for (int i = 0; i < level; i++) // for the hierarchical display
			cout << " ";
		cout << p->content << endl;
		if (p->isLeaf == false)
		{
			for (auto it = p->responses.begin(); it != p->responses.end(); it++)
			{
				print(*it, level + 3);
			}
		}
	}
}

bool Tree::printSubTree(Node* curr, string val)
{
	Node* parent;
	Node* p = search(curr, val, parent);
	if (p)
	{
		print(p);
		return true;
	}
	return false;
}

void Tree::deleteAllSubTree(Node* p)
{
	if (p)
	{
		if (p->isLeaf)
		{
			p = nullptr;
			return;
		}
		for (auto it = p->responses.begin(); it != p->responses.end(); it++)
		{
			deleteAllSubTree(*it);
			*it = nullptr;
			delete* it;
		}
		p = nullptr;
	}
}

bool Tree::removeNode(string str)
{
	Node* parent;
	Node* child = search(root, str, parent);
	if (!child)
		return false;
	if (child == root)
		root = nullptr;
	else
		removeFromList(root, str);
	removeNode(child);
	return true;
}

void Tree::removeNode(Node* p)
{
	if (!p->isLeaf)
	{
		for (auto it = p->responses.begin(); it != p->responses.end(); it++)
		{
			removeNode(*it);
		}
	}
}

bool Tree::removeFromList(Node* rootPtr, string str)
{
	bool flag = false;
	bool deleted = false;
	list<Node*>::iterator iterator;
	if (!rootPtr->isLeaf)
	{
		for (auto it = rootPtr->responses.begin(); it != rootPtr->responses.end(); it++)
		{
			if ((*it)->content == str)
			{
				flag = true;
				iterator = it;
			}
			else
				deleted = removeFromList(*it, str); // continue going through the responses recursively
		}
		if (flag)
		{
			rootPtr->responses.erase(iterator);
			deleted = true;
		}
	}
	return deleted;

}
