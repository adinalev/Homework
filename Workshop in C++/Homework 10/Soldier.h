#pragma once
#include <iostream>
using namespace std;

class Soldier
{
protected:
	int id;
	string firstName;
	string lastName;
	int numOfOp = 0;
public:
	Soldier(int idNum, string first, string last, int opNum); // ctor // AM I ALLOWED TO DO THIS?
	Soldier(); // default ctor
	virtual ~Soldier(); // virtual destructor

	//virtual methods:
	virtual bool medal() = 0;
	virtual void print() = 0; // for printing soldier data -- do i define it in this class?
	virtual string soldierType() = 0; // method that will return a string value based on the type of solder that the soldier is

	// setter and getters:
	void setId(int idNum);
	int getId();
	void setFirstName(string first);
	string getFirstName();
	void setLastName(string last);
	string getLastName();
	void setNumOfOp(int opNum);
	int getNumOfOp();

	//virtual int getSocioMetric();
};

