/*
Adina Lev
566021464
Exercise 6 Question 1
This questions deals with parttime and fulltime employees which are both classes which inherit from the class employee.
This code reads in employee data, calculates their salaries and bonuses, and outputs the new data.
*/

#include "Employee.h"
#include "FullTime.h"
#include "PartTime.h"
#include <iostream>
using namespace std;
int main()
{
	FullTime arrF[3]; // change to 3
	for (int i = 0; i < 3; i++) // same
	{
		try
		{
			cin >> arrF[i];
		}
		catch (const char* str)
		{
			cout << str << endl;
			i--;
		}
	}


	PartTime arrP[3]; // change to 3
	for (int i = 0; i < 3; i++) // same
	{
		try
		{
			cin >> arrP[i];
		}
		catch (const char* str)
		{
			cout << str << endl;
			i--;
		}
	}


	for (int i = 0; i < 3; i++) // change to 3
	{
		cout << arrF[i];
		cout << "After Bonus: " << arrF[i].salaryAfterBonus() << endl;
		cout << endl; // added this!!
	}


	for (int i = 0; i < 3; i++) // change to 3
	{
		cout << arrP[i];
		cout << "After Bonus: " << arrP[i].salaryAfterBonus() << endl;
	}
	return 0;
}

/*
Enter employee details:
moshe 1234 3 36000
Enter employee details:
miriam 4321 8 48000
Enter employee details:
aharon 5678 4 160 35
Employee: moshe
Employee ID: 1234
Years Seniority: 3
Salary per Month: 3000
After Bonus: 3500
Employee: miriam
Employee ID: 4321
Years Seniority: 8
Salary per Month: 4000
After Bonus: 5000
Employee: aharon
Employee ID: 5678
Years Seniority: 5678
Hours: 160
Salary per Month: 5600
After Bonus: 6100
*/

