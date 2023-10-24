#pragma once
#include "Stack.h"
#include "StackList.h"
#include "Queue.h"
#include "QueueStack.h"
class QueueStack : public Queue
{
protected:
	Stack* data;
public:
	QueueStack();
	void clear() override;
	int dequeue() override;
	void enqueue(int value) override;
	int front() override;
	bool isEmpty() const override;
};


