#include <iostream>
#include <cstring>
#include <cmath>

#include "card1.h"
#include "player.h"
#include "space.h"
#include "action.h"

using namespace std;

Card1::Card1()
{
	_text = "        ";
}

void Card1::setCards()
{

	_text = "You lose 20 stars!";
	
}

string Card1::getText()
{
	return _text;
}

void Card1::executeAction(int space, int stars, int i, Player* player, Space* spaces)
{
	(player+i)->setStars(stars);

}
