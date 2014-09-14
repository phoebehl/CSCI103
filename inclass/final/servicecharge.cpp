#include <cstring>
#include <iostream>
#include <cmath>
#include <string.h>

#include "servicecharge.h"
#include "bankaccount.h"

using namespace std;

ServiceCharge::ServiceCharge(string owner, double strtBalance)
{

}

string ServiceCharge::getName(int acct)
{
	return _name;
}

int ServiceCharge::getAcctNum(int index)
{
	return _acctNum;
}

double ServiceCharge::getBalance(int acct)
{
	return _balance;
}

void ServiceCharge::deposit(int acct, double amount)
{
	_balance = _balance+amount;
}

void ServiceCharge::withdraw(int acct, double amount)
{
	_balance = _balance-amount;
}

void ServiceCharge::writeCheck(double amount, int times)
{
	if (times < 5)
	{
		_balance = _balance-amount;
	}

	else
	{
		_balance = _balance-(amount+1);
	}

	
}

void ServiceCharge::monthEnd()
{
	_balance = ((_balance)*1.01);
}