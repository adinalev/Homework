/*
Adina Lev
566021464
Exercise 5 Question 2
This exerise deals with the class list. 
It merges two lists, removes duplicates, and reverses lists.
*/

#include <iostream>
#include "List.h"
using namespace std;

List merge(List lst1, List lst2)
{
	List lst3;
	List::Link* p1 = lst1.head;
	List::Link* p2 = lst2.head;
	/*lst3.insert(p1->value);
	lst3.insert(p2->value);
	p1 = p1->next;
	p2 = p2->next;*/
	while (p1 != nullptr) {
		lst3.insert(p1->value);
		p1 = p1->next;
	}
	while (p2 != nullptr) {
		lst3.insert(p2->value);
		p2 = p2->next;
	}
	return lst3;
}

void makeSet(List& lst)
{
	int val1, val2;
	List::Link* p1 = lst.head;
	if (p1 == nullptr) {
		return;
	}
	val1 = p1->value;
	p1 = p1->next;
	while (p1 != nullptr) {
		val2 = p1->value;
		if (val1 == val2) lst.remove(val1);
		val1 = val2;
		p1 = p1->next;
	}
}

void reverse(List& lst) // not really sure what this does
{
	List::Link* prev;
	List::Link* current;
	List::Link* newList;
	prev = nullptr;
	current = lst.head;
	newList = current;
	while (current != nullptr) {
		newList = current->next;
		current->next = prev;
		prev = current;
		//current = nextLink;
		current = newList;
	}
	lst.head = prev;
}

int main()
{
	List lst1, lst2, mergedList;

	cout << "enter sorted values for the first list:" << endl;
	cin >> lst1;
	cout << "enter sorted values for the second list:" << endl;
	cin >> lst2;

	mergedList = merge(lst1, lst2);
	cout << "the new merged list: " << mergedList << endl;

	makeSet(mergedList);
	cout << "the new merged set: " << mergedList << endl;

	reverse(mergedList);
	cout << "the new merged reverse: " << mergedList << endl;


	return 0;
}

/*
enter sorted values for the first list:
7 6 5 4 3 2 1 9
enter sorted values for the second list:

7 5 4 3 9
the new merged list: 7 7 6 5 5 4 4 3 3 2 1
the new merged set: 7 6 5 4 3 2 1
the new merged reverse: 1 2 3 4 5 6 7
*/
