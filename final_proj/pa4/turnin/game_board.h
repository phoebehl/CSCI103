#ifndef GAME_BOARD_H
#define GAME_BOARD_H


#include "player.h"
#include "space.h"

using namespace std;

class Game_Board
{
public: 
	Game_Board(Space* spaces);
	void printFirst(string p1Piece, string p2Piece, string p3Piece, string p4Piece);
	void printMiddle(bool last, string p1Piece, string p2Piece, string p3Piece, string p4Piece);
	void printLast(string p1Piece, string p2Piece, string p3Piece, string p4Piece);
	void printBoard(string p1Piece, string p2Piece, string p3Piece, string p4Piece);

private:
	//const int _NUMSPACES = 43;
	Space* _spaces;
};

#endif
