/*
Adina Lev
566021464
Exercise 1 Question 3
This program collects data about circles and returns their circumferences, areas, and whether or not certain points lie within or on them.
*/

#include "Circle.h"
#include "Point.h"
using namespace std;

void Circle::setCenter(int x, int y)
{
	// need to use a class Point in order to set the center of the circle
	Point temp;
	temp.setxValue(x);
	temp.setyValue(y);
	center = temp;
}

Point Circle::getCenter()
{
	return center;
}

int Circle::getRadius()
{
	return radius;
}

void Circle::setRadius(int rad)
{
	radius = rad;
}

float Circle::area(int radius)
{
	// to calculate the area of a circle
	const float PI = 3.14;
	float area = PI * radius * radius;
	return area;
}

float Circle::circumference(int radius)
{
	// to calculate the perimeter/circumference of a circle
	const float PI = 3.14;
	float circum = 2 * PI * radius;
	return circum;
}

int Circle::pointLies(Point p)
{
	// this is getting the value of (x-x1)^2
	float diffx = pow(p.getxValue() - getCenter().getxValue(), 2);
	//this is getting the value of (y-y1)^2
	float diffy = pow(p.getyValue() - getCenter().getyValue(), 2);
	//the square root of the two above powers is the distance
	float distance = sqrt(diffx + diffy);
	// if the point lies outside the circle, return 1
	if (distance > radius) return 1;
	// if the point lies inside the circle, return -1
	if (distance < radius) return -1;
	// if the point is on the circle return 0
	if (distance == radius) return 0;
}


