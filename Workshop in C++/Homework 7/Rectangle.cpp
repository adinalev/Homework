#include "Rectangle.h"
#include <cmath>
#include <iostream>
using namespace std;

Rectangle::Rectangle() : Shape(4) {}
//{
//}

bool Rectangle::isSpecial() const
{
    float side1, side2, side3, side4;
    /*side1 = sqrt((pow(Shape :: pts[1].getxValue() - pts[0].getxValue()), 2) + pow((pts[1].getyValue() - pts[0].getyValue())));
    side2 = sqrt((pow(pts[2].getxValue() - pts[1].getxValue()), 2) + pow((pts[2].getyValue() - pts[1].getyValue())));
    side3 = sqrt((pow(pts[3].getxValue() - pts[2].getxValue()), 2) + pow((pts[3].getyValue() - pts[2].getyValue())));
    side4 = sqrt((pow(pts[0].getxValue() - pts[3].getxValue()), 2) + pow((pts[0].getyValue() - pts[3].getyValue())));*/
    side1 = sqrt((pts[1].getxValue() - pts[0].getxValue()) * (pts[1].getxValue() - pts[0].getxValue())
        + (pts[1].getyValue() - pts[0].getyValue()) * (pts[1].getyValue() - pts[0].getyValue()));
    side2 = sqrt((pts[2].getxValue() - pts[1].getxValue()) * (pts[2].getxValue() - pts[1].getxValue())
        + (pts[2].getyValue() - pts[1].getyValue()) * (pts[2].getyValue() - pts[1].getyValue()));
    side3 = sqrt((pts[3].getxValue() - pts[2].getxValue()) * (pts[3].getxValue() - pts[2].getxValue())
        + (pts[3].getyValue() - pts[2].getyValue()) * (pts[3].getyValue() - pts[2].getyValue()));
    side4 = sqrt((pts[0].getxValue() - pts[3].getxValue()) * (pts[0].getxValue() - pts[3].getxValue())
        + (pts[0].getyValue() - pts[3].getyValue()) * (pts[0].getyValue() - pts[3].getyValue()));
    return ((side1 == side2) && (side1 == side3) && (side1 == side4));
}

void Rectangle::printSpecial() const
{
    float length = sqrt((pts[1].getxValue() - pts[0].getxValue()) * (pts[1].getxValue() - pts[0].getxValue())
        + (pts[1].getyValue() - pts[0].getyValue()) * (pts[1].getyValue() - pts[0].getyValue()));
    //if (isSpecial())
    cout << "Square with side length " << length << endl; 
}

float Rectangle::area() const
{
    float length, width;
    length = sqrt((pts[1].getxValue() - pts[0].getxValue()) * (pts[1].getxValue() - pts[0].getxValue())
        + (pts[1].getyValue() - pts[0].getyValue()) * (pts[1].getyValue() - pts[0].getyValue()));
    width = sqrt((pts[2].getxValue() - pts[1].getxValue()) * (pts[2].getxValue() - pts[1].getxValue())
        + (pts[2].getyValue() - pts[1].getyValue()) * (pts[2].getyValue() - pts[1].getyValue()));
    return length * width;
}

Rectangle::~Rectangle() // DID NOT DO THIS CORRECTLY!
{
    numOfPoints = 0;
    if (pts) {
        pts = nullptr;
        delete[] pts;
    }
}
