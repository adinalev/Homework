/*
Adina Lev
566021464
Exercise 1 Question 3
This program collects data about circles and returns their circumferences, areas, and whether or not certain points lie within or on them.
*/

#pragma once 
#include <iostream>
#include <cmath>
#include "Point.h"

class Circle
{
private:
	// this is a class to hold each circle
	Point center;
	int radius;
public:
	void setCenter(int x, int y);
	Point getCenter();
	int getRadius();
	void setRadius(int rad);
	float area(int radius);
	float circumference(int radius);
	int pointLies(Point p);
};