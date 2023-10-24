#pragma once
#include <iostream>
#include <string>
using namespace std;

class Employee
{
protected: // is this correct?
	string name;
	int id;
	int seniority;
	float pay=0;
public:
	Employee(string name, int id, int seniority); // do i initialize the pay here?
	Employee(); // empty ctor
	Employee(const Employee& other);
	void setName(string name);
	string getName();
	void setId(int id);
	int getId();
	void setSeniority(int senior);
	int getSeniority();
	void setPay(float pay);
	float getPay();
	float salaryAfterBonus();
	Employee& operator=(const Employee& emp);
	friend ostream& operator<<(ostream& os, const Employee& emp); // did i do this title line correctly?
	friend istream& operator>>(istream& is, Employee& emp); // title line correct?
};



