#pragma once
#include <iostream>
using namespace std;

class Account
{
private:
	int accountNumber;
	int code;
	float balance;
	string email;
	static float sumWithdraw;
	static float sumDeposit;
public:
	Account(); //empty ctor
	Account(int accountNumber, int code, float balance, string email); //regular ctor
	void setAccountNumber(int an);
	int getAccountNumber();
	void setCode(int code);
	int getCode();
	void setBalance(float bal);
	float getBalance();
	void setEmail(string em);
	string getEmail();
	friend istream& operator>>(istream& is, Account& acc) 
		{
			int accountNumber, code;
			float balance = 0;
			string email;
			is >> accountNumber >> code >> email;
			acc.setAccountNumber(accountNumber);
			acc.setCode(code);
			acc.setBalance(0);
			acc.setEmail(email);
			return is;
	}
	void withdraw(int nis); //does it need to be a friend?
	void deposit(int nis);  //does it need to be a friend?
	/*friend*/ float getSumWithdraw(); // – method that returns the sum of all bank withdrawals
	/*friend*/ float getSumDeposit(); //method that returns the sum of all check deposits
};

