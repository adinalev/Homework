#pragma once
#include "List.h"
#include <iostream> 
using namespace std;

class RoundList : public List
{
//private:// am i supposed to do this?
//	Link* head;
public:
	RoundList(); // empty ctor
	~RoundList(); // I think override
	void addToEnd(int val);
	int search(int n); // override
	friend ostream& operator<<(ostream& os, RoundList rl);
	//Link* head;
};

