#pragma once
#include "List.h"		
#include "Stack.h"

class StackList : public Stack
{
public:
    StackList();
    StackList(const StackList&);

    void clear() override;
    bool isEmpty() const override;
    int pop() override;
    void push(int value) override;
    int top() override;

protected:
    // data fields
    List data;
};

