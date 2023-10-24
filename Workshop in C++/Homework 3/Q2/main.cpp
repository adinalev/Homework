/*
Adina Lev
566021464
Exercise 3 Question 2
This code deals with dates. It updates the date if the given value is within the acceptable range,
does a pre and post auto increment update on the dates, assigns a Date to a different date value,
and compares two dates to see if they're greater than, less than, or equal to each other.
*/
#include "Date.h"
#include <iostream>
using namespace std;

// enum operator to set values for the different operations
enum OPERATOR {
    EXIT, UPDATE_DATE, ADD_PRE, ADD_POST, ASSIGN_PRINT, GREATER_THAN, LESS_THAN, EQUAL_TO
};

int main()
{

    int d, m, y;
    char slash;
    cout << "Enter a date " << endl;
    cin >> d >> slash >> m >> slash >> y;
    Date d1(d, m, y); // reads in the date
    Date d2, d3; // creates two default dates
    d1.print(); // prints out the first date
    cout << endl;
    int code = 1;
    cout << "Enter a code " << endl;
    cin >> code;
    // while the user does not input a 0
    while (code != EXIT) {
        // run the switch statement
        switch (code) {
        case UPDATE_DATE:
            cout << "Enter a date " << endl;
            cin >> d >> slash >> m >> slash >> y;
            // set the day to the inputted values if they're legal
            d1.setDate(d, m, y);
            d1.print();
            cout << endl;
            break;
        case ADD_PRE:
            // pre auto increment
            d2 = ++d1;
            d2.print();
            cout << endl;
            d1.print();
            cout << endl;
            break;
        case ADD_POST:
            // post auto increment
            d2 = d1++;
            d1.print();
            cout << endl;
            d2.print();
            cout << endl;
            break;
        case ASSIGN_PRINT:
            // assigns a date to a different date and prints the new date out
            cout << "Enter a date " << endl;
            cin >> d >> slash >> m >> slash >> y;
            d3.setDate(d, m, y);
            d1 = d3;
            d1.print();
            cout << endl;
            break;
        case GREATER_THAN:
            // tests if a date is greater than a different one
            cout << "Enter a date " << endl;
            cin >> d >> slash >> m >> slash >> y;
            d3.setDate(d, m, y);
            d1.print();
            cout << " > ";
            d3.print();
            cout << " : ";
            if (d1 > d3) cout << "true" << endl;
            else cout << "false" << endl;
            break;
        case LESS_THAN:
            // tests if a date is less than a different one
            cout << "Enter a date " << endl;
            cin >> d >> slash >> m >> slash >> y;
            d3.setDate(d, m, y);
            d1.print();
            cout << " < ";
            d3.print();
            cout << " : ";
            if (d1 < d3) cout << "true" << endl;
            else cout << "false" << endl;
            break;
        case EQUAL_TO:
            // tests if a date is equal to a different one
            cout << "Enter a date " << endl;
            cin >> d >> slash >> m >> slash >> y;
            d3.setDate(d, m, y);
            d1.print();
            cout << " == ";
            d3.print();
            cout << " : ";
            if (d1 == d3) cout << "true" << endl;
            else cout << "false" << endl;
            break;
        }
        cout << "Enter a code " << endl;
        cin >> code;
    }
    return 0;
}
/*
Enter a date
-5/1/2012
ERROR day
1/1/2012
Enter a code
1
Enter a date
5/7/2010
5/7/2010
Enter a code
2
6/7/2010
6/7/2010
Enter a code
3
6/7/2010
7/7/2010
Enter a code
4
Enter a date
14/7/2010
14/7/2010
Enter a code
5
Enter a date
14/7/2010
14/7/2010 > 14/7/2010 : false
Enter a code
7
Enter a date
14/7/2010
14/7/2010 == 14/7/2010 : true
Enter a code
0
*/