#pragma once
#include <iostream>
#include "Employee.h"
using namespace std;

class FullTime : public Employee
{
private:
	float salaryPerYear;
public:
	FullTime(string name, int id, int seniority, float salaryPerYear);
	FullTime(); // empty ctor
	FullTime(const FullTime& other); // copy ctor
	void setSalaryPerYear(float sal);// DID NOT WRITE - DO NOT KNOW
	float getSalaryPerYear(); // don't know
	float salary(); // for calculating the employee's monthly salary - DONT KNOW
	FullTime& operator=(const FullTime& full);
	friend ostream& operator<<(ostream& os, FullTime full);
	friend istream& operator>>(istream& is, FullTime& full);
};

