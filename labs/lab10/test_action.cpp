#include <iostream>
#include <string>
#include "action.h"
#include "moveAction.h"
#include "player.h"
#include "moneyAction.h"

using namespace std;

void executeAction(Action& a)
{
	a.executeAction();
}

int main()
{
	//Testing action
	Action square1;
	square1.print_name();

	string card;
	cout << "Enter the name of the action: ";
	cin >> card;
	Action sq(card);
	sq.print_name();

	//Testing moveAction
	moveAction action1(card);
	int val;
	cout << "Enter the amount: ";
	cin >> val;
	action1.get_amount(val);
	action1.set_amount();

	//Testing moneyAction
	Player other;
	moneyAction m1(card);
	int cash;
	cout << "Enter the amount to pay: ";
	cin >> cash;
	m1.pay_money(other, cash);

	cout <<"Calling executeAction using objects" << endl;
	sq.executeAction();
	m1.executeAction();
	action1.executeAction();

	cout << "Calling executeAction in main" << endl;
	executeAction(sq);
	executeAction(m1);
	executeAction(action1);

	Action* actions[9];
	for (int i = 0; i < 9; i = i+3)
	{
		actions[i] = new Action();
		actions[i+1] = new moneyAction();
		actions[i+2] = new moveAction();
	}

	for (int i = 0; i < 9; i++)
	{
		actions[i]->executeAction();
	}

	for (int i = 0; i < 9; i++)
	{
		delete actions[i];
	}


	return 0;

}