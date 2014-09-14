#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "player.h"
#include "game_board.h"

using namespace std;

Player::Player()
{
	_currentSpace = 0;
	_totStars = 0;
	_piece = " ";
	//_name = name;
}

void Player::selectPiece(string choice)
{
	_piece = choice;

}

string Player::showPiece()
{
	return _piece;
}

int Player::getSpace()
{
	return _currentSpace;
}

void Player::setSpace(int space)
{
	_currentSpace = space;
}

int Player::getStars()
{
	return _totStars;
}

void Player::setStars(int num)
{
	_totStars = _totStars+num;
}

string Player::getName()
{
	//return _name;
}