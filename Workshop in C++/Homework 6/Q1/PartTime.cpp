#include "PartTime.h"

PartTime::PartTime(string name, int id, int seniority, float how, float pph)
{
	Employee(name, id, seniority);
	payPerHour = pph;
	pay = salary(); // I think this is what to do?
	if (how < 0) throw "ERROR";
	hoursOfWork = how;
}

PartTime::PartTime()
{
	Employee();
	hoursOfWork = 0;
	payPerHour = 0;
}

PartTime::PartTime(const PartTime& other)
{
	name = other.name;
	id = other.id;
	seniority = other.seniority;
	pay = other.pay;
	hoursOfWork = other.hoursOfWork;
	payPerHour = other.payPerHour;
}

void PartTime::setHoursOfWork(float how)
{
	if (how < 0) throw "ERROR";
	hoursOfWork = how;
}

float PartTime::getHoursOfWork()
{
	return hoursOfWork;
}

void PartTime::setPayPerHour(float pph)
{
	payPerHour = pph;
}

float PartTime::getPayPerHour()
{
	return payPerHour;
}

float PartTime::salary()
{
	return (hoursOfWork * payPerHour);
}

//PartTime& PartTime::operator=(const PartTime& part)
//{
//	name = part.name;
//	id = part.id;
//	seniority = part.id;
//	pay = part.pay;
//	hoursOfWork = part.hoursOfWork;
//	payPerHour = part.payPerHour;
//	return *this;
//}

ostream& operator<<(ostream& os, PartTime part)
{
	os << "Employee: " << part.name << endl;
	os << "Employee ID: " << part.id << endl;
	os << "Years Seniority: " << part.seniority << endl;
	os << "Hours: " << part.hoursOfWork << endl;
	os << "Salary per Month: " << part.salary() << endl;
	return os;
}

istream& operator>>(istream& is, PartTime& part)
{
	string name;
	int id, seniority;
	float how, pph;
	cout << "Enter employee details: " << endl;
	is >> name >> id >> seniority >> how >> pph;
	part.setSeniority(seniority);
	part.setName(name);
	part.setId(id);
	part.setHoursOfWork(how);
	part.setPayPerHour(pph);
	part.pay = part.salary();
	return is;
}
