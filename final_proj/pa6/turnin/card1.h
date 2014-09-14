#ifndef CARD1_H
#define CARD1_H

#include <string.h>
#include "player.h"
#include "space.h"
#include "action.h"

using namespace std;

class Card1 : public Action
{
public:
	Card1();
	void setCards();
	string getText();
	void executeAction(int space, int stars, int i, Player* player, Space* spaces);

private: 
	string _text;

};

#endif