#pragma once

template<class T>
class Stack
{
public:
	virtual void clear() = 0;
	virtual bool isEmpty() const = 0;
	virtual T pop() = 0;
	virtual void push(T value) = 0;
	virtual T top() = 0;
};

