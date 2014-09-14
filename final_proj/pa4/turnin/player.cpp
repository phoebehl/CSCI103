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
	_totPoints = 0;
	_piece = " ";
}

void Player::selectPiece(string choice)
{
	_piece = choice;

}

string Player::showPiece()
{
	return _piece;
}
/*
int Player::singleRoll(string p1Piece, string p2Piece, string p3Piece, string p4Piece)
{
	char playing;
	cout << "If you would like to quit the game, press the 'q' key. Otherwise, press any key to roll the dice: ";
	cin >> playing;
	if (cin.fail())
	{
		cout << "Sorry, you entered something invalid...please try again: ";
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> playing;
	}
	if (playing == 'q')
	{
		return -1;
	}

	int dice1 = (rand()%6)+1;
	int dice2 = (rand()%6)+1;
	int toMove = dice1+dice2;

	//How do I refer to a specifc player object in the same class?
	_currentSpace += toMove;
	//board.printBoard(p1Piece, p2Piece, p3Piece, p4Piece);
	return _currentSpace;
}
*/

