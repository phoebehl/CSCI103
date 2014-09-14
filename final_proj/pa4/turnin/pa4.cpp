#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cstring>
#include <ctime>
#include "player.h"
#include "action.h"
#include "space.h"
#include "game_board.h"
#include "bank.h"


using namespace std;

//Prototypes

//Global variables
int numPlayers;
int move;
Player p1;
Player p2;
Player p3;
Player p4;

Action actions[43];//Array of all the actions
Space spaces[43];//An array of all the spaces used in the game


//Player players[3];

int main()
{
	srand(time(0));
	//Start the game
	cout << "How many players do you want? Enter a number from 2-4: ";
	cin >> numPlayers;

	if (numPlayers < 2 || numPlayers > 4)
	{
		cout << "You entered an invalid number of players...Please restart.";
		return -1;
	}

	//Now let each player select their gamepiece
	string tempPiece;
	for (int i = 0; i < numPlayers; i++)
	{
		cout << "Player " << i+1 << ", select one piece from the following. No player may choose the same piece." << endl;
		cout << "You will be asked to choose again if another player has already selected that piece." << endl;
		cout << "A B C D E F G H I J K" << endl;
		cin >> tempPiece;

		while (cin.fail() || (tempPiece != "A" && tempPiece != "B" && tempPiece != "C" && tempPiece != "D" && tempPiece != "E" && tempPiece != "F" &&
			 tempPiece != "G" && tempPiece != "H" && tempPiece != "I" && tempPiece != "J" && tempPiece != "K"))
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "You entered an invalid piece...please try again: ";
			cin >> tempPiece;
		}
		if (i == 0)
		{
			p1.selectPiece(tempPiece);
		}
		if (i == 1)
		{
			while (p1.showPiece() == tempPiece)
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Another player already selected that piece. Please enter a different one: ";
				cin >> tempPiece;
			}
			p2.selectPiece(tempPiece);
		}
		if (i == 2)
		{
			while (p1.showPiece() == tempPiece || p2.showPiece() == tempPiece)
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Another player already selected that piece. Please enter a different one: ";
				cin >> tempPiece;

			}
			p3.selectPiece(tempPiece);
		}
		if (i == 3)
		{
			while (p1.showPiece() == tempPiece || p2.showPiece() == tempPiece || p3.showPiece() == tempPiece)
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Another player already selected that piece. Please enter a different one: ";
				cin >> tempPiece;
			}
			p4.selectPiece(tempPiece);
		}
		
	}
	
	//Action action
	for (int i = 0; i < 43; i++)
	{
		spaces[i].populate(actions, i, numPlayers);
	}
	Game_Board board(spaces);
	string p1Piece = p1.showPiece();
	string p2Piece = p2.showPiece();
	string p3Piece = p3.showPiece();
	string abc = "  ";//No use, but memory gets messed up without this in between
	string p4Piece = p4.showPiece();
	board.printBoard(p1Piece, p2Piece, p3Piece, p4Piece);
/*
	while (move != -1)
	{
		if (numPlayers == 2)
		{
			move = p1.singleRoll();
			board.printBoard(p1Piece, p2Piece, p3Piece, p4Piece);

			board.printBoard(p1Piece, p2Piece, p3Piece, p4Piece);

		}

		if (numPlayers == 3)
		{

			board.printBoard(p1Piece, p2Piece, p3Piece, p4Piece);

			board.printBoard(p1Piece, p2Piece, p3Piece, p4Piece);

			board.printBoard(p1Piece, p2Piece, p3Piece, p4Piece);

		}

		if (numPlayers == 4)
		{

			board.printBoard(p1Piece, p2Piece, p3Piece, p4Piece);

			board.printBoard(p1Piece, p2Piece, p3Piece, p4Piece);

			board.printBoard(p1Piece, p2Piece, p3Piece, p4Piece);

			board.printBoard(p1Piece, p2Piece, p3Piece, p4Piece);

		}
		quit = p1.singleRoll();
		quit = p2.singleRoll();
		quit = p3.singleRoll();
		quit = p4.singleRoll();
	}
	//Possibly make an "all players turn" function that calls singleRoll...
	//If at any point you return a -1, then quit...recursive?


	*/
}