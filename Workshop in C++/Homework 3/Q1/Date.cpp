#include "Date.h"
#include <iostream>
using namespace std;

Date::Date(int day, int month, int year)
// regular and default ctor
{
	if (day < 1 || day > 30) { // if the month isn't within legal range
		cout << "ERROR day " << endl;
		this->day = 1;
	}
	else this->day = day;
	if (month < 1 || month > 12) { // if the month isn't within legal range
		cout << "ERROR month " << endl;
		this->month = 1;
	}
	else this->month = month;
	if (year < 1920) { // if the year isn't within legal range
		cout << "ERROR year " << endl;
		this->year = 1920;
	}
	else this->year = year;
}

Date::Date(const Date& other)
// copy ctor
{
	day = other.day;
	month = other.month;
	year = other.year;
}

void Date::setDate(int day, int month, int year)
// sets the date to the assigned values
{
	if (day > 0 && day < 31 && month > 0 && month < 13 && year >= 1920) {
		this->day = day;
		this->month = month;
		this->year = year;
	}
}

Date Date::operator=(const Date& other)
// assigns a date to a different date
{
	day = other.day;
	month = other.month;
	year = other.year;
	return *this;
}

Date Date::operator++()
// pre autoincrement
{
	if (day == 30) {
		if (month == 12) {
			year++;
			month = 1;
			day = 1;
		}
		else {
			month++;
			day = 1;
		}
	}
	else {
		day++;
	}
	return *this;
}

Date Date::operator++(int u)
//post auto increment
{
	Date current = *this;
	if (current.day == 30) {
		if (current.month == 12) {
			current.year++;
			current.month = 1;
			current.day = 1;
		}
		else {
			current.month++;
			current.day = 1;
		}
	}
	else {
		current.day++;
	}
	return current;
}

bool Date::operator>(const Date& other) const
// "greater than" operator which tests if the left date is later than the right date.
{
	if (year != other.year) return (year > other.year);
	if (month != other.month) return (month > other.month);
	if (day != other.day) return (day > other.day);
	return false;
}

bool Date::operator<(const Date& other) const
//"less than" operator which tests if the left date is earlier than the right date.
{
	if (year != other.year) return (year < other.year);
	if (month != other.month) return (month < other.month);
	if (day != other.day) return (day < other.day);
	return false;
}

bool Date::operator==(const Date& other) const
// "is equal to" operator which tests if two dates are equal to each other.
{
	return (day == other.day && month == other.month && year == other.year);
}

void Date::print()
// print method
{
	cout << day << "/" << month << "/" << year;
}

