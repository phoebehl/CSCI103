#include <iostream>
#include <cstring>
#include <string.h>
#include <vector>
#include <cmath>

#include "bankaccount.h"
#include "checkingaccount.h"
#include "servicecharge.h"
#include "noservicecharge.h"
#include "savingsaccount.h"
#include "highinterest.h"

using namespace std;

int main()
{
	vector <BankAccount*> allAccounts;
	string acctType;
	string owner;
	double strtBalance;

	for (int i = 0; i < 5; i++)
	{
		//Get initial data
		cout << "Please enter your name: ";
		cin >> owner;
		cout << endl;
		cout << "Please enter your starting balance: ";
		cin >> strtBalance;
		cout << endl;
		if (cin.fail())
		{
			cout << "Your starting balance was invalid. Please try again: "
			cin.clear();
			cin.ignore(10000, "/n");
			cin >> strtBalance;
		}

		cout << "Account creation menu: " << endl;
		cout << "a) Service Charge Checking" << endl << "b) No Service Charge Checking" << endl << "c) Savings" << endl << "d) High Interest Savings";
		cout << endl << "Enter an a, b, or c corresponding to the type of account you want to create: ";
		cin >> acctType;
		cout << endl;
		//Input error check
		while (acctType != "a" || acctType != "b" || acctType != "c" || acctType != "d")
		{
			cout << "Mmmm there was an error with what you entered. Please enter an a, b, or c corresponding to the type of account: ";
			cin >> acctType;
		}
		//Input okay
		if (acctType == "a")
		{
			cout << "You want to create a service charge checking account.";
			BankAccount* currentAcct = new ServiceCharge(owner, strtbalance);
			allAccounts.push_back();


		}

		else if (acctType == "b")
		{
			cout << "You want to create a no service charge checking account.";
			BankAccount* currentAcct  = new NoServiceCharge(owner, strtBalance);
			allAccounts.push_back();
		}

		else if (acctType == "c")
		{
			cout << "You want to create a savings account.";
			BankAccount* currentAcct  = new SavingsAccount(owner, strtBalance);
			allAccounts.push_back();
		}

		else if (acctType == "d")
		{
			cout << "You want to create a high interest savings account";
			BankAccount* currentAcct  = new HighInterest(owner, strtBalance);
			allAccounts.push_back();
		}
		
	}

	cout << "Options menu:" << endl;
	cout << "a) Display balance" << endl << "b) Deposit money" << endl;
	cout << "c) Withdraw money (savings)" << endl << "d) Write a check (checking)" << endl;
	cout << "e) Apply month end interest" << endl << "f) Quit program" << endl;

	
	


}