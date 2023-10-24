#include "Rational.h"
#include <iostream>
using namespace std;

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
	if (denominator == 1) cout << numerator;
	else cout << numerator << "/" << denominator;
}

void Rational::reduction()
{
	for (int i = numerator * denominator; i > 1; i--) {
		// this divides the numerator and denominator by their greatest factor
		if (numerator % i == 0 && denominator % i == 0) {
			numerator = numerator / i;
			denominator = denominator / i;
		}
	}
	if (numerator == 0) denominator = 1; // don't know if i need this?
}

Rational::Rational()
{
	numerator = 1;
	denominator = 1;
}

Rational::Rational(int num, int den)
{
	// let's say you get the wrong value for denominator!
	numerator = num;
	denominator = den;
}

Rational::Rational(const Rational& other)
{
	numerator = other.numerator;
	denominator = other.denominator;
}

Rational Rational::operator+(const Rational& rat) const
{
	Rational finalRat;
	if (rat.denominator == denominator) {
		// if the denominators are the same then add the numerators and keep the denominator
		finalRat.setNumerator(rat.numerator + numerator);
		finalRat.setDenominator(denominator);
		finalRat.reduction(); // reduce this rational
	}
	else {
		// if the denominators are different then multiply each numerator by the other's denominator, and multiply the denominators together
		finalRat.setNumerator(rat.numerator * denominator + numerator * rat.denominator);
		finalRat.setDenominator(rat.denominator * denominator);
		finalRat.reduction();
	}
	return finalRat;
}

Rational Rational::operator-(const Rational& rat) const
{
	Rational finalRat;
	if (rat.denominator == denominator) {
		// if the denominators are the same then subtract the numerators and keep the denominator
		finalRat.setNumerator(numerator - rat.numerator);
		finalRat.setDenominator(denominator);
		finalRat.reduction(); // reduce this rational
	}
	else {
		// if the denominators are different then multiply each numerator by the other's denominator, and multiply the denominators together
		finalRat.setNumerator(numerator * rat.denominator - rat.numerator * denominator);
		finalRat.setDenominator(rat.denominator * denominator);
		finalRat.reduction();
	}
	return finalRat;
}

Rational Rational::operator*(Rational rat) const
{
	Rational r;
	r.numerator = numerator * rat.numerator;
	r.denominator = denominator * rat.denominator;
	r.reduction();
	return r;
}

Rational Rational::operator/(Rational rat) const
{
	Rational r;
	int temp;
	temp = rat.numerator;
	rat.numerator = rat.denominator;
	rat.denominator = temp;
	r.numerator = numerator * rat.numerator;
	r.denominator = denominator * rat.denominator;
	r.reduction();
	return r;
}

Rational Rational::operator++()
{
	numerator += denominator;
	return *this;
}

Rational Rational::operator++(int u)
{
	Rational temp= *this;
	numerator += denominator;
	return temp;
}

Rational Rational::operator--()
{
	numerator -= denominator;
	return *this;
}

Rational Rational::operator--(int u)
{
	Rational temp = *this;
	numerator -= denominator;
	return *this;
}

bool Rational::operator==(const Rational& rat) const
{
	Rational temp1 = *this;
	Rational temp2 = rat;
	temp1.reduction();
	temp2.reduction();
	return (temp1.numerator == temp2.numerator && temp1.denominator == temp2.denominator);
}

bool Rational::operator!=(const Rational& rat) const
{
	return !(*this == rat);
}

bool Rational::operator<(const Rational& rat) const
{
	//MAY HAVE TO ACCOUNT IF IT IS AN IMPROPER FRACTION AND IF THE NUM > DEN!!! IF PROBLEMS DO ARISE!!
	
	Rational temp1 = *this;
	Rational temp2 = rat;
	temp1.reduction();
	temp2.reduction(); 
	if (denominator == rat.denominator) {
		return (numerator < rat.numerator);
	}
	else if (numerator == rat.numerator) {
		return (denominator > rat.denominator);
	}
	else {
		int test1, test2;
		test1 = numerator * rat.denominator;
		test2 = denominator * rat.numerator;
		return (test1 < test2);
	}
}

bool Rational::operator>(const Rational& rat) const
{
	//MAY HAVE TO ACCOUNT IF IT IS AN IMPROPER FRACTION AND IF THE NUM > DEN!!! IF PROBLEMS DO ARISE!!
	Rational temp1 = *this;
	Rational temp2 = rat;
	temp1.reduction();
	temp2.reduction();
	if (denominator == rat.denominator) {
		return (numerator > rat.numerator);
	}
	else if (numerator == rat.numerator) {
		return (denominator < rat.denominator);
	}
	else {
		int test1, test2;
		test1 = numerator * rat.denominator;
		test2 = denominator * rat.numerator;
		return (test1 > test2);
	}
}

bool Rational::operator<=(const Rational& rat) const
{
	//MAY HAVE TO ACCOUNT IF IT IS AN IMPROPER FRACTION AND IF THE NUM > DEN!!! IF PROBLEMS DO ARISE!!
	return !(*this > rat);
	/*Rational temp1 = *this;
	Rational temp2 = rat;
	temp1.reduction();
	temp2.reduction();
	if (denominator == rat.denominator) {
		return (numerator <= rat.numerator);
	}
	else if (numerator == rat.numerator) {
		return (denominator <= rat.denominator);
	}
	else {
		return (numerator >= rat.numerator && denominator <= rat.denominator);
	}*/
}

bool Rational::operator>=(const Rational& rat) const
{
	//MAY HAVE TO ACCOUNT IF IT IS AN IMPROPER FRACTION AND IF THE NUM > DEN!!! IF PROBLEMS DO ARISE!!
	return !(*this < rat);
	/*Rational temp1 = *this;
	Rational temp2 = rat;
	temp1.reduction();
	temp2.reduction();
	if (denominator == rat.denominator) {
		return (numerator >= rat.numerator);
	}
	else if (numerator == rat.numerator) {
		return (denominator <= rat.denominator);
	}
	else {
		return (numerator >= rat.numerator && denominator <= rat.denominator);
	}*/
}

