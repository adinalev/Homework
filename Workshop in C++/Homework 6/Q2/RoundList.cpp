#include "RoundList.h"
#include "List.h"

ostream& operator<<(ostream& os, RoundList rl)
{
	// current points to the head of the list
	List::Link* p = rl.head;
	while (p != nullptr) { // while the head is not pointing to null
		os << p->value << " "; // print the value sitting in the node which p is pointing to
		p = p->next; // set p equal to the node that is the next of the node p is pointing to 
	}
	return os;
}

//RoundList::RoundList(int linkValue, Link* nextPtr)
//{
//	List(linkValue, nextPtr);
//}

RoundList::RoundList() : List()
{
}

RoundList::~RoundList()
{
	clear();
}

void RoundList::addToEnd(int val)
{
	if (isEmpty()) add(val); // add to the beginning if the list is empty
	else {
		Link* p = head;
		while (p->next != nullptr) p = p->next; // move over p until it's at the last element of the list
		Link* newLink = new Link(val, nullptr);
		p->next = newLink;
	}
}

int RoundList::search(int n)
{
	if (isEmpty()) return -1;
	if (n == 0) return head->value;
	else {
		Link* p = head;
		for (int i = 0; i < n; i++) {
			if (p->next == nullptr) p->next = head;
			p = p->next;
		}
		return p->value;
	}
}

//ostream& operator<<(ostream& os, RoundList rl)
//{
//	List::Link* p = rl.head;
//	if (rl.isEmpty()) return os;
//	while (p != nullptr) {
//		cout << p->value << " ";
//	}
//	return os;
//}
