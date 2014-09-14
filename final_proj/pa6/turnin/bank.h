#ifndef BANK_H
#define BANK_H

#include <string.h>
#include "player.h"
#include "space.h"
#include "action.h"

class Bank : public Action
{
public:
	Bank();
	void executeAction(int space, int stars, int i, Player* player, Space* spaces);

private:
	int _Stars;
};

#endif