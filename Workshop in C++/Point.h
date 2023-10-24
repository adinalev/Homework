#pragma once
class Point
{
private:
	int x;
	int y;
public: 
	void setxValue(int xv); // setter for x
	int getxValue(); // getter for x
	void setyValue(int yv); // setter for y
	int getyValue(); // getter for y
	float distance(Point p); // method to calculate the distance between two points
	Point(); // empty constructor
	Point(int xv, int yv); // regular constructor
	Point(const Point & other); //copy constructor
	~Point(); // destructor
};

