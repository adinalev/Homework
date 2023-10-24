#include "Soldier.h"
#include "PrivateSoldier.h"
#include "Commander.h"
#include "Officer.h"
#include <iostream>
#include <vector>
#include <list> // necessary?
#include <algorithm>
#include <string>
using namespace std;

void add(vector<Soldier*>& sld)
{
	int num, id, numOp, combat, socio, score;
	string first, last;
	cout << "choose a soldier" << endl;

	cout << "enter 1 to add a private\n";
	cout << "enter 2 to add a commander\n";
	cout << "enter 3 to add an officer\n";
	cin >> num;

	cout << "enter id, first name, last name and number of operations\n";
	cin >> id >> first >> last >> numOp;
	
	PrivateSoldier* ps = new PrivateSoldier;
	Commander* comm = new Commander;
	Officer* off = new Officer;

	switch (num) {
	case 1:
		//PrivateSoldier * ps = new PrivateSoldier;
		ps->setId(id);
		ps->setNumOfOp(numOp);
		ps->setFirstName(first);
		ps->setLastName(last);
	//	if (numOp == 0) ps->newScore(0);
	//	if (numOp > 0) {
			cout << "enter " << numOp << " grades\n";
			for (int i = 0; i < numOp; i++) {
				cin >> score;
				ps->newScore(score);
			}
	//	}
		sld.push_back(ps);
		break;
	case 2:
		//Commander * comm = new Commander;
		comm->setId(id);
		comm->setNumOfOp(numOp);
		comm->setFirstName(first);
		comm->setLastName(last);
	//	if (numOp == 0) ps->newScore(0);
	//	if (numOp > 0) {
			cout << "enter " << numOp << " grades\n";
			for (int i = 0; i < numOp; i++) {
				cin >> score;
				ps->newScore(score);
			}
	//	}
		cout << "enter 1 if the soldier is combat and 0 if not\n";
		cin >> combat;
		if (combat == 1) comm->setIsCombat(true);
		if (combat == 0) comm->setIsCombat(false);
		sld.push_back(comm);
		break;
	case 3:
		//Officer * off = new Officer;
		off->setId(id);
		off->setNumOfOp(numOp);
		off->setFirstName(first);
		off->setLastName(last);
		//cout << "enter " << numOp << " grades\n";
		cout << "enter the sociometric score\n";
		cin >> socio;
		off->setSocio(socio);
		sld.push_back(off);
		break;
	}
}

void printMedalList(vector<Soldier*> s)
{
	for (auto it = s.begin(); it != s.end(); it++) {
		if ((*it)->medal()) (*it)->print();
	}
}

Soldier* highestSociometricScore(vector<Soldier*> s)
{
	int highest = 0, test;
	Officer* best = nullptr;
	for (auto it = s.begin(); it != s.end(); it++) {
		if ((*it)->soldierType() == "officer") {
			//Soldier* soldier = new Officer; // necessary?
			test = ((Officer*)(*it))->getSocioMetric();
			if (test > highest) {
				highest = test;
				best = (Officer*)(*it); 
			}
		}
	}
	return best;
}

enum option {
	EXIT,	
	ADD_NEW_SOLDIER,	
	DESERVES_MEDAL,	
	HIGHEST_SOCIOMETRIC,	
	PRIVATE_MEDAL_COUNT,	
	NONCOMBAT_COMMANDER,	
	SUPER_SOLDIER,   
	REMOVE_OFFICER,	
};

int main()
{
	Soldier* s;
	vector<Soldier*> sold;  
	int op, count1 = 0, count2 = 0;
	cout << "enter 0-7\n";
	cin >> op;
	while (op != EXIT)
	{
		switch (op)
		{
		case ADD_NEW_SOLDIER:
			add(sold); 						
			break;
		case DESERVES_MEDAL:
			printMedalList(sold);  
			cout << endl;
			break;
		case HIGHEST_SOCIOMETRIC:   
			s = highestSociometricScore(sold); 
			cout << "Officer with the highest sociometric score: ";
			cout << s->getFirstName() << ' ' << s->getLastName() << endl;
			break;
		case PRIVATE_MEDAL_COUNT:  
			cout << "number of privates that received medals: ";
			for (auto it = sold.begin(); it != sold.end(); it++) {
				if ((*it)->soldierType() == "private" && (*it)->medal()) count1++;
			}
			cout << count1 << endl;
			break;
		case NONCOMBAT_COMMANDER: 
			cout << "list of noncombat commanders: ";    
			for (auto it = sold.begin(); it != sold.end(); it++) {
				if ((*it)->soldierType() == "commander" && ((Commander*)(*it))->getIsCombat() == false) {
					cout << (*it)->getFirstName() << " " << (*it)->getLastName() << " ";
				}
			}
			cout << endl;
			break;
		case SUPER_SOLDIER:
			for (auto it = sold.begin(); it != sold.end(); it++) {
				if ((*it)->getNumOfOp() > 15) count2++;
			}
			if (count2 >= 1) 
				cout << "there is at least one soldier that did more than 15 operations\n";
			else
				cout << "no soldier did more than 15 operations\n";
			break;
		case REMOVE_OFFICER:
			for (auto it = sold.begin(); it != sold.end(); it++) {
				if ((*it)->soldierType() == "officer" && (*it)->getNumOfOp() == 0) {
					sold.erase(it); // the it or the end it
				}
			}
			for (auto it = sold.begin(); it != sold.end(); it++) {
				(*it)->print();
				cout << endl;
			}
			break;
		};
		cout << "enter 0-7\n";
		cin >> op;
	}
	return 0;
}


