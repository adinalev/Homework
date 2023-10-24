#pragma once
#include "Shape.h"

class Circle : public Shape
{
private:
	float radius;
public:
	Circle(int rad); // regular ctor for circle
	Circle(const Circle& other); //copy ctor
	bool isSpecial() const override; // test if the circle is canonical
	void printSpecial() const override; // prints the special attribute of a circle
	float area() const override; // prints the area of a circle -- not sure if I should put a circle in there?
	~Circle(); // overridden deconstructor
};

