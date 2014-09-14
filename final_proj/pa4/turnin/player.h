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
	//bool singleRoll(Game_Board board, string p1Piece, string p2Piece, string p3Piece, string p4Piece);

	private:
	int _currentSpace;
	int _totPoints;
	string _piece;
};

#endif