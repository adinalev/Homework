#include "Shape.h"

Shape::Shape()
{
	numOfPoints = 0;
	pts = nullptr;
}

Shape::Shape(int numVertices)
{
	numOfPoints = numVertices;
	cout << "Enter values of " << numVertices << " points: ";
	pts = new Point[numVertices];
	for (int i = 0; i < numVertices; i++) {
		cin >> pts[i];
	}
}

Shape::Shape(const Shape& other)
// copy ctor
{
	numOfPoints = other.numOfPoints;
	pts = new Point[numOfPoints];
	for (int i = 0; i < numOfPoints; i++) { 
		pts[i] = other.pts[i];
	}
}
Shape::Shape(Shape&& other) // should I do a deep copy? I think this is fine
// move ctor
{
	numOfPoints = other.numOfPoints;
	pts = other.pts;
	other.pts = nullptr;
}

Shape::~Shape()
{
	numOfPoints = 0;
	if (pts) {
		pts = nullptr;
		delete[] pts;
	}
}

ostream& operator<<(ostream& os, Shape& shp)
{
	os << "points: "; 
	for (int i = 0; i < shp.numOfPoints; i++) {
		os << "(" << shp.pts[i].getxValue() << "," << shp.pts[i].getyValue() << ")";
		os << " ";
	}
	return os;
}

//ostream& operator<<(ostream& os, Shape shp)
//{
//	// TODO: insert return statement here
//}
