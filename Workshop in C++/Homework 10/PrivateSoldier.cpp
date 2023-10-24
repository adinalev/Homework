#include "PrivateSoldier.h"

PrivateSoldier::PrivateSoldier(int idNum, string first, string last, int opNum) : Soldier(idNum, first, last, opNum)
{
}

PrivateSoldier::PrivateSoldier() : Soldier()
{
	/*id = 0;
	firstName = "";
	lastName = "";
	numOfOp = 0;*/
	for (int i = 0; i < numOfOp; i++) {
		scores[i] = 0;
	}
}

PrivateSoldier::PrivateSoldier(PrivateSoldier&& ps)
{
	id = ps.id;
	firstName = ps.firstName;
	lastName = ps.lastName;
	numOfOp = ps.numOfOp;
	scores = ps.scores;
	ps.scores = nullptr;
}


PrivateSoldier::PrivateSoldier(const PrivateSoldier& other)
{
	this->id = other.id;
	this->firstName = other.firstName;
	this->lastName = other.lastName;
	this->numOfOp = other.numOfOp;
	this->scores = new int[numOfOp];
	for (int i = 0; i < numOfOp; i++) {
		this->scores[i] = other.scores[i];
	}
}

PrivateSoldier::~PrivateSoldier()
{
	id = 0;
	firstName = "";
	lastName = "";
	numOfOp = 0;
	if (scores) delete[] scores;
	scores = nullptr;
}

bool PrivateSoldier::medal()
{
	return (numOfOp >= 10 && average() > 95);
}

void PrivateSoldier::print()
{
	cout << "private" << endl;
	cout << "ID: " << id << endl;
	cout << "first name: " << firstName << endl;
	cout << "last name: " << lastName << endl;
	cout << "num operations: " << numOfOp << endl;
	cout << "grades: ";
	for (int i = 0; i < numOfOp; i++) {
		cout << scores[i] << " ";
	}
}

string PrivateSoldier::soldierType()
{
	return "private";
}

float PrivateSoldier::average()
{
	int sum = 0;
	float average = 0;
	for (int i = 0; i < numOfOp; i++) {
		sum += scores[i];
	}
	average = (float)sum / numOfOp;
	return average;
}

void PrivateSoldier::newScore(int score)
{
	///*int* newScores;
	//int newSize = numOf + 1;*/
	//int* newScores = new int[numOfScores + 1];
	///*if (scores[0] > 0) {*/
	//	for (int i = 0; i < numOfScores; i++) {
	//		newScores[i] = scores[i];
	//	}
	////}
	//newScores[numOfScores] = score;
	//delete scores;
	//scores = newScores;
	//numOfScores += 1;
	int* newScores;
	int newSize = numOfScores + 1;
	newScores = new int[newSize] {};

	for (int i = 0; i < numOfScores; i++)
		newScores[i] = scores[i];

	newScores[numOfScores] = score;
	delete[] scores;
	scores = newScores;
	numOfScores += 1;
}
