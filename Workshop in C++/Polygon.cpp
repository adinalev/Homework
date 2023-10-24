#include "Polygon.h"
#include <cstddef>
#include <iostream>
using namespace std;

Point* Polygon::getVertices()
// getter function for the dynamic array of vertices
{
    Point* temp = new Point[numVertices];
    for (int i = 0; i < numVertices; i++) {
        temp[i] = vertices[i];
    }
    return temp;
}

int Polygon::getNumVertices()
// getter function for the amount of vertices
{
    return numVertices;
}

Polygon::Polygon()
// empty constructor
{
    vertices = nullptr;
    numVertices = 0;
    cout << "in empty constructor" << endl;
}

Polygon::Polygon(int numv)
// regular constructor
{
    numVertices = numv;
    vertices = new Point[numVertices];
    cout << "in one parameter constructor" << endl;
}

Polygon::Polygon(const Polygon& other)
// copy constructor
{
    numVertices = other.numVertices;
    vertices = new Point[other.numVertices];
    for (int i = 0; i < numVertices; i++) {
        vertices[i] = other.vertices[i];
    }
    cout << "in copy constructor" << endl;

}

Polygon::~Polygon()
// destructor
{
    if (vertices) delete[] vertices;
    vertices = NULL;
    cout << "in destructor" << endl;
}

void Polygon::addPoint(int index, Point vertex)
// method to add a Point into the dynamic array of vertices into the desired index
{
    vertices[index] = vertex;
}

float Polygon::perimeter()
// method to caluclator and return the perimeter of a polygon
{
    float total = 0;
    for (int i = 1; i < numVertices; i++) {
        total += vertices[i-1].distance(vertices[i]); 
    }
    total += vertices[0].distance(vertices[numVertices - 1]);
    return total;
}

bool Polygon::equal(Polygon p) {
// method to test if two polygons are equal to each other
    bool equal = false;
    bool found = false;
    //if they don't have the same amount of sides, return false
    if(numVertices != p.numVertices)
        return equal;
    //loop through each point in one polygon and compare to each point in the other polygon
    for(int i = 0; i < numVertices; i++){
        for(int j = 0; j < numVertices; j++){
            //if found corresponding point, set found to true and break from inner loop
            if(vertices[i].getxValue()==p.vertices[j].getxValue() && vertices[i].getyValue()==p.vertices[j].getyValue()) {
                found = true;
                break;
            }
        }
        //if found is false, then the two polygons can't be equal and return
        if (!found) {
            return equal;
        }
        //if it is true, then reset and keep checking
        else {
            found = false;
        }
    }
    //if made it this far then they must be equal and return
    equal = true;
    return equal;
}