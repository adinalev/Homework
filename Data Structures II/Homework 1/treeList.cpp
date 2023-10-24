#include "treeList.h"
#include "tree.h"
//#include "DiscussionTree.h"
//#include "Node.h"

treeList::~treeList()
{
	for (auto it = trees.begin(); it != trees.end(); it++)
		delete (*it);
}

void treeList::addNewTree(string str)
{
	Tree* dt = new Tree();
	(*dt).addRoot(str); // do we need to un-dereference it?
	trees.push_front(dt); // should we do push_back??
}

void treeList::deleteTree(Tree* t)
{
	t->deleteAllSubTree(t->root);
	t = nullptr;
	// maybe should be a Node*?
}

void treeList::searchAndPrint(string str)
{
	//for (auto it = trees.begin(); it != trees.end(); it++)
	//{
	//	Node* parent;
	//	Node* p = (*it)->search((*it)->root, str, parent);
	//	if (p) // if the string is found in that tree
	//	{
	//		(*it)->print(p, 0); // print from the root till the occuring string
	//		(*it)->printSubTree(p->content); // print from that node to the end of that subtree
	//	}
	//}
	for (auto it = trees.begin(); it != trees.end(); ++it) {//go over list of all trees 
		cout << endl;
		if ((*it)->root) {
			(*it)->printSubTree(str);//print sub tree of s in tree
			if ((*it)->searchAndPrintPath(str))//search and print path in tree
				cout << (*it)->root->content;
		}
	}
}

bool treeList::addResponse(string title, string father, string son)
{
	for (auto it = trees.begin(); it != trees.end(); it++)
	{
		if ((*it)->root &&(*it)->root->content == title) // we have found where we want to add our response to
		{
			Node* parent;
			if ((*it)->search((*it)->root, father, parent))
			{
				if ((*it)->addSon(father, son)); // calls the addNode function in DiscussionTree class
				return true;
			}
		}
	}
	return false;
}

void treeList::printTree(string root)
{
	for (auto it = trees.begin(); it != trees.end(); it++)
	{
		(*it)->printAllTree(); // pretty sure it's this function
	}
}

void treeList::printAllTrees()
{
	int count = 1;
	if (!trees.empty())
	{
		for (auto it = trees.begin(); it != trees.end(); it++)
		{
			if ((*it)->root != nullptr)
			{
				cout << "Tree #" << count << endl;
				(*it)->printAllTree();
				count++;
				cout << endl;
			}
		}
	}	
}



void treeList::printSubTree(string rootStr, string discussion)
{
	for (auto it = trees.begin(); it != trees.end(); it++)
	{
		if ((*it)->root && (*it)->root->content == rootStr) // we have found where we want to add our response to
		{
			Node* parent;
			Node* p = (*it)->search((*it)->root, discussion, parent);
			if (!p)
				return;
			(*it)->printSubTree((*it)->root, discussion);
			if ((*it)->searchAndPrintPath((*it)->root, discussion)) //print path from the discussion to root using fat arrow notation
				cout << rootStr << endl;
			return;
		}
	}
	//cout << rootStr << "=>" << discussion;
}

bool treeList::delResponse(string rootStr, string nodeStr)
{
	for (auto it = trees.begin(); it != trees.end(); it++)
	{
		if ((*it)->root && (*it)->root->content == rootStr) // we have found where we want to add our response to
		{
			if ((*it)->removeNode(nodeStr))
				return true;		
		}
	}
	return false;
}
