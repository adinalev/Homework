/*
Adina Lev
566021464
Exercise 1 Question 3
This program collects data about circles and returns their circumferences, areas, and whether or not certain points lie within or on them.
*/

#include "Circle.h"
#include "Point.h"
using namespace std;

void Point::setxValue(int xvalue)
{
	x = xvalue;
}

int Point::getxValue()
{
	return x;
}

void Point::setyValue(int yvalue)
{
	y = yvalue;
}

int Point::getyValue()
{
	return y;
}