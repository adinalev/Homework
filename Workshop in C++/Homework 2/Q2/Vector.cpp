#include "Vector.h"
#include <cstddef>
#include <cmath>
#include <iostream>
using namespace std;

Vector::Vector()
// default constructor
{
	size = 0;
	capacity = 2;
	data = new int[capacity];
	for (int i = 0; i < capacity; i++)
		data[i] = rand() % 100;
}

Vector::Vector(int cap)
//regular constructor
{
	size = 0;
	// find the closest power of 2 and set the capacity equal to that
	capacity = pow(2, ceil(log(cap) / log(2)));
	//build the array
	data = new int[capacity];
	for (int i = 0; i < capacity; i++)
		data[i] = rand() % 100;
}

//Vector::Vector(int cap, int s)
//{
//	size = s;
//	if (cap <= 0) capacity = 2;
//	// if the value it receives is a power of two, then capacity is set equal to that value
//	if (ceil(log2(cap)) == floor(log2(cap))) capacity = cap;
//	// if the value is not a power of two, then find the closest power of 2 and set the capacity equal to that
//	else capacity = pow(2, ceil(log(cap) / log(2)));
//	//build the array
//	data = new int[capacity];
//}

Vector::Vector(const Vector& other)
// copy constructor
{
	size = other.size;
	capacity = other.capacity;
	data = new int[other.capacity];
	for (int i = 0; i < size; i++) {
		data[i] = other.data[i];
	}
}

Vector::~Vector()
// destructor
{
	if (data) delete[] data;
	data = nullptr;
}

int Vector::getCapacity()
// getter for capacity
{
	return capacity;
}

int Vector::getSize()
//getter for size
{
	return size;
}

void Vector::print()
// method to print the capacity, size, and contents of the array
{
	cout << "capacity: " << capacity << " size: " << size << " values: ";
	for (int i = 0; i < size; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
}

void Vector::assign(Vector vec)
{
	capacity = vec.capacity;
	size = vec.size;
	Vector newVec(capacity);

	for (int i = 0; i < size; i++) {
		newVec.data[i] = vec.data[i];
	}
	data = newVec.data;
	newVec.data = nullptr;
	//delete[] newVec.data;

}
//void Vector::assign(Vector vec)
//// method to assing one vector to a different one
//{
//	vec.capacity = capacity;
//	vec.size = size;
//	int* temp = new int[capacity];
//	for (int i = 0; i < size; i++) {
//		temp[i] = data[i];
//	}
//	vec.data = temp;
//	temp = nullptr;
//	delete[] temp;
//}

bool Vector::isEqual(Vector vec)
// method to test if two vectors are equal
{
	bool equal = true;
	for (int i = 0; i < size; i++) {
		if (data[i] != vec.data[i]) equal = false;
	}
	if (size == vec.size) return equal;
	return equal;
}

int& Vector::at(int index)
// method that receives an index to assign and retrieve a value in the vector
{
	if (index >= capacity || index < 0) {
		// if the requested index is not within range then print ERROR and return the first element
		cout << "ERROR";
		return data[0];
	}
	return data[index];
}

int Vector::scalmul(Vector vec)
// method to calculator the dot product
{
	int sum = 0, product = 0;
	if (size != vec.size) {
		// cannot find the dot product of two arrays with do not have the same size
		cout << "ERROR";
		return -1;
	}
	// multiply the corresponding elements in the specified index together and add it to the sum.
	// repeat for every index
	for (int i = 0; i < size; i++) {
		product = data[i] * vec.data[i];
		sum += product;
		product = 0;
	}
	return sum;
}

void Vector::clear()
// the clear the vector
{
	delete[] data;
	size = 0;
	data = nullptr;
}

void Vector::delLast()
// to delete the last element of the vector
{
	if (size == 0 ) cout << "ERROR";
	//if the vector was empty, print ERROR
	data[size - 1] = 0;
	size -= 1;
	//delete the last element of the vector

}

void Vector::insert(int val)
// method to insert the value of the paramter in the next available location in the array
{
	if (size < capacity) {
		// if the size is less than the capacity, you can add the value to the existing array
		data[size] = val;
		size++;
	}
	else if (size == capacity) { //if size is equal to capacity
		// if the size and capacity are equal to each other, then you need to create an array larger by one element
		int newCapacity = 2 * capacity;
		size++; 
		Vector newVec(newCapacity);
		newVec.size = size;
		// create a temporary array
		for (int i = 0; i < size-1; i++) {
			// transfer the values of the original array into the temporary array
			newVec.data[i] = data[i];
		}
		newVec.data[size-1] = val;
		data = newVec.data;
		capacity = newCapacity;
		//data = newData; //NEED TO DELETE DATA BEFORE I DO THIS
		newVec.data = nullptr;
		delete[] newVec.data;
		// make the last element in the array equal to the value
	}
}

Vector Vector::strnewcat(Vector vec)
{
	int count = 0;//counting when the first array ends to save the index
	int newSize = vec.size + size;
	int newCapacity = pow(2, ceil(log(capacity + vec.capacity) / log(2)));
	//int* temp = new int[newCapacity];
	Vector newVec(newCapacity);
	for (int i = 0; i < size; i++)//going through the called vector
	{
		newVec.data[i] = data[i];//copying whats in the called vector into the temp vector
		count++;
	}
	for (int i = 0; i < vec.size; i++)//going through the recieved vecotr 
	{
		newVec.data[i + count] = vec.data[i];//copying whats in the recived vector into the temp vector
	}
	newVec.size = newSize;
	return newVec;

}
//Vector Vector::strnewcat(Vector vec)
//{
//	int newCapacity = pow(2, ceil(log(capacity + vec.capacity) / log(2)));
//	int *temp = new int[newCapacity];
//	Vector newVector(newCapacity);
//	for (int i = 0; i < size; i++) {
//		newVector.data[i] = data[i];
//	}
//	for (int i = 0; i < vec.size; i++) {
//		newVector.data[vec.capacity - size + i] = vec.data[i];
//	}
//	newVector.size = size + vec.size;
//	return newVector;
//
//}
//Vector Vector::strnewcat(Vector vec)
//// method for concantenation
//{	
//	int newCap = capacity + vec.getCapacity(), newSize = size + vec.getSize(), realCap = 0;
//	if (ceil(log2(newCap)) == floor(log2(newCap))) realCap = newCap;
//	else realCap = pow(2, ceil(log(newCap) / log(2)));
//	int* temp = new int[realCap];
//	for (int i = 0; i < capacity; i++) {
//		temp[i] = data[i];
//	}
//	for (int i = 0; i < vec.capacity; i++) {
//		temp[i+capacity] = vec.data[i];
//	}
//	Vector newVec(realCap);
//	newVec.size = size + vec.size;
//	//newVec.capacity = realCap;
//	for (int i = 0; i < newVec.size; i++) {
//		newVec.data[i] = temp[i];
//	}
//	// return the new vector
//	return newVec;
//}

//int* Vector::strnewcat(Vector vec) //Is this really type int or supposed to be type Vector?
//{
//	int newCap = capacity + vec.getCapacity(), newSize = size + vec.getSize(), realCap = 0;
//	if (ceil(log2(newCap)) == floor(log2(newCap))) realCap = newCap;
//	else realCap = pow(2, ceil(log(newCap) / log(2)));
//	int* temp = new int[realCap];
//	for (int i = 0; i < capacity; i++) {
//		temp[i] = data[i];
//	}
//	for (int i = capacity; i < realCap; i++) {
//		temp[i] = vec.data[i];
//	}
//	return temp;
//}
