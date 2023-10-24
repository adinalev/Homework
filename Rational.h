/*
Adina Lev
566021464
Exercise 1 Question 1
This program deals with rational numbers by comparing, adding, and reducing them.
*/

#pragma once 
#include <iostream>

class Rational
{
private:
	int numerator;
	int denominator;
	void reduction(); // to reduce the rationals
public:
	void setDenominator(int den);
	int getDenominator();
	void setNumerator(int num);
	int getNumerator();
	void print();
	Rational add(Rational rat); // to add the rationals
	bool equal(Rational rat); // to test equality
};

