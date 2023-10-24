#pragma once
#include <string>
#include <iostream>
using namespace std;

class Family
{
private:
	int id;
	char lastName[20];
	int famMembers;
	int phoneNumber;
	short int activities; // huh? --> is it supposed to be single short int like in the doc?
	short int waitingActivities; // do i also need to put this in a ctor?
public:
	Family(int id = 0, char* lastName = nullptr, int members = 0, int phone = 0, short int acts = 0, short int wa = 0);
	Family(const Family& fam); // copy ctor
	//Family(Family&& fam); // move ctor -- DO I NEED THIS?

	// setters and getters
	void setID(int id);
	void setName(char* name);
	void setFamMems(int members);
	void setPhone(int phone);
	void setActivities(short int act);
	void setWaitingActivities(short int wa);
	int getID() const;
	string getName() const;
	int getFamMems() const;
	int getPhone() const;
	short int getActivities() const;
	short int getWaitingActivities() const;
};

