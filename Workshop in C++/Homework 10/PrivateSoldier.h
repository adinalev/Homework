#pragma once
#include "Soldier.h"

class PrivateSoldier : public Soldier
{
protected:
	int* scores; // pointer to an array of evaluation scores
	int numOfScores = 0;
public:
	// not sure if this first constructor is correct
	PrivateSoldier(int idNum, string first, string last, int opNum); // ctor
	PrivateSoldier(); // empty ctor
	PrivateSoldier(PrivateSoldier&& ps); // move ctor
	PrivateSoldier(const PrivateSoldier& other); // copy ctor
	~PrivateSoldier(); // dtor // not sure if i should've used the one in soldier -- it wouldn't let me
	
	//overriden methods:
	bool medal() override;
	void print() override;
	string soldierType() override;

	// new method to calculate the average of scores:
	float average(); // use this for PrivateSoldier and also commander
	
	// new method to enter a new score
	void newScore(int score);
};

