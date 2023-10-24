#include "Soldier.h"

Soldier::Soldier(int idNum, string first, string last, int opNum)
{
	id = idNum;
	firstName = first;
	lastName = last;
	numOfOp = opNum;
}

Soldier::Soldier()
{
	id = 0;
	firstName = "";
	lastName = "";
	numOfOp = 0;
}

Soldier::~Soldier()
{
	id = 0;
	firstName = "";
	lastName = "";
	numOfOp = 0;
}

void Soldier::setId(int idNum)
{
	id = idNum;
}

int Soldier::getId()
{
	return id;
}

void Soldier::setFirstName(string first) 
{
	firstName = first;
}

string Soldier::getFirstName()
{
	return firstName;
}

void Soldier::setLastName(string last)
{
	lastName = last;
}

string Soldier::getLastName()
{
	return lastName;
}

void Soldier::setNumOfOp(int opNum)
{
	numOfOp = opNum;
}

int Soldier::getNumOfOp()
{
	return numOfOp;
}
