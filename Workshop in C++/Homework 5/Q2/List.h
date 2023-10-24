#pragma once
#include <iostream>
using namespace std;

class List
{
	// put the public before the private so I would be able to declare an array
	// of links in the private arena
public:
	class Link {
	public:
		int value; // this is the key of the element
		Link* next; // next is a pointer to a link
		Link(const Link& source); // copy ctor
		Link(int val, Link* nxt); // regular ctor
	};
	List(); // empty ctor
	//~List(); // dtor
	void clear();
	bool isEmpty();
	List& operator=(const List& other);
	void insert(int key);
	void remove(int key);
	void removeFirst();
	void add(int key);
	friend istream& operator>>(istream& is, List& L);
	friend ostream& operator<<(ostream& os, const List& L);
public:
	Link* head; // this head points to the beginning of the list
};

