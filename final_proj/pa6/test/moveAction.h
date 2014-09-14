#ifndef MOVEACTION_H
#define MOVEACTION_H

#include <string.h>
#include "player.h"
#include "space.h"
#include "action.h"

using namespace std;

class MoveAction : public Action
{
public:
	MoveAction();
	void executeAction(int space, int stars, int i, Player* player, Space* spaces);

private:
	
};

#endif