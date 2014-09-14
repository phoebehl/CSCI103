#include <iostream>
#include <cmath>

#include "starsAction.h"
#include "player.h"
#include "space.h"
#include "action.h"

using namespace std;

StarsAction::StarsAction()
{
	
}

void StarsAction::executeAction(int space, int stars, int i, Player* player, Space* spaces)
{
	if (space == 1 || space == 17 || space == 30)
	{
		(player+i)->setStars(10);
	}

	else
	{
		(player+i)->setStars(-6);
	}

	(player+i)->setSpace(space);
	(spaces+space)->toggle(true, i);

}
