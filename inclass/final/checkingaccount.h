#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include <string>

#include "bankaccount.h"

class CheckingAccount: public BankAccount
{
public: 
	void virtual writeCheck(double amount, int times) = 0;
	


private:


};

#endif