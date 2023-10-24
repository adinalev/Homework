#include "Officer.h"

int Officer::getSocioMetric()
{
    return socioMetric;
}

bool Officer::medal()
{
	return (numOfOp >= 2 && socioMetric >= 92);
}

void Officer::print()
{
	cout << "officer" << endl;
	cout << "ID: " << id << endl;
	cout << "first name: " << firstName << endl;
	cout << "last name: " << lastName << endl;
	cout << "num operations: " << numOfOp << endl;
	cout << "sociometric score: " << socioMetric << endl;
}

string Officer::soldierType()
{
	return "officer";
}

void Officer::setSocio(int sm)
{
	socioMetric = sm;
}