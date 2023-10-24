#pragma once
#include "Point.h"
#include <iostream>
using namespace std;

class Shape
{
protected:
	int numOfPoints = 0; // number of vertices of the shape
	Point* pts; // for storing the points of the shope
public:
	Shape(); // empty ctor
	Shape(int numVertices); // regular ctor -- FINISH THIS
	Shape(const Shape& other); // copy ctor for deep copy
	Shape(Shape&& other); // move ctor -- DID I DO THIS RIGHT?
	virtual ~Shape(); //virtual deconstructor
	friend ostream& operator<<(ostream& os, Shape& shp);
	virtual float area() const = 0; // const method for computing the area of the shape
	virtual bool isSpecial() const = 0; // const method that returns true if the shape has a special attribute
	virtual void printSpecial() const = 0; // const method that prints the special attribute

};

