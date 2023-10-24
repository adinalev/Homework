#include "Employee.h"

Employee::Employee(string name, int id, int seniority)
{
	this->name = name;
	this->id = id;
	//this->pay = pay;
	this->pay = 0;
	if (seniority < 0) throw "ERROR";
	this->seniority = seniority;
}

Employee::Employee()
{
	name = "";
	id = 0;
	seniority = 0;
	pay = 0;
}

Employee::Employee(const Employee& other)
{
	name = other.name; // or do i need to do strcopy?
	id = other.id;
	seniority = other.seniority;
	pay = other.pay;

}

void Employee::setName(string name)
{
	this->name = name;
}

string Employee::getName()
{
	return name;
}

void Employee::setId(int id)
{
	this->id = id;
}

int Employee::getId()
{
	return id;
}

void Employee::setSeniority(int senior)
{
	if (senior < 0) throw "ERROR";
	seniority = senior;
}

int Employee::getSeniority()
{
	return seniority;
}

void Employee::setPay(float pay)
{
	this->pay = pay;
}

float Employee::getPay()
{
	return pay;
}

float Employee::salaryAfterBonus()
{
	float bonus = 0;
	if (seniority <= 5) bonus = 500;
	else {
		bonus = this->pay * (.25);
	}
	return (bonus + this->pay);
}

//Employee& Employee::operator=(const Employee& emp)
//{
//	name = emp.name;
//	id = emp.id;
//	seniority = emp.id;
//	pay = emp.pay;
//	return *this;
//}

ostream& operator<<(ostream& os, const Employee& emp)
{
	os << "Employee: " << emp.name << endl;
	os << "Employee ID: " << emp.id << endl;
	os << "Years Seniority: " << emp.seniority << endl;
	return os;
}

istream& operator>>(istream& is, Employee& emp)
{
	string name;
	int id, seniority;
	cout << "Enter employee details: " << endl;
	is >> name >> id >> seniority;
	emp.setSeniority(seniority);
	emp.setName(name);
	emp.setId(id);
	return is;
}
