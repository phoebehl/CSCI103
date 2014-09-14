#ifndef ACTION_H
#define ACTION_H

#include <string.h>
#include "player.h"
#include "space.h"

using namespace std;

class Action
{
public:
	Action();
	void setBoardAction(int i);
	string getText(int j);
	void virtual executeAction(int space, int stars, int i, Player* player, Space* spaces) = 0;

private:
	string _text[3];//3 lines of text to describe action
};

#endif