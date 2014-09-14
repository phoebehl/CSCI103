#ifndef MONEYACTION_H
#define MONEYACTION_H

#include <string.h>
#include "action.h"
#include "player.h"

using namespace std;

class moneyAction : public Action
{
public:
	moneyAction(string title);
	void pay_money(Player p, int amount);
	void executeAction();

private:
	int _money;
};

#endif