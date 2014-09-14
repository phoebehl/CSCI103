#ifndef STARSACTION_H
#define STARSACTION_H

#include <string.h>
#include "player.h"
#include "space.h"
#include "action.h"

using namespace std;

class StarsAction : public Action
{
public:
	StarsAction();
	void executeAction(int space, int stars, int i, Player* player, Space* spaces);

private:
	
	
};

#endif