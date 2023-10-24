#include <iostream>
#include "Clock.h"
#include "Account.h"
#include <string>
using namespace std;

enum ACTION {
	STOP,
	BALANCE,
	DEPOSIT,
	WITHDRAW,
	SUM_DEPOSIT,
	SUM_WITHDRAW
};
ACTION menu() {
	cout << "enter 1 to get account balance" << endl;
	cout << "enter 2 to deposit money" << endl;
	cout << "enter 3 to withdraw money" << endl;
	cout << "enter 4 to see the sum of all deposits" << endl;
	cout << "enter 5 to see the sum of all withdrawals" << endl;
	cout << "enter 0 to stop" << endl;
	cout << endl; //ADDED THIS
	int x;
	cin >> x;
	return (ACTION)x;
}
int findAccount(Account* bank, int size) {
	int number, code;
	cout << "please enter account number:\n";
	cin >> number;
	int i = 0;
	while (i < size && bank[i].getAccountNumber() != number)
		i++;
	if (i >= size)
		throw "ERROR: no such account number\n";
	cout << "please enter the code:\n";
	cin >> code;
	if (bank[i].getCode() == code)
		return i;
	throw "ERROR: wrong code!\n";
}
void printTransaction(Account a, ACTION ac, Clock& c) {
	cout << c << "\t" << endl; // maybe put try and catch over here **added endl here
	switch (ac) {
	case BALANCE: cout << "account #: " << a.getAccountNumber() << "\t" << endl; //**added endl here
		cout << "balance: " << a.getBalance() << endl;
		break;
	case DEPOSIT: // need to deposit??!!****************************************
	case WITHDRAW: cout << "account #: " << a.getAccountNumber() << "\t";
		cout << "new balance: " << a.getBalance() << endl;
		break;
	case SUM_DEPOSIT:
		cout << "sum of all deposits: " << a.getSumDeposit() << endl;
		break;
	case SUM_WITHDRAW:
		cout << "sum of all withdrawals: " << a.getSumWithdraw() << endl;
		break;
	}
}
void getBalance(Account* bank, int size, Clock& c) {
	int i = findAccount(bank, size);
	c += 20; // adds 20 seconds to the elapsed time
	printTransaction(bank[i], BALANCE, c);
}
void cashDeposit(Account* bank, int size, Clock& c) {
	int i = findAccount(bank, size);
	float amount;
	cout << "enter the amount of the deposit:\n ";
	cin >> amount;
	bank[i].deposit(amount);
	c += 30;
	printTransaction(bank[i], DEPOSIT, c);
}
void cashWithdraw(Account* bank, int size, Clock& c) {
	int i = findAccount(bank, size);
	float amount;
	cout << "enter the amount of money to withdraw: " << endl; // took away \n and added endl
	cin >> amount; 
	bank[i].withdraw(amount); 
	c += 50;
	printTransaction(bank[i], WITHDRAW, c);
}
void checkAccount(Account bank[], int i) {
	for (int j = 0; j < i; j++)
		if (bank[i].getAccountNumber() == bank[j].getAccountNumber())
			throw "ERROR: account number must be unique!";
}
int main() {
	const int SIZE = 2; // CHANGE THIS BACK TO 10!!
	Clock c(8, 0, 0); // do i need to use a try-catch block?
	Account bank[SIZE];
	cout << "enter account number, code and email for " << SIZE << " accounts:\n"; // took away the added endl
	for (int i = 0; i < SIZE; i++) {
		try {
			cin >> bank[i];
			checkAccount(bank, i); // should I make this a new try block or keep it attached to the one above?
		}
		catch (const char* msg) {
			cout << c << '\t' << msg << endl;
			i--;
		}
	}
	ACTION ac = menu();
	while (ac) {
		switch (ac) {
		case BALANCE: 
			try {
				getBalance(bank, SIZE, c);
			}
			catch (const char* msg) {
				cout << c << endl << msg << endl;
			}
			break;
		case WITHDRAW:
			try {
				cashWithdraw(bank, SIZE, c);
			}
			catch (const char* msg) {
				cout << c << endl << msg << endl;
			}
			break;
		case DEPOSIT:
			try {
				cashDeposit(bank, SIZE, c);
			}
			catch (const char* msg) {
				cout << c << msg << endl;
			}
			break;
		case SUM_DEPOSIT:c += 60; // adds 1 minute to the amount of time elapsed
			printTransaction(bank[0], SUM_DEPOSIT, c);
			break;
		case SUM_WITHDRAW:c += 60; // adds 1 minute to the amount of time elapsed
			printTransaction(bank[0], SUM_WITHDRAW, c);
		}

		ac = menu();
	}

	return 0;
}
/*
enter account number, code and email for 2 accounts:
123 4444 me@gmail.com
234 5555 you@walla.co.il
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all deposits
enter 5 to see the sum of all withdrawals
enter 0 to stop

2
please enter account number:
234
please enter the code:
5555
enter the amount of the deposit:
 5000
08:00:30
account #: 234  new balance: 5000
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all deposits
enter 5 to see the sum of all withdrawals
enter 0 to stop

3
please enter account number:
234
please enter the code:
5555
enter the amount of money to withdraw:
1000
08:01:20
account #: 234  new balance: 4000
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all deposits
enter 5 to see the sum of all withdrawals
enter 0 to stop

1
please enter account number:
234
please enter the code:
5555
08:01:40
account #: 234
balance: 4000
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all deposits
enter 5 to see the sum of all withdrawals
enter 0 to stop
*/