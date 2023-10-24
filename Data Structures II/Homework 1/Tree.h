#pragma once
#include "Node.h"

using namespace std;
//Tree: the discussion Tree
class Tree
{
	Node* root;
	Node* search(Node* p, string val, Node*& parent);
	//returns Node t where the string equals val. If t has a prent, the pointer parent will contain its address. 

	bool searchAndPrintPath(Node* p, string val);
	void print(Node* p, int level = 0);
public:
	Tree() { root = NULL; }
	~Tree() {
		deleteAllSubTree(root);
		root = 0;
	}
	void deleteAllSubTree(Node* t);
	void addRoot(string newval);
	bool addSon(string fatherdiscussion, string newresponse);
	bool search(string val)
	{
		Node* parent;
		if (search(root, val, parent))
			cout << root->content << endl;
	}
	bool searchAndPrintPath(string val)
	{
		bool flag = searchAndPrintPath(root, val);
		return flag;
	}

	void printAllTree() { print(root); }
	void printSubTree(string val) { printSubTree(root, val); }
	bool printSubTree(Node* curr, string val);
	bool deleteSubTree(string val);
	bool removeNode(string str); // to see if a node can be removed
	void removeNode(Node* p); // to delete that node
	bool removeFromList(Node* p, string str);  // to remove the node from the root's list
	
	friend class treeList;
};

//class DiscussionTree
//{
//	Node* root;
//
//public:
//	DiscussionTree() { root = nullptr; } // creates and empty tree
//	~DiscussionTree(); // destructor
//	void createRoot(string str); // Creates a root with given contents (and deleting the previous tree emanating from this root, if exists)
//
//	Node* find(string str); // receives a string, and returns a pointer to the node which contains that string
//	Node* findHelper(Node* p, string str);
//	void addNode(string fatherNode, string childNode); // Adds a node to the tree, as the child of another node
//	void deleteSub(string str); // Given a string, deletes the subtree starting from the node which contains that string
//	void deleteAllSub(Node* p); // delete the subtree of the node sent in
//	void printTree(); // Prints the complete tree, in a hierarchical display
//	void printHelper(Node* p, int level);
//	void printPath(string str); // Given a string, finds the node containing that string and prints the path from the root to it
//	void printPathHelper(Node* p, int level, string str);
//	void printNodePath(string str); // Given a string, searches for a node containing the given string, and prints the tree emanating starting from that node, all the way down to the leaves, in a hierarchical display (i.e., prints the whole discussion from the given point)
//
//};

