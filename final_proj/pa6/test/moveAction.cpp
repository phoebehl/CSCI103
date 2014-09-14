#include <iostream>
#include <cmath>
#include "moveAction.h"
#include "player.h"
#include "space.h"
#include "action.h"

using namespace std;

MoveAction::MoveAction()
{
	
}

void MoveAction::executeAction(int space, int stars, int i, Player* player, Space* spaces)
{
	//Move 3 spaces back
	if (space == 4 || space == 16 || space == 28)
	{
		(player+i)->setSpace(space-3);
		(spaces+(space-3))->toggle(true, i);

	}

	//Move 1 space back
	if (space == 8 || space == 20 || space == 32)
	{
		(player+i)->setSpace(space-1);
		(spaces+(space-1))->toggle(true, i);
	}

	//Move 3 spaces forward
	if (space == 3 || space == 9 || space == 15 || space == 21 || space == 27 || space == 33)
	{
		(player+i)->setSpace(space+3);
		(spaces+(space+3))->toggle(true, i);

	}

}