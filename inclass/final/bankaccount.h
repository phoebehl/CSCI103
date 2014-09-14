#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <cstring>
#include <string.h>

using namespace std;

class BankAccount
{
public: 
	string virtual getName(int acct) = 0;
	int virtual getAcctNum(int index) = 0;
	double virtual getBalance(int acct) = 0;
	void virtual deposit(int acct, double amount) = 0;
	void virtual withdraw(int acct, double amount) = 0;

private:
	


};

#endif