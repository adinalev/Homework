#pragma once
#include <iostream>
using namespace std;

class List
{
	class Link
	{
	public:
		// data areas
		int value = 0;
		Link* next = nullptr;
	public:
		// constructor
		Link(int linkValue = 0, Link* nextPtr = nullptr);
		Link(const Link&);//cctor
		friend class List;

	};	//end of class Link


	// data field
	Link* head;

public:
	List();// empty ctor
	List(const List&);// copy ctor
	~List();// destructor
	//List(List&&) {} //move constructor -- DO I NEED THIS?

	void add(int value);// to insert into the front of the list
	int firstElement() const;// to view the first element of a list
	//bool search(const int& value) const; // to search for a key in list -- DO I NEED THIS?
	//Link* search(const int& value) const;// to search for key in list
	bool isEmpty() const;// to test if the list is empty
	void removeFirst();// to delete first element
	void clear();// to clear the list
	friend ostream& operator<<(ostream& os, const List& l);// to print the list
	List& operator=(const List& rhs); // assignment operator
	//List& operator=(List&&) {} // move assignment -- DO I NEED THIS?


};

