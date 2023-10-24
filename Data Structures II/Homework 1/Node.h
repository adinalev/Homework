#pragma once
#include <iostream>
#include <list>
#include <string>
using namespace std;

class Node;

//Node: each Node in the discussion tree
class Node
{
	//void removeSonValue(string v);
public:
	list<Node*> responses;
	string content;
	bool isLeaf;
	Node(string v) { isLeaf = true;  content = v; }

	friend class Tree;
};
