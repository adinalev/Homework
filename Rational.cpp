/*
Adina Lev
566021464
Exercise 1 Question 1
This program deals with rational numbers by comparing, adding, and reducing them.
*/

#include "Rational.h"
using namespace std;

void Rational::reduction()
{
	for (int i = numerator * denominator; i > 1; i--) {
		// this divides the numerator and denominator by their greatest factor
		if (numerator % i == 0 && denominator % i == 0) {
			numerator = numerator / i;
			denominator = denominator / i;
		}
	}
	if (numerator == 0) denominator = 1;
}

void Rational::setDenominator(int den)
{
	if (den == 0) denominator = 1; // if a zero is inputted for the denominator, it is changed to a 1
	else if (den < 0) {
		denominator = den * (-1);
		numerator = numerator * (-1); // if the denominator is negative, the minus sign gets moved to the numerator
	}
	else if (den > 0) denominator = den;
}

int Rational::getDenominator()
{
	return denominator;
}

void Rational::setNumerator(int num)
{
	numerator = num;
}

int Rational::getNumerator()
{
	return numerator;
}

void Rational::print()
{
	cout << numerator << "/" << denominator;
}

Rational Rational::add(Rational rat)
{
	Rational finalRat;
	if (rat.getDenominator() == denominator) {
		// if the denominators are the same then add the numerators and keep the denominator
		finalRat.setNumerator(rat.getNumerator() + numerator);
		finalRat.setDenominator(denominator);
		finalRat.reduction(); // reduce this rational
	}
	else {
		// if the denominators are different then multiply each numerator by the other's denominator, and multiply the denominators together
		finalRat.setNumerator(rat.getNumerator() * denominator + numerator * rat.getDenominator());
		finalRat.setDenominator(rat.getDenominator() * denominator);
		finalRat.reduction();
	}
	return finalRat;
}


bool Rational::equal(Rational rat)
{
	// to test if the rationals are equal to each other
	int num = rat.getNumerator();
	int den = rat.getDenominator();
	if (num == numerator && den == denominator) return true;
	else return false;
}


