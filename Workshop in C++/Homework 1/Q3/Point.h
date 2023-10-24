#pragma once
#include "Circle.h"
#include <iostream>


class Point
{
	// this is a class to hold each point
private:
	int x;
	int y;
public:
	void setxValue(int xvalue);
	int getxValue();
	void setyValue(int yvalue);
	int getyValue();
};