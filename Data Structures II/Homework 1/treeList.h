#pragma once
#include <list>
#include "Tree.h"
#include "Node.h"
using namespace std;

class treeList
{
	list<Tree*> trees;

public:
	treeList() {}
	~treeList();
	void addNewTree(string s);
	void deleteTree(Tree*);
	void searchAndPrint(string val);
	bool addResponse(string rt, string prnt, string res);
	bool delResponse(string rt, string res);
	void printTree(string rt);
	void printAllTrees();
	void printSubTree(string rt, string s);
};


//class DiscussionList
//{
//	list<DiscussionTree*> discussionTreeList;
//
//	DiscussionList();
//	~DiscussionList();
//	void createDiscTree(string str); // Creates a new discussion tree
//	void deleteDiscTree(Node* rootPtr);
//	void search(string str);
//	void addDiscussion(string rootStr, string respondTo, string response);
//	void printDiscTree(string root); // Receives a string which is the root of a tree, and prints the whole tree, in a hierarchical display
//	void printSubTree(string root, string discussion); // Receives a string which is the root of a tree, and a string of a discussion in the tree (a node), and prints the path from the root to the node, as well as the whole sub-tree starting from that node, in a hierarchical display.
//	void deleteDisc(string rootStr, string nodeStr);
//};

