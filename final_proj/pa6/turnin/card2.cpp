#include <iostream>
#include <cstring>
#include <cmath>

#include "card2.h"
#include "player.h"
#include "space.h"
#include "action.h"

using namespace std;

Card2::Card2()
{
	_text = "        ";
}

void Card2::setCards()
{
	
	_text = "You get 17 stars!";
	
}

string Card2::getText()
{
	return _text;
}

void Card2::executeAction(int space, int stars, int i, Player* player, Space* spaces)
{
	(player+i)->setStars(stars);

}