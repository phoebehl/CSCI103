#include <iostream>
#include "moneyAction.h"
#include "action.h"
#include "player.h"

using namespace std;

moneyAction::moneyAction(string title) : Action(title)
{
	_money = 50;
}

void moneyAction::pay_money(Player p, int amount)
{
	p.give_money(amount);
	_money -= amount;
	cout << "I now have: " << _money << endl;

}

void moneyAction::executeAction()
{
	cout << "in moneyAction executeAction" << endl;
}

