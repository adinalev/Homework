#pragma once
#include <iostream>
using namespace std;

class Employee
{
private:
	int ssn;
	char name[21]; //do i need to initialize the 21?
	float wage;
	int hours;
	float moneyColl;
public:
	void setSsn(int social);
	void setName(char n[]); //is this how i write an array in a method?
	void setWage(float w);
	void setHours(int hrs);
	void setMoneyColl(int mon);
	int getSsn();
	char* getName(); //do i need this?
	float getWage();
	int getHours();
	int getMoneyColl();
	float totalSal(Employee emp);
	void createEmployee(int ssn, char[], float wage, int hours, float moneyColl);
	float percent(Employee emp);
};
