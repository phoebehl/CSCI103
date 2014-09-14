#include <cstring>
#include <string.h>
#include <iostream>
#include <cmath>

#include "highinterest.h"
#include "bankaccount.h"

using namespace std;

HighInterest::HighInterest(string owner, double strtBalance)
{
	_name = owner;
	_balance = strtBalance;

}

string HighInterest::getName(int acct)
{
	return _name;
}

int HighInterest::getAcctNum(int index)
{
	return _acctNum;
}

double HighInterest::getBalance(int acct)
{
	return _balance;
}

void HighInterest::deposit(int acct, double amount)
{
	_balance = _balance+amount;
}

void HighInterest::monthEnd()
{
	_balance = ((_balance)*1.02);
}