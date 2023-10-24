#pragma once
#include "Shape.h"
#include <cmath>

class Triangle : public Shape
{
	//do i include a protected class? -- DONT THINK SO BC IT INHERITS FROM SHAPE
public:
	Triangle(); // empty ctor -- HOW DO I DO THIS? NOT DONE!
	bool isSpecial() const override; // to see if triangle is equilateral
	void printSpecial() const override; // prints the special attribute of a triangle
	float area() const override; // to calculate the area of the triangle
	~Triangle(); // overridden deconstructor
};

