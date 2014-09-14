#ifndef NOSERVICECHARGE_H
#define NOSERVICECHARGE_H

#include <string.h>
#include <cstring>

#include "bankaccount.h"

using namespace std;

class NoServiceCharge: public BankAccount
{
public: 
	NoServiceCharge(string owner, double strtBalance);
	string getName(int acct);
	int getAcctNum(int index);
	double getBalance(int acct);
	void deposit(int acct, double amount);
	void withdraw(int acct, double amount);
	void writeCheck(double amount, int times);
	void monthEnd();


private:
	int _acctNum;
	string _name;
	double _balance;


};

#endif