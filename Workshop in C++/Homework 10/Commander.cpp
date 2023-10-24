#include "Commander.h"

bool Commander::medal()
{
	if (isCombat && numOfOp >= 7) {
			int sum = 0;
			for (int i = 0; i < numOfOp; i++)
				sum += scores[i];
			if (sum/ numOfOp > 90)
				return true;
	}
		return false;
}
		//&& average() > 90);

void Commander::print() 
{
	cout << "commander" << endl;
	cout << "ID: " << id << endl;
	cout << "first name: " << firstName << endl;
	cout << "last name: " << lastName << endl;
	cout << "num operations: " << numOfOp << endl;
	cout << "grades: ";
	for (int i = 0; i < numOfOp; i++) {
		cout << scores[i] << " ";
	}
	cout << "combat: ";
	if (isCombat) cout << "yes" << endl;
	else cout << "no";
}

string Commander::soldierType()
{
	return "commander";
}

//Commander::Commander() : PrivateSoldier()
//{
//}
//
//Commander::Commander(Commander&& comm)
//{
//	id = comm.id;
//	firstName = comm.firstName;
//	lastName = comm.lastName;
//	numOfOp = comm.numOfOp;
//	scores = comm.scores;
//	comm.scores = nullptr;
//}
//
//Commander::Commander(const Commander& other)
//{
//	id = other.id;
//	firstName = other.firstName;
//	lastName = other.lastName;
//	numOfOp = other.numOfOp;
//	scores = new int[numOfOp];
//	for (int i = 0; i < numOfOp; i++) {
//		scores[i] = other.scores[i];
//	}
//}

void Commander::setIsCombat(bool ic)
{
	isCombat = ic;
}

bool Commander::getIsCombat()
{
	return isCombat;
}
