#include <cstring>
#include <iostream>
#include <cmath>
#include <string.h>

#include "noservicecharge.h"
#include "bankaccount.h"

using namespace std;

NoServiceCharge::NoServiceCharge(string owner, double strtBalance)
{
	_name = owner;
	_balance = strtBalance;

}

string NoServiceCharge::getName(int acct)
{
	return _name;
}

int NoServiceCharge::getAcctNum(int index)
{
	return _acctNum;
}

double NoServiceCharge::getBalance(int acct)
{
	return _balance;
}

void NoServiceCharge::deposit(int acct, double amount)
{
	_balance = _balance+amount;
}

void NoServiceCharge::withdraw(int acct, double amount)
{
	_balance = _balance-amount;
}

void NoServiceCharge::writeCheck(double amount, int times)
{
	_balance = _balance-amount;

	
}

void NoServiceCharge::monthEnd()
{
	_balance = ((_balance)*1.01);
}