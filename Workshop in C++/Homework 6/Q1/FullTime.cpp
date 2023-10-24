#include "FullTime.h"

FullTime::FullTime(string name, int id, int seniority, float salaryPerYear)
{
	Employee(name, id, seniority);
	/*this->name = name;
	this->id = id;
	this->seniority = seniority;*/
	this->salaryPerYear = salaryPerYear;
	this->pay = salary(); // is this what i'm supposed to do?
}

FullTime::FullTime()
{
	// call the empty ctor for employee to get empty values for everything included in that class
	Employee();
	salaryPerYear = 0;
}

FullTime::FullTime(const FullTime& other)
{
	name = other.name;
	id = other.id;
	seniority = other.seniority;
	pay = other.pay;
	salaryPerYear = other.salaryPerYear;
}

void FullTime::setSalaryPerYear(float sal)
{
	salaryPerYear = sal;
}

float FullTime::getSalaryPerYear()
{
	return salaryPerYear;
}

float FullTime::salary()
{
	return (salaryPerYear/12);
}

//FullTime& FullTime::operator=(const FullTime& full)
//{
//		name = full.name;
//		id = full.id;
//		seniority = full.id;
//		pay = full.pay;
//		salaryPerYear = full.salaryPerYear;
//		return *this;
//}

ostream& operator<<(ostream& os, FullTime full)
{
	// do i need to make a new one or can i call the one from employee?
	os << "Employee: " << full.name << endl;
	os << "Employee ID: " << full.id << endl;
	os << "Years Seniority: " << full.seniority << endl;
	os << "Salary per Month: " << full.salary() << endl;
	return os;
}

istream& operator>>(istream& is, FullTime& full)
{
	string name;
	int id, seniority;
	float spy;
	cout << "Enter employee details: " << endl;
	is >> name >> id >> seniority >> spy; 
	full.setSeniority(seniority);
	full.setName(name);
	full.setId(id);
	full.setSalaryPerYear(spy);
	full.pay = full.salary();
	return is;
}
