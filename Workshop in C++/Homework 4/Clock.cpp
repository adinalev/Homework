#include "Clock.h"
#include <iostream>

Clock::Clock(int hour, int minute, int second)
{
	if (second < 0) {
		throw "Invalid time - negative number of seconds.";
	}
	if (second > 59) {
		throw "Invalid time - more than 60 seconds.";
	}
	if (minute < 0) {
		throw "Invalid time - negative number of minutes";
	}
	if (minute > 59) {
		throw "Invalid time - more than 60 minutes";
	}
	if (hour < 0) {
		throw "Invalid time - negative number of hours.";
	}
	if (hour > 24) {
		throw "Invalid time - more than 24 hours.";
	}
	this->second = second;
	this->minute = minute;
	this->hour = hour;
}

void Clock::setHour(int hr)
{
	if (hr < 0) {
		throw "Invalid time - negative number of hours.";
	}
	if (hr > 23) {
		throw "Invalid time - more than 24 hours.";
	}
	hour = hr;
}

void Clock::setMinute(int min)
{
	if (min < 0) {
		throw "Invalid time - negative number of minutes.";
	}
	if (min > 59) {
		throw "Invalid time - more than 60 minutes.";
	}
	minute = min;
}

void Clock::setSecond(int sec)
{
	if (sec < 0) {
		throw "Invalid time - negative number of seconds.";
	}
	if (sec > 59) {
		throw "Invalid time - more than 60 seconds.";
	}
	second = sec;
}

int Clock::getHour()
{
	return hour;
}

int Clock::getMinute()
{
	return minute;
}

int Clock::getSecond()
{
	return second;
}

Clock Clock::operator+=(int sec)
{
	int t1, t2, newSec, newMin;
	t1 = sec / 60; // this calculates the amount of minutes
	t2 = sec % 60; // this calculates the amount of seconds
	newSec = second + t2;
	if (newSec > 59) {
		if (minute == 59) {
			hour++;
			minute = 00;
			second = newSec - 60; // is this correct?
		}
		else {
			minute++;
			second = newSec - 60; //is this correct?
		}
	}
	else second = newSec;
	newMin = minute + t1;
	if (newMin > 59) {
		hour++;
		minute = newMin - 60; // is this correct?
	}
	else minute = newMin;
	return *this;
}

ostream& operator<<(ostream& os, Clock c) 
{
	if (c.hour < 10) os << "0";
	os << c.hour << ":";
	if (c.minute < 10) os << "0";
	os << c.minute << ":";
	if (c.second < 10) os << "0";
	os << c.second << "  "; // endl?
	return os;
}

istream& operator>>(istream& is, Clock& c)
{
	char junk;
	int hr, min, sec;
	is >> hr >> junk >> min >> junk >> sec;
	try { // NEED TO FIND A PLACE TO CATCH THESE. maybe don't make this a try. make a try in the main before reading in and then catch it afterwards
		c.setSecond(sec);
		c.setMinute(min);
		c.setHour(hr);
	}
	catch(const char* msg) { // do i need to catch this in the main?
		cout << msg << endl;
	}
	return is;
}
