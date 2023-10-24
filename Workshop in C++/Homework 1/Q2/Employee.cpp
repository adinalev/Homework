#include "Employee.h"
using namespace std;


void Employee::setSsn(int social)
{
	ssn = social;
}

void Employee::setName(char names[])
{
	strcpy_s(name, names);
}

void Employee::setWage(float w)
{
	wage = w;
}

void Employee::setHours(int hrs)
{
	hours = hrs;
}

void Employee::setMoneyColl(int mon)
{
	moneyColl = mon;
}

int Employee::getSsn()
{
	return ssn;
}

char* Employee::getName()
{
	return name;
}

float Employee::getWage()
{
	return wage;
}

int Employee::getHours()
{
	return hours;
}

int Employee::getMoneyColl()
{
	return moneyColl;
}

float Employee::totalSal(Employee emp)
{
	int hrs, wage;
	float perc, finalSalary;
	hrs = emp.getHours();
	wage = emp.getWage();
	perc = percent(emp);
	finalSalary = hrs * wage + perc;
	return finalSalary;
}

float Employee::percent(Employee emp)
{
	float total = emp.getMoneyColl();
	if (total <= 1000) {
		total = total * 0.1;
	}
	if (total <= 2000) {
		total = 100 + (total - 1000) * (.15);
	}
	if (total <= 4000) {
		total = 250 + (total - 2000) * (.2);
	}
	if (total <= 5000) {
		total = 650 + (total - 4000) * (.3);
	}
	if (total > 5000) {
		total = 950 + (total - 5000) * (.4);
	}
	return total;
}


void Employee::createEmployee(int ssn, char[], float wage, int hours, float moneyColl)
{
	Employee emp;
	emp.setSsn(ssn);
	emp.setName(name);
	emp.setWage(wage);
	emp.setHours(hours);
	emp.setMoneyColl(moneyColl);
}
