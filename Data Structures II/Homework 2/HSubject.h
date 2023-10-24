#pragma once
#include <iostream>
#include <string>
#include <list>
using namespace std;
#include "HashTable.h"

const int MAX = 1000;



class HSubject :public HashTable<list<string>, string>
{
	//private:
	int key(string s) { return (int)s[0] + (int)s[1] + (int)s[s.length() - 1]; }

public:
	HSubject(int n) :HashTable <list<string>, string>(n) {}
	int h1(string s) { return key(s) % size; }
	int h2(string s) { return (key(s) % (size - 1) + 1) % size; }
	void printS(string ky); // prints all the string in the data list
	void printN(string ky, int N); // a function that receives a topic and a number N and prints the first N discussions on the corresponding topic
	void print(); // a function that prints all the entries in the table
	void startNewTable(); // A function that resets the table to be an empty table.
	void addSubjectAndTitle(string s, string t); // insert subject and string into the table
};
