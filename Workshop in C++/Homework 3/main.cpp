/*
Adina Lev
566021464
Exercise 3 Question 3
This code deals with strings. It compares the strings using lexicographic order, 
inserts a string into a different string, and inserts a new character inside an existing string.
*/
#include "MyString.h"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	char* a;
	char* b;
	char* c;
	a = new char[100];
	b = new char[100];
	char newChar;
	int num, lengthB, lengthA;
	cout << "Enter two strings and a number " << endl;
	cin >> a >> b >> num; // how to read these in?
	MyString myA(a);
	MyString myB(b);
	if (myA > myB) cout << "a>b" << endl;
	else if (myA == myB) cout << "a=b" << endl;
	else if (myA < myB) cout << "a<b" << endl;
	MyString myC;
	myC = myB.insert(num, myA.getString()); // may need to change the inserts
	c = myC.getString();
	for (int i = 0; i < myC.getLength(); i++) {
		cout << c[i]; // how do I print out from the string?
	}
	cout << endl;
	cout << "Enter a character and a number " << endl;
	cin >> newChar >> num;
	myC[num] = newChar;
	for (int i = 0; i < myC.getLength(); i++) {
		cout << myC[i];
	}
	return 0;
}
/*
Enter two strings and a number
World
Hello
5
a>b
move ctor
move assign
HelloWorld
Enter a character and a number
!
5
Hello!orld

Enter two strings and a number
Hello
Hello
2
a=b
move ctor
move assign
HeHellollo
Enter a character and a number
h
2
Hehellollo
*/
