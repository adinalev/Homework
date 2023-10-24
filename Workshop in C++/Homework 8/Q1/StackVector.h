#pragma once
#include <iostream>
#include "Vector.h"
#include "Stack.h"
using namespace std;

template <class T>
class StackVector : public Stack<T> 
{
private:
	Vector<T> data; 
public:
	StackVector(); // empty ctor 
	StackVector(T capacity); // constructor 
	StackVector(const StackVector<T>& sv); // copy ctor
	void clear(); 
	bool isEmpty() const; 
	T pop();
	void push(T val);
	T top();
};

template<class T>
inline StackVector<T>::StackVector()
{
}

template<class T>
inline StackVector<T>::StackVector(T capacity) : data(capacity) {} 

 template<class T>
inline StackVector<T>::StackVector(const StackVector<T>& sv) : data(sv.data) {}

template<class T>
inline void StackVector<T>::clear()
{
	data.clear();
}

template<class T>
inline bool StackVector<T>::isEmpty() const
{
	return data.isEmpty();
}

template<class T>
inline T StackVector<T>::pop()
{
	if (isEmpty())
		throw "Stack is empty";
	return data.delLast();
}

template<class T>
inline void StackVector<T>::push(T val)
{
	data.insert(val);
}

template<class T>
inline T StackVector<T>::top()
{
	if (isEmpty())
		throw "Stack is empty";
	return data[data.getSize() - 1]; 
}




