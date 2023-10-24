#pragma once
class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date(int day = 1, int month = 1, int year = 1920); // default and regular ctor
	Date(const Date& other); // copy ctor
	void setDate(int days, int mon, int yr); //  sets the date to the assigned values
	void print(); // print method that prints dd/yy/yyyy.
	Date operator=(const Date& other); // assigns a date to a different date
	Date operator++(); // pre autoincrement
	Date operator++(int u); // post autoincrement
	bool operator>(const Date& other) const; // "greater than" operator which tests if the left date is later than the right date.
	bool operator<(const Date& other) const; //"less than" operator which tests if the left date is earlier than the right date.
	bool operator==(const Date& other) const; // "is equal to" operator which tests if two dates are equal to each other.


};


