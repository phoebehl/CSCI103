#include <iostream>
#include <cstdlib>
#include "game_board.h"
#include "space.h"
#include "action.h"
#include "player.h"

using namespace std;

Game_Board::Game_Board(Space *spaces)
{
	_spaces = spaces;

}

void Game_Board::printFirst(string p1Piece, string p2Piece, string p3Piece, string p4Piece)
{
	cout << "________                                  __________________________________________________                                  ________" << endl;
	cout << "|" << _spaces[0].getName() << "|                                  |";
	for (int i = 0; i < 7; i++)
	{
		cout << _spaces[18+i].getName() << "|";
	} 
	cout << "                                  |"<< _spaces[42].getName() << "|"<< endl;
	cout << "|      |                                  |      |      |      |      |      |      |      |                                  |      |" << endl;

	for (int j = 0; j < 3; j++)
	{
		cout << "|" << _spaces[0].getAction(j) << "|                                  |";
		for (int i = 0; i < 7; i++)
		{
			cout << _spaces[18+i].getAction(j) << "|";
		}
		cout << "                                  |"<< _spaces[42].getAction(j) << "|" << endl;
	}
	cout << "| " << _spaces[0].getPlayer(p1Piece, 0) << _spaces[0].getPlayer(p2Piece, 1) << _spaces[0].getPlayer(p3Piece, 2) << _spaces[0].getPlayer(p4Piece, 3) << " |                                  | ";
	for (int i = 0; i < 7; i++)
	{
		cout << _spaces[18+i].getPlayer(p1Piece, 0) << _spaces[18+i].getPlayer(p2Piece, 1) << _spaces[18+i].getPlayer(p3Piece, 2) << _spaces[18+i].getPlayer(p4Piece, 3) << " | ";
	}
	cout << "                                 | " << _spaces[42].getPlayer(p1Piece, 0) << _spaces[42].getPlayer(p2Piece, 1) << _spaces[42].getPlayer(p3Piece, 2) << _spaces[42].getPlayer(p4Piece, 3) << " |" << endl;
	cout << "________                                  __________________________________________________                                  ________" << endl;
}

void Game_Board::printMiddle(bool last, string p1Piece, string p2Piece, string p3Piece, string p4Piece)
{
	if (last == false)
	{
		for (int i = 0; i < 4; i++)
		{
			

			cout << "|" << _spaces[1+i].getName() << "|                                  |" << _spaces[17-i].getName() << "|                                  |" << _spaces[25+i].getName() << "|                                  |" << _spaces[41-i].getName() << "|" << endl;
			cout << "|      |                                  |      |                                  |      |                                  |      |" << endl;
			for (int j = 0; j < 3; j++)
			{
				cout << "|" << _spaces[1+i].getAction(j) << "|                                  |" << _spaces[17-i].getAction(j) << "|                                  |" << _spaces[25+i].getAction(j) << "|                                  |" << _spaces[41-i].getAction(j) << "|" << endl;
			}
			cout << "| " << _spaces[1+i].getPlayer(p1Piece, 0) << _spaces[1+i].getPlayer(p2Piece, 1) << _spaces[1+i].getPlayer(p3Piece, 2) << _spaces[1+i].getPlayer(p4Piece, 3) << " |                                  | ";
			cout << _spaces[17-i].getPlayer(p1Piece, 0) << _spaces[17-i].getPlayer(p2Piece, 1) << _spaces[17-i].getPlayer(p3Piece, 2) << _spaces[17-i].getPlayer(p4Piece, 3) << " |                                  | ";
			cout << _spaces[25+i].getPlayer(p1Piece, 0) << _spaces[25+i].getPlayer(p2Piece, 1) << _spaces[25+i].getPlayer(p3Piece, 2) << _spaces[25+i].getPlayer(p4Piece, 3) << " |                                  | ";
			cout << _spaces[41-i].getPlayer(p1Piece, 0) << _spaces[41-i].getPlayer(p2Piece, 1) << _spaces[41-i].getPlayer(p3Piece, 2) << _spaces[41-i].getPlayer(p4Piece, 3) << " |" << endl;
			cout << "________                                  ________                                  ________                                  ________" << endl;
		}

	}
	else
	{
		//cout << "________                                  __________________________________________________                                  ________" << endl;

		cout << "|" << _spaces[5].getName() << "|                                  |" << _spaces[13].getName() << "|                                  |" << _spaces[29].getName() << "|                                  |" << _spaces[37].getName() << "|" << endl;
		cout << "|      |                                  |      |                                  |      |                                  |      |" << endl;
		for (int j = 0; j < 3; j++)
		{
			cout << "|" << _spaces[5].getAction(j) << "|                                  |" << _spaces[13].getAction(j) << "|                                  |" << _spaces[29].getAction(j) << "|                                  |" << _spaces[37].getAction(j) << "|" << endl;
		}
		cout << "| " << _spaces[5].getPlayer(p1Piece, 0) << _spaces[5].getPlayer(p2Piece, 1) << _spaces[5].getPlayer(p3Piece, 2) << _spaces[5].getPlayer(p4Piece, 3) << " |                                  | ";
		cout << _spaces[13].getPlayer(p1Piece, 0) << _spaces[13].getPlayer(p2Piece, 1) << _spaces[13].getPlayer(p3Piece, 2) << _spaces[13].getPlayer(p4Piece, 3) << " |                                  | ";
		cout << _spaces[29].getPlayer(p1Piece, 0) << _spaces[29].getPlayer(p2Piece, 1) << _spaces[29].getPlayer(p3Piece, 2) << _spaces[29].getPlayer(p4Piece, 3) << " |                                  | ";
		cout << _spaces[37].getPlayer(p1Piece, 0) << _spaces[37].getPlayer(p2Piece, 1) << _spaces[37].getPlayer(p3Piece, 2) << _spaces[37].getPlayer(p4Piece, 3) << " |" << endl;
		cout << "__________________________________________________                                  __________________________________________________" << endl;
	}


}

void Game_Board::printLast(string p1Piece, string p2Piece, string p3Piece, string p4Piece)
{
	cout << "|";
	for (int i = 0; i < 7; i++)
	{
		cout << _spaces[6+i].getName() << "|";
	}
	cout << "                                  |";
	for (int i = 0; i < 7; i++)
	{
		cout << _spaces[30+i].getName() << "|";
	}
	cout << endl;
	cout << "|      |      |      |      |      |      |      |                                  |      |      |      |      |      |      |      |" << endl;
	//cout << "| ";
	for (int j = 0; j < 3; j++)
	{
		cout << "|";
		for (int i = 0; i < 7; i++)
		{
			cout << _spaces[6+i].getAction(j) << "|";
		}
		cout << "                                  |";
		for (int i = 0; i < 7; i++)
		{
			cout << _spaces[30+i].getAction(j) << "|";
		}
		cout << endl;
	}
	cout << "| ";
	for (int i = 0; i < 7; i++)
	{
		cout << _spaces[6+i].getPlayer(p1Piece, 0) << _spaces[6+i].getPlayer(p2Piece, 1) << _spaces[6+i].getPlayer(p3Piece, 2) << _spaces[6+i].getPlayer(p4Piece, 3) << " | ";
	}
	cout << "                                 | ";
	for (int i = 0; i < 7; i++)
	{
		cout << _spaces[30+i].getPlayer(p1Piece, 0) << _spaces[30+i].getPlayer(p2Piece, 1) << _spaces[30+i].getPlayer(p3Piece, 2) << _spaces[30+i].getPlayer(p4Piece, 3) << " | ";
	}
	cout << endl;
	cout << "__________________________________________________                                  __________________________________________________" << endl;
	

}

void Game_Board::printBoard(string p1Piece, string p2Piece, string p3Piece, string p4Piece)
{
	printFirst(p1Piece, p2Piece, p3Piece, p4Piece);
	printMiddle(false, p1Piece, p2Piece, p3Piece, p4Piece);
	printMiddle(true, p1Piece, p2Piece, p3Piece, p4Piece);
	printLast(p1Piece, p2Piece, p3Piece, p4Piece);
}
