#include "QueueStack.h"

QueueStack::QueueStack()
{
	data = new StackList();
}

void QueueStack::clear()
{
	while (!data->isEmpty()) data->pop();
}

int QueueStack::dequeue()
{
	return data->pop();
}

void QueueStack::enqueue(int value)
{
	Stack* temp = new StackList();
	int tempVal;
	while (!data->isEmpty()) {
		temp->push(data->pop()); // push each element of data into temp
		//tempVal = data->pop(); // pop the top element of the stack
		//temp->push(tempVal); // push it onto a temporary stack so we do not lose the value
	}
	data->push(value); // push the value onto the bottom of the stack
	while (!temp->isEmpty()) {
		data->push(temp->pop()); // push each element of temp into data
	}
}

int QueueStack::front()
{
	return data->top();
}

bool QueueStack::isEmpty() const
{
	return (data->isEmpty());
}
