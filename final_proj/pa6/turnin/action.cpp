#include <iostream>
#include <cmath>
#include "action.h"

using namespace std;

Action::Action()
{
	for (int i = 0; i < 3; i++)
	{
		_text[i] = "      ";
	}
}

void Action::setBoardAction(int i)
{
	if (i == 0)
	{
		_text[1] = "START!";

	}

	else if (i == 42)
	{
		_text[0] = "FINISH";
		_text[1] = " MUCH ";
		_text[2] = " YAY  ";
	}
	//Moving actions

	else if ((i+3)%6 == 0)
	{
		_text[0] = "Move 3";
		_text[1] = "spaces";
		_text[2] = "ahead.";
	}

	else if (i == 4 || i == 16 || i == 28)
	{
		_text[0] = "Move 3";
		_text[1] = "spaces";
		_text[2] = "back. ";
	}

	else if (i == 8 || i == 20 || i == 32)
	{
		_text[0] = "Move 1";
		_text[1] = "space ";
		_text[2] = "back. ";
	}

	//Money actions (Bank)
	else if (i == 1 || i == 17 || i == 30)
	{
		_text[0] = " You  ";
		_text[1] = "won 10";
		_text[2] = "stars!";

	}

	else if (i == 11 || i == 23 || i == 35)
	{
		_text[0] = " You  ";
		_text[1] = "lost 6";
		_text[2] = "stars!";	
	}


	//Draw Card 1
	else if (i == 10 || i == 25 || i == 37)
	{
		_text[0] = "Draw a";
		_text[1] = "happy ";
		_text[2] = "card! ";

	}

	//Draw Card 2
	else if (i == 5 || i == 29 || i == 39)
	{
		_text[0] = "Draw a";
		_text[1] = " sad  ";
		_text[2] = "card! ";

	}

	//Roll again
	else if (i == 7 || i == 13 || i == 19 || i == 26 || i == 34)
	{
		_text[0] = " YAY! ";
		_text[1] = " Roll ";
		_text[2] = "again!";
	}

	//Remaining spaces
	else
	{
		_text[0] = "You're";
		_text[1] = "safe! ";
	}



}

string Action::getText(int j)
{
	return _text[j];
}
