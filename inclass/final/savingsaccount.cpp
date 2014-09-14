#include <cstring>
#include <iostream>
#include <cmath>
#include <string.h>

#include "savingsaccount.h"
#include "bankaccount.h"

using namespace std;

SavingsAccount::SavingsAccount(string owner, double strtBalance)
{
	_name = owner;
	_balance = strtBalance;

}

string SavingsAccount::getName(int acct)
{
	return _name;
}

int SavingsAccount::getAcctNum(int index)
{
	return _acctNum;
}

double SavingsAccount::getBalance(int acct)
{
	return _balance;
}

void SavingsAccount::deposit(int acct, double amount)
{
	_balance = _balance+amount;
}

void SavingsAccount::withdraw(int acct, double amount)
{
	_balance = _balance-amount;
}

void SavingsAccount::monthEnd()
{
	_balance = ((_balance)*1.01);
}