#ifndef SPACE_H
#define SPACE_H

#include <string.h>
#include "player.h"
//#include "action.h"

using namespace std;

class Action;

class Space
{
public:
	Space();
	void populate(Action** boardActions, int i, int numPlayers);
	string getPlayer(string p, int posit);
	string getName();
	string getAction(int j);
	bool ifOccupied(int i);
	void toggle(bool switchTo, int player);
	

private:
	string _name;
	Action* _myAction;//Action class
	bool _players[3];
};

#endif
