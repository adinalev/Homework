#pragma once
#include "Employee.h"

class PartTime : public Employee
{
private:
	float hoursOfWork;
	float payPerHour;
public:
	PartTime(string name, int id, int seniority, float how, float pph);
	PartTime();
	PartTime(const PartTime& other);
	void setHoursOfWork(float how);
	float getHoursOfWork();
	void setPayPerHour(float pph);
	float getPayPerHour();
	float salary();
	PartTime& operator=(const PartTime& part);
	friend ostream& operator<<(ostream& os, PartTime part);
	friend istream& operator>>(istream& is, PartTime& part);

};

