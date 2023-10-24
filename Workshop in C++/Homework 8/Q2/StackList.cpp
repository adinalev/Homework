#include "StackList.h"

StackList::StackList() :data()
{
}

StackList::StackList(const StackList& lst)
    : data(lst.data)
{    /* copy constructor*/
}

void StackList::clear()
{
    // clear all elements from the stack by clearing the list
    data.clear();
}

bool StackList::isEmpty() const
// returns true if the stack is empty
{
    return data.isEmpty();
}

int StackList::pop()
// to return and remove the first element in the list
{
    int result = data.firstElement(); // first get what the first element of the list is
    data.removeFirst(); // then remove the first element of the list
    return result; // return the stored value
}

void StackList::push(int val)
// push the given value onto the stack
{
    data.add(val);
}

int StackList::top()
// return what's sitting in the beginning of the list (i.e. top of the stack)
{
    return data.firstElement();
}






