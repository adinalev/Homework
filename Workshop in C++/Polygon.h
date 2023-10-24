#pragma once
#include "Point.h"

class Polygon {
private:
	Point* vertices; // creating the dynamic array of Points
	int numVertices;
public:
	Point* getVertices(); // getter function for the array of Points
	int getNumVertices(); // getter function for the amount of vertices the polygon has
	Polygon(); //the empty constructor
	Polygon(int numv); // the regular constructor
	Polygon(const Polygon& other); // the copy constructor
	~Polygon(); // the destructor
	void addPoint(int index, Point vertex); // method to add a Point value into the vertices array
	float perimeter(); // method to find the perimeter of a polygon
	bool equal(Polygon poly); // method to find out if two polygons are equal
};
