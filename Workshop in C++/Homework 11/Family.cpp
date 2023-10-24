#include "Family.h"
#include "string.h"
#include <cstring>
#include <string>

Family::Family(int id, char* lastName, int members, int phone, short int acts, short int wa)
{
	this->id = id;
	if (lastName == nullptr) {
		this->lastName[0] = 0;
	}
	else {
		strcpy_s(this->lastName, lastName);
	}
	famMembers = members;
	phoneNumber = phone;
	activities = acts;
	waitingActivities = wa;
}

Family::Family(const Family& fam)
{
	id = fam.id;
	strcpy_s(lastName, fam.lastName);
	famMembers = fam.famMembers;
	phoneNumber = fam.phoneNumber;
	activities = fam.activities;
	waitingActivities = fam.waitingActivities;
}

void Family::setID(int id)
{
	this->id = id;
}

void Family::setName(char* name)
{
	strcpy_s(lastName, name);
}

void Family::setFamMems(int members)
{
	famMembers = members;
}

void Family::setPhone(int phone)
{
	phoneNumber = phone;
}

void Family::setActivities(short int act)
{
	activities = act;
}

void Family::setWaitingActivities(short int wa)
{
	waitingActivities = wa;
}

int Family::getID() const
{
	return id;
}

string Family::getName() const
{
	return lastName;
}

int Family::getFamMems() const
{
	return famMembers;
}

int Family::getPhone() const
{
	return phoneNumber;
}

short int Family::getActivities() const
{
	return activities;
}

short int Family::getWaitingActivities() const
{
	return waitingActivities;
}
