#include "Triangle.h"

Triangle::Triangle() : Shape(3) {}
//{
//	// how do i do this??
//	Triangle tri;
//	tri = Shape(3); // huh?
//}

bool Triangle::isSpecial() const
{
	return (pts[0].distance(pts[1]) == pts[1].distance(pts[2]) == pts[2].distance(pts[0]));
}

void Triangle::printSpecial() const
{
	if (isSpecial()) {
		cout << "An equilateral triangle with a side length ";
		cout << pts[0].distance(pts[1]);
	}
}

float Triangle::area() const
{
	float side1, side2, side3, part1, area;
	side1 = pts[0].distance(pts[1]);
	side2 = pts[1].distance(pts[2]);
	side3 = pts[2].distance(pts[0]);
	part1 = (side1 + side2 + side3) / 2;
	area = sqrt(part1 * (part1 - side1) * (part1 - side2) * (part1 - side3));
	return area;
}

Triangle::~Triangle()
{
	numOfPoints = 0;
	if (pts) {
		pts = nullptr;
		delete[] pts;
	}
}
