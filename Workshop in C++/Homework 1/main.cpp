// Homework1.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include "Employee.h"
#include <string>
using namespace std;

int main()
{
    Employee leastEmp, temp;
    Employee highestEmp;
    int ssn = 0, hours = 0, numberEntry = 0;
    char name[21] = "johnDoe";
    float wage=0, moneyColl=0, highestSal=0;
    leastEmp.createEmployee(ssn, name, wage, hours, moneyColl);
    highestEmp.createEmployee(ssn, name, wage, hours, moneyColl);
    cout << "enter details, to end enter 0: ";
    cin >> ssn;
    while (ssn != 0) {
        cin >> name >> wage >> hours >> moneyColl;
        if (hours < 0 || wage < 0 || hours < 0 || moneyColl < 0) {
            cout << "ERROR" << endl;
        }
        else if (numberEntry == 0) {
            leastEmp.createEmployee(ssn, name, wage, hours, moneyColl);
            highestEmp.createEmployee(ssn, name, wage, hours, moneyColl);
            numberEntry++;
        }
        else if (numberEntry > 0) {
            temp.createEmployee(ssn, name, wage, hours, moneyColl);
            if (moneyColl < leastEmp.getMoneyColl()) {
                leastEmp.setSsn(ssn);
                leastEmp.setName(name);
                leastEmp.setWage(wage);
                leastEmp.setHours(hours);
                leastEmp.setMoneyColl(moneyColl);

            }
            if (temp.totalSal(temp) > highestEmp.totalSal(highestEmp)) {
                highestEmp.setSsn(ssn);
                highestEmp.setName(name);
                highestEmp.setWage(wage);
                highestEmp.setHours(hours);
                highestEmp.setMoneyColl(moneyColl);
            }
        }
        cin >> ssn;
    }
    highestSal = highestEmp.totalSal(highestEmp);
    cout << "minimum collected: " << leastEmp.getSsn() << " " << leastEmp.getName() << " " << leastEmp.getMoneyColl() << endl;
    cout << "highest salary: " << highestEmp.getSsn() << " " << highestEmp.getName() << " " << highestSal << endl;

}