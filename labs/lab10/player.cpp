#include <iostream>
#include <sstream>
#include <cstring>
#include "player.h"
#include "moneyAction.h"

using namespace std;

Player::Player()
{
	_currentSpace = 0;
	_totPoints = 0;
	_piece = "0";
}

void Player::give_money(int amount)
{
	_totPoints += amount;
	cout << "the other player now has: " << _totPoints << endl;

}

