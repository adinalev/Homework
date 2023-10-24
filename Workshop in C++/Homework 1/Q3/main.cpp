/*
Adina Lev
566021464
Exercise 1 Question 3
This program collects data about circles and returns their circumferences, areas, and whether or not certain points lie within or on them.
*/
#include "Circle.h"
#include "Point.h"
#include <iostream>
using namespace std;

int main()
{
	Circle a, b, c;
	int x1, y1, radius1, x2, y2, radius2, x3, y3, radius3;
	int insideA = 0, insideB = 0, insideC = 0; // these will be used to see if a point lies within or on a circle
	char lt, rt, co; // parenthesis and comma for user to enter when writing the point
	cout << "enter the center point and radius of 3 circles: ";
	cin >> lt >> x1 >> co >> y1 >> rt >> radius1 >> lt >> x2 >> co >> y2 >> rt >> radius2 >> lt >> x3 >> co >> y3 >> rt >> radius3;
	// setting the radius and center of each circle
	a.setCenter(x1, y1);
	a.setRadius(radius1);
	b.setCenter(x2, y2);
	b.setRadius(radius2);
	c.setCenter(x3, y3);
	c.setRadius(radius3);
	// printing all the perimeters/circumferences
	cout << "perimeter:	A: " << a.circumference(a.getRadius()) << "	B: " << b.circumference(b.getRadius())
		<< "	C: " << c.circumference(c.getRadius());
	cout << endl;
	//printing all the areas
	cout << "area:	A: " << a.area(a.getRadius()) << "	B: " << b.area(b.getRadius())
		<< "	C: " << c.area(c.getRadius());
	cout <<  endl;
	cout << "enter points until (0,0): ";
	int xvalue=0, yvalue=0;
	while (xvalue || !xvalue) {
		cin >> lt >> xvalue >> co >> yvalue >> rt;
		//stop the program if a (0,0) is inputted
		if (xvalue == 0 && yvalue == 0) break;
		Point temp;
		temp.setxValue(xvalue);
		temp.setyValue(yvalue);
		// testing to see if one of the points lies within or on the circle
		if (a.pointLies(temp) <= 0) {
			insideA++;
		}
		if (b.pointLies(temp) <= 0) {
			insideB++;
		}
		if (c.pointLies(temp) <= 0) {
			insideC++;
		}
	}
	// printing how many points lie within each circle
	cout << "num of points in circle:	A: " << insideA++ << "	B: " << insideB << "	C: " << insideC;
	return 0;
}
/*
enter the center point and radius of 3 circles: (0,0)3 (1,1)2 (5,5)2
perimeter:      A: 18.84        B: 12.56        C: 12.56
area:   A: 28.26        B: 12.56        C: 12.56
enter points until (0,0): (0,1) (1,0) (0,4) (0,0)
num of points in circle:        A: 2    B: 2    C: 0
*/

