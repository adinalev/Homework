#include "Point.h"
#include <cmath>

void Point::setxValue(int xv)
// setter function for the x value
{
	x = xv;
}

int Point::getxValue()
// getter function for the x value
{
	return x;
}

void Point::setyValue(int yv)
// setter function for the y value
{
	y = yv;
}

int Point::getyValue()
// getter function for the y value

{
	return y;
}

float Point::distance(Point p)
// method to calculate and return the distance between two different points
{
	float diffx = pow(p.getxValue()-x, 2);
	float diffy = pow(p.getyValue()-y, 2);
	float distance = sqrt(diffx + diffy);
	return distance;
}

Point::Point()
// empty constructor
{
	x = 0;
	y = 0;
}

Point::Point(int xv, int yv)
// regular constructor
{
	x = xv;
	y = yv;
}

Point::Point(const Point& other)
// copy constructor
{
	x = other.x;
	y = other.y;
}

Point::~Point()
// destructor
{
	if (x) x = NULL;
	if (y) y = NULL;
}
