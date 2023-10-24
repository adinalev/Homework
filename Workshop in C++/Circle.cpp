#include "Circle.h"

Circle::Circle(int rad) : Shape(1)
{
	radius = rad;
	//numOfPoints = 1;
	//pts = new Point[1];
	//pts[0] = ; // how do I know the center of a circle?
}

Circle::Circle(const Circle& other)
{
	numOfPoints = other.numOfPoints;
	pts = new Point[numOfPoints]; // do i need +1?
	for (int i = 0; i < numOfPoints; i++) { // do I need +1?
		pts[i] = other.pts[i];
	}
	radius = other.radius;
}

bool Circle::isSpecial() const
{
	return ((pts[0].getxValue() == 0) && (pts[0].getyValue() == 0));
}

void Circle::printSpecial() const
{
	if (isSpecial()) 
		cout << "A canonical circle with a radius " << radius << endl;
}

float Circle::area() const
{
	const float PI = 3.14;
	return (PI * radius * radius);
}

Circle::~Circle()
{
	radius = 0;
	numOfPoints = 0;
	if (pts) {
		pts = nullptr;
		delete[] pts;
	}
}
