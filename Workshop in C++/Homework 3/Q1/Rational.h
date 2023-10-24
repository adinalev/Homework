#pragma once
class Rational
{
private:
	int numerator;
	int denominator;
public:
	void setDenominator(int den);
	int getDenominator();
	void setNumerator(int num);
	int getNumerator();
	void print();
	void reduction(); // to reduce the rationals
	Rational(); // empty constructor
	Rational(int num, int den); // regular constructor
	Rational(const Rational& other); // copy constructor
	Rational operator+(const Rational& rat) const; // + operator
	Rational operator-(const Rational& rat) const; // - operator
	Rational operator*(Rational rat) const; // * operator -- DO I NEED TO DO THE SPECIAL TITLE LINE HERE?
	Rational operator/(Rational rat) const; // do I need to do all the const and & here?
	Rational operator++(); // post increment
	Rational operator++(int u); // pre increment
	Rational operator--(); // post decrement
	Rational operator--(int u); // pre decrement
	bool operator==(const Rational& rat) const; // "is equal to" == operator
	bool operator!=(const Rational& rat) const; // "is  not equal to" != operator
	bool operator<(const Rational& rat) const; // "is less than" < operator
	bool operator>(const Rational& rat) const; // "is greater than" > operator
	bool operator<=(const Rational& rat) const; // "is less than or equal to" <= operator
	bool operator>=(const Rational& rat) const; // "is greater than or equal to" >= operator
};

