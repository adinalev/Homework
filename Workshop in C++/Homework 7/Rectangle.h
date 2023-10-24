#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
public:
	Rectangle(); //empty ctor -- HOW DO I DO THIS??
	bool isSpecial() const override; // to check if it's a square -- DIDNT DO YET
	void printSpecial() const override; // to print the special attribute
	float area() const override; // calculates the area of the square
	~Rectangle(); // overridden destructor
};

