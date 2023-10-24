#include "Account.h"
#include <cstring>
#include <string>
#include <iostream>
typedef basic_string<char> string;
using namespace std;

float Account::sumWithdraw = 0;
float Account::sumDeposit = 0;

Account::Account()
{
	accountNumber = 0;
	code = 0;
	balance = 0;
	email = " "; // set the email to an emtpy string
}

Account::Account(int accountNumber, int code, float balance, string email)
{
	if (code < 1000 || code > 9999) { // if code is not 4 digits
		throw "ERROR: code must be of 4 digits!";
	}
	if (email.find("@") == string::npos) throw "ERROR: email must contain @!";
	if (email.find(".com") == string::npos && email.find(".co.il") == string::npos) throw "ERROR: email must end at .com or .co.il!";
	this->accountNumber = accountNumber;
	this->code = code;
	this->balance = balance;
	this->email = email;
}

void Account::setAccountNumber(int an)
//account number and password code cannot be reset. Values for these fields can only be assigned through the constructor or via input
{
	accountNumber = an;
}

int Account::getAccountNumber()
{
	return accountNumber;
}

void Account::setCode(int code)
// account number and password code cannot be reset.Values for these fields can only be assigned through the constructor or via input
{
	if (code < 1000 || code > 9999) { // if code is not 4 digits
		throw "ERROR: code must be of 4 digits!";
	}
	this->code = code;
}

int Account::getCode()
{
	return code;
}

void Account::setBalance(float bal)
{
	balance = bal;
}

float Account::getBalance()
{
	return balance;
}

void Account::setEmail(string em)
{
	if (em.find("@") == string::npos)
	{

		throw "ERROR: email must contain @!";
	}
	if (em.find(".com") == string::npos && em.find(".co.il") == string::npos) {
		throw "ERROR: email must end at .com or .co.il!";
	}
	email = em;
}

string Account::getEmail()
{
	return email;
}

void Account::withdraw(int nis)
{
	if (balance - nis < -6000) { // is this what overdraft is? MADE IT -6000
		throw "ERROR: cannot have less than - 6000 NIS!";
	}
	if (nis > 2500) {
		throw "ERROR: cannot withdraw more than 2500 NIS!";
	}
	balance -= nis;
	sumWithdraw += nis;
}

void Account::deposit(int nis)
{
	if (nis > 10000) {
		throw "ERROR: cannot deposit more than 10000 NIS!";
	}
	balance += nis;
	sumDeposit += nis;
}

float Account::getSumWithdraw()
{
	return sumWithdraw;
}

float Account::getSumDeposit()
{
	return sumDeposit;
}

istream& operator>>(istream& is, Account acc) // change all the gets to dots
{
	int accountNumber, code;
	float balance=0;
	string email;
	is >> accountNumber >> code >> email;
	acc.setAccountNumber(accountNumber);
	acc.setCode(code);
	acc.setBalance(0);
	acc.setEmail(email);
	/*Account temp(accountNumber, code, balance, email);
	acc.setAccountNumber(temp.getAccountNumber());
	acc.setCode(temp.getCode());
	acc.setBalance(0);
	acc.setEmail(temp.getEmail());*/
	return is;
	//try {
	//	
	//}
	//catch (const char* c) {
	//	cout << "ERROR: code must be of 4 digits!" << endl;
	//	// keep everything at their default values
	//}
	//try {
	//	temp.setEmail(email);
	//}
	//catch (const char* c) {
	//	// if the email does not have @ then return first error
	//	// if the email does not end properly then return second error
	//}
}