#pragma once
#include <iostream>
using namespace std;
template <class T>

class Vector {
protected:
	T* data; 
	int size;
	int capacity;
public:
	Vector(int cap);
	Vector(const Vector<T>& v);
	~Vector();
	T& operator[](int index);
	Vector<T>& operator=(const Vector<T>& vec);
	int getSize() const; 
	int getCapacity() const;
	void insert(T value);
	void clear(); 
	T delLast();
	bool isEmpty() const;
};

template<class T>
inline Vector<T>::Vector(int cap)
{
	capacity = cap;
	size = 0;
	data = new T[capacity];
	if (data == nullptr)
		throw "memory allocation problem";
}

template<class T>
inline Vector<T>::Vector(const Vector<T>& vec)
{
	capacity = vec.capacity;
	size = vec.size;
	data = new T[capacity];
	if (data == nullptr)
		throw "memory allocation problem";
	for (int index = 0; index < size; index++)
		data[index] = vec.data[index];
}

template<class T>
inline Vector<T>::~Vector()
{
	if (data != nullptr)
	{
		delete[] data;
		data = nullptr;
	}

}

template<class T>
inline T& Vector<T>::operator[](int index)
{
	if (index < 0 || index >= size)
		throw "vector overflow";
	return data[index];
}

template<class T>
inline int Vector<T>::getSize() const
{
	return size;
}

template<class T>
inline int Vector<T>::getCapacity() const
{
	return capacity;
}

template<class T>
inline void Vector<T>::insert(T value) 
{
	if (size >= capacity)
		throw "the vector is full";
	data[size] = value; 
	size++;
}

template<class T>
inline void Vector<T>::clear()
{
	size = 0; 
}

template<class T>
inline T Vector<T>::delLast() 
{
	if (size < 0)
		throw "the vector is empty";
	T temp = data[size - 1];
	size--;
	return temp;
}

template<class T>
inline bool Vector<T>::isEmpty() const
{
	return (size == 0);
}

 template<class T>
inline Vector<T>& Vector<T>::operator =(const Vector<T>& vec)
{
	size = vec.size;
	capacity = vec.capacity;
	if (data)
		delete[] data;
	data = new T[capacity];
	if (data == nullptr)
		throw "memory allocation problem";
	for (int index = 0; index < size; index++)
		data[index] = vec.data[index];
	return *this;
}
