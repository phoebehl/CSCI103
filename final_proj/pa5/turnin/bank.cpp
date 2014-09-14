#include <iostream>
#include <cmath>

#include "bank.h"
#include "player.h"
#include "space.h"
#include "action.h"

using namespace std;

Bank::Bank()
{
	_Stars = 100000000;
	
}

void Bank::executeAction(int space, int stars, int i, Player* player, Space* spaces)
{
	if (space == 1 || space == 17 || space == 30)
	{
		cout << "You won 10 stars!" << endl;
		(player+i)->setStars(10);
		_Stars = _Stars-10;
	}

	else
	{
		cout << "You lost 6 stars!" << endl;
		(player+i)->setStars(-6);
		_Stars = _Stars+6;
	}

	(player+i)->setSpace(space);
	(spaces+space)->toggle(true, i);

}