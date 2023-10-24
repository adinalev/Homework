#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class MyString
{
private:
	int len = 0;
	char* str;
	void setString(const char* s);
public:
	void setLength(int n);
	int getLength();
	MyString();//explicit empty constructor
	MyString(const char* s); //constructor
	MyString(const MyString& ms); //copy constructor
	MyString(MyString&& ms); // move constructor
	~MyString(); //destructor

	char* getString() const;

	MyString& operator=(const MyString& ms); //assignment operator
	MyString& operator=(MyString&& ms); //move assignment operator

	bool operator==(const MyString& ms) const;
	MyString  operator+(const MyString& ms) const;
	MyString  operator* (const int) const;

	void print() const;

	bool operator<(const MyString& ms) const;
	bool operator>(const MyString& ms) const;
	bool operator<=(const MyString& ms) const;
	bool operator>=(const MyString& ms) const;
	bool operator!=(const MyString& ms) const;
	char& operator[](int i);
	MyString insert(int index, const char* str);
};


