/*
Adina Lev
566021464
Exercise 2 Question 2
*/

#pragma once
class Vector
{
private:
	int* data; // creates a dynamid array of type int
	int size;
	int capacity;
public:
	Vector(); // default constructor
	Vector(int cap); // regular constructor
	//Vector(int cap, int s);
	Vector(const Vector& other); //copy constructor
	~Vector(); // destructor
	int getCapacity(); // getter for capacity
	int getSize(); // getter for size
	void print(); // print method
	void assign(Vector vec); // assign a vector to another
	bool isEqual(Vector vec); // method to test if two vectors are equal
	int& at(int index); // receives an index to assign and retrieve a value in the vector
	int scalmul(Vector vec); // calculates the dot product
	Vector strnewcat(Vector vec); // method for concantenation
	void clear(); // method to clear the contents of a vector
	void delLast(); // method to delete the last entry in a vector
	void insert(int val); // method to insert a value into the next available location in an array
};



