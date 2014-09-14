#ifndef CARD2_H
#define CARD2_H

#include <string.h>
#include "player.h"
#include "space.h"
#include "action.h"

using namespace std;

class Card2 : public Action
{
public:
	Card2();
	void setCards();
	string getText();
	void executeAction(int space, int stars, int i, Player* player, Space* spaces);

private: 
	string _text;

};

#endif