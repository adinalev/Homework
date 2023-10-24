#pragma once
#include <iostream>
using namespace std;

class Clock
{
private:
	int hour = 00;
	int minute = 00;
	int second = 00;
public:
	Clock(int hour = 00, int minute = 00, int second = 00);
	void setHour(int hr);
	void setMinute(int min);
	void setSecond(int sec);
	int getHour();
	int getMinute();
	int getSecond();
	Clock operator+=(int seconds);
	friend ostream& operator<<(ostream& os, Clock c);  //os?
	friend istream& operator>>(istream& is, Clock& c);
};

