#ifndef PLAYER_H
#define PLAYER_H

#include <string.h>
#include "game_board.h"

using namespace std;

class Player
{
public:
	Player();
	void selectPiece(string choice);
	string showPiece();
	int getSpace();
	void setSpace(int space);
	int getStars();
	void setStars(int num);
	string getName();

	private:
	int _currentSpace;
	int _totStars;
	string _piece;
	string _name;
};

#endif
