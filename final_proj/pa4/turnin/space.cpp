#include <iostream>
#include <cstring>
#include <sstream>
#include "player.h"
#include "action.h"
#include "space.h"

using namespace std;

Space::Space()
{
	_name = "0";
	
	for (int i = 0; i < 3; i++)
	{
		_players[i] = false;
	}
	
}

void Space::populate(Action* actions, int i, int numPlayers)//Sets the board to how it should be for the very start of the game
{
	_myAction = actions;
	stringstream ss;
	string tempVal;
	string tempName;

	ss << i+1;
	ss >> tempVal;
	if (i < 9)
	{
		tempName = " SQ0";
	}
	else
	{
		tempName = " SQ";
	}
	tempName.append(tempVal);
	tempName.append(" ");
	ss.clear();
	_name = tempName;

	for (int j = 0; j < 3; j++)
	{
		_players[j] = false;
	}

	if (i == 0)
	{
		for (int j = 0; j < numPlayers; j++)
		{
			_players[j] = true;
		}

	}

}

string Space::getPlayer(string p, int posit)
{
	if  (_players[posit] == true)
	{
		return p;
	}

	else
	{
		return " ";
	}
}

string Space::getName()
{
	return _name;
}

string Space::getAction(int j)
{
	return _myAction->getText(j);
}

void Space::stAction(Action* a)
{
	action = a;
}

void Space::doAction(Board&b)
{
	action.executeAction()
}