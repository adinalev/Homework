#include "List.h"
#include <iostream>
using namespace std;

List::List()
// empty ctor
{
	// to make a list empty, the head just need to be pointing to null
	head = nullptr;
}
List::~List()
{
	clear();
}
void List::clear()
{
	if (isEmpty()) return; //WRITE ISEMPTY
	Link* p = head;
	Link* next = p->next; // a link is linking to another link
	while (!next) { // !next means next != null
		p->next = nullptr;
		delete p;
		p = next;
		next = p->next;
	}
	delete p;
	head = nullptr;
}
bool List::isEmpty()
{
	return (head == nullptr);
}

List& List::operator=(const List & rhs)
	// deep assignment operator
{
	// if the rhs is an empty list, then make the lhs an empty list
	if (rhs.head == nullptr) head = nullptr;
	else {
		Link* p1;
		Link* p2;
		head = new Link(rhs.head->value, nullptr);
		p1 = rhs.head;
		p2 = head;
		while (p1->next != nullptr) {
			p2->next = new Link((p1->next->value), nullptr); // instead of nullptr should I put p1->next?
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	return *this; // correct return statement?
}

ostream& operator<<(ostream& os, const List& lst)
{
	// current points to the head of the list
	int key;
	List::Link* p = lst.head;
	while (p != nullptr) { // while the head is not pointing to null
		os << p->value << " "; // print the value sitting in the node which p is pointing to
		p = p->next; // set p equal to the node that is the next of the node p is pointing to 
	}
	return os;
}
istream& operator>>(istream& is, List& lst)//inputs sorted elements.
{
	int key1, key2;
	is >> key1;
	List::Link* p = new List::Link(key1, nullptr);
	lst.head = p;
	is >> key2;
	while (key1 > key2)//while inputs the sorted numbers, and stops when its out of order
	{
		p->next = new List::Link(key2, nullptr);
		p = p->next;
		key1 = key2;
		is >> key2;
	}
	return is;
}

// copy ctor
List::Link::Link(const Link& source) :value(source.value), next(source.next) {}

// regular ctor
List::Link::Link(int val, Link* nxt) :
	value(val), next(nxt) {}

void List::insert(int key)
{
	Link* lnk;
	// if the list is empty, set the head equal to the value given
	if (head == nullptr) {
		head = new Link(key, nullptr);
		return;
	}
	Link* p = head;
	// if the value is greater then the head
	if (key > p->value) {
		add(key);
		return;
	}
	// find where to put the value
	while (p->next != nullptr && p->next->value > key) { // correct conditions? is it > or >=?
		p = p->next;
	}
	/*if ((p == head) && p->next != nullptr) {
		lnk = new Link(key, p);
		head = lnk;
	}*/
	lnk = new Link(key, p->next);
	p->next = lnk;
}

void List::remove(int key)
{
	Link* p = head;
	bool found = false;
	if (p->value == key) {
		removeFirst();
		return;
	}
	while (p->next != nullptr && found == false) {
		if (p->next->value == key) {
			Link* temp = p->next->next;
			delete p->next;
			p->next = temp;
			found = true;
			// return ?
		}
		else p = p->next;
	}
	if (found == false) throw "value not found"; // need to catch this exception
	// return?
}

void List::removeFirst()
{
	// make sure there is a first element
	if (isEmpty())
		throw "the List is empty, no Elements to remove";
	// save pointer to the removed node
	Link * p = head;
	// reassign the first node
	head = p->next;
	p->next = nullptr;
	// recover memory used by the first element
	delete p;
}

void List::add(int val)
{
	//Add a new value to the front of a Linked List
	head = new Link(val, head);
	/*if (head == nullptr)
		throw "failed in memory allocation";*/
}
