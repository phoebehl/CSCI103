#ifndef HIGHINTEREST_H
#define HIGHINTEREST_H

#include <cstring>
#include <string.h>

#include "bankaccount.h"

using namespace std;

class HighInterest: public BankAccount
{
public: 
	HighInterest(string owner, double strtBalance);
	string getName(int acct);
	int getAcctNum(int index);
	double getBalance(int acct);
	void deposit(int acct, double amount);
	void withdraw(int acct, double amount);
	void monthEnd();


private:
	int _acctNum;
	string _name;
	double _balance;


};

#endif