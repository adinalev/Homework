
#include "Polygon.h"
#include "Point.h"
#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    int sides, x, y; 
    char lp, comma, rp;
    bool equal;
    Point point;
    cout << "enter number of sides: " << endl; //number of sides for the first polygon
    cin >> sides;
    if (sides <= 0) cout << "ERROR"; // if there is a negative input, return an error
    Polygon poly1(sides); //creating the first polygon
    cout << "enter the point values" << endl;
    // entering the values of the points into the array vertices of the first polygon
    for (int i = 0; i < sides; i++) {
        cin >> lp >> x >> comma >> y >> rp;
        point.setxValue(x);
        point.setyValue(y);
        poly1.addPoint(i, point);
    }
    cout << "enter number of sides: " << endl; //number of sides for the second polygon
    cin >> sides;
    if (sides <= 0) cout << "ERROR"; // if there is a negative input, return an error
    Polygon poly2(sides); // creating the second polygon
    cout << "enter the point values: " << endl;
    // entering the values of the points into the array vertices of the second polygon
    for (int i = 0; i < sides; i++) {
        cin >> lp >> x >> comma >> y >> rp;
        point.setxValue(x);
        point.setyValue(y);
        poly2.addPoint(i, point);
    }
    equal = poly1.equal(poly2); // to check if the polygons are equal
    //print corresponding message
    if (equal)
        // if they're equal, print "equal" and return the length of the perimeter 
        cout << "equal" << endl << "perimeter: " << round(poly2.perimeter()) << endl;
    else {
        // if they're not equal, print "not equal" and return each perimeter
        cout << "not equal " << endl;
        cout << "perimeter: " << round(poly1.perimeter()) << endl;
        cout << "perimeter: " << round(poly2.perimeter()) << endl;
    }

}
