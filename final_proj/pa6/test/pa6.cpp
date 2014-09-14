#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cstring>
#include <ctime>
#include <QtGui>
#include <QApplication>
#include <QString>

#include "player.h"
#include "action.h"
#include "space.h"
#include "game_board.h"
#include "bank.h"
#include "card1.h"
#include "card2.h"
#include "moveAction.h"

#include "mainWindow.h"

using namespace std;

//Prototypes
int dice();

//Global variables
int numPlayers;
int numQuit; //Number of players who have quit the game
Bank bank;
char playing;

Action* boardActions[43];//Array of pointers to all the actions
Space spaces[43];//An array of all the spaces used in the game
//Player players[4];
Card1 happyDeck[4];
Card2 sadDeck[4];

int main( int argv, char* argc[] )
{
	QApplication app( argv, argc );
	StartWindow sw;
	sw.show();

	MainWindow mw;
  	mw.show();

	srand(time(0));
	//Gets gameboard and card decks ready for gameplay
	for (int i = 0; i < 43; i++)
	{
		if ( i == 4 || i == 16 || i == 28 || i == 8 || i == 20 || i == 32 ||
			i == 3 || i == 9 || i == 15 || i == 21 || i == 27 || i == 33)
		{
			boardActions[i] = new MoveAction();
			boardActions[i]->setBoardAction(i);
		}

		else if ( i == 10 || i == 25 || i == 37)
		{
			boardActions[i] = new Card1();
			boardActions[i]->setBoardAction(i);
		}

		else if ( i == 5 || i == 29 || i == 39)
		{
			boardActions[i] = new Card2();
			boardActions[i]->setBoardAction(i);
		}	

		else if ( i == 1 || i == 11 || i == 17 || i == 23 || i == 30 || i == 35)
		{
			boardActions[i] = new Bank();
			boardActions[i]->setBoardAction(i);
		}

		else
		{
			boardActions[i] = new MoveAction();
			boardActions[i]->setBoardAction(i);
		}	
	}
	//Generate the two decks of cards
	for (int i = 0; i < 4; i++)
	{
		happyDeck[i].setCards();
		sadDeck[i].setCards();
	}
	/*
	//Getting all the necessary info....
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
			players[0].selectPiece(tempPiece);
		}
		if (i == 1)
		{
			while (players[0].showPiece() == tempPiece)
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Another player already selected that piece. Please enter a different one: ";
				cin >> tempPiece;
			}
			players[1].selectPiece(tempPiece);
		}
		if (i == 2)
		{
			while (players[0].showPiece() == tempPiece || players[1].showPiece() == tempPiece)
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Another player already selected that piece. Please enter a different one: ";
				cin >> tempPiece;

			}
			players[2].selectPiece(tempPiece);
		}
		if (i == 3)
		{
			while (players[0].showPiece() == tempPiece || players[1].showPiece() == tempPiece || players[2].showPiece() == tempPiece)
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Another player already selected that piece. Please enter a different one: ";
				cin >> tempPiece;
			}
			players[3].selectPiece(tempPiece);
		}
		
	}

	
	for (int i = 0; i < 43; i++)
	{
		spaces[i].populate(boardActions, i, numPlayers);
	}

	Game_Board board(spaces);
	string p1Piece = players[0].showPiece();
	string p2Piece = players[1].showPiece();
	string p3Piece = players[2].showPiece();
	string abc = "  ";//No use, but memory gets messed up without this in between
	string p4Piece = players[3].showPiece();
	board.printBoard(p1Piece, p2Piece, p3Piece, p4Piece);

	//WHOOO all set up, time to play the game
	while (spaces[42].ifOccupied(0) == false || spaces[42].ifOccupied(1) == false || spaces[42].ifOccupied(2) == false || spaces[42].ifOccupied(3) == false)
	{
		for (int i = 0; i < numPlayers; i++)
		{
			if (players[i].showPiece() != " ")
			{
				cout << "Player " << i+1 << ": If you would like to quit the game, press the 'q' key. Otherwise, press any other key to roll the dice: ";
				cin >> playing;
				if (cin.fail())
				{
					cout << "Sorry, you entered something invalid...please try again: ";
					cin.clear();
					cin.ignore(10000, '\n');
					cin >> playing;
				}
			}

				if (playing == 'q')
				{
					numQuit++;
					playing = 'X';//resets playing to something that's not q
					cout << "Player " << i+1 << " has quit the game." << endl;
					string resign = " ";
					players[i].selectPiece(resign);
					int clearSpace = players[i].getSpace();
					spaces[clearSpace].toggle(false, i);
					cout <<"The remaining players are: " << endl;
					for (int i = 0; i < 4; i++)
					{
						if (players[i].showPiece() != " ")
						{
							cout << "Player " << i+1 << endl;
						}
					
					}
					//The game cannot be played if there is just one person left
					if (numPlayers == 2 || (numPlayers-numQuit) == 1)
					{
						cout << "Only one player remains, so the game has ended. No one reached the finish line T_T" << endl;
						return 0;
					}
				}
			//}

			else
			{
				if (players[i].showPiece() != " ")
				{
					//Move player off current space
					int space = players[i].getSpace();
					spaces[space].toggle(false, i);
					int moveTo = dice();
					space = space+moveTo;
					cout << "You rolled a " << moveTo << endl;
					if (space > 41)
					{
						cout << "Player " << (i+1) << " has reached the finish line!" << endl;
						cout << "PLAYER " << (i+1) << " WINS THE GAME!!!" << endl;
						
						for (int j = 0; j < numPlayers; j++)
						{
							//If the player has negative stars
							if (players[j].getStars() < 0)
							{
								cout << "Player " << (j+1) << " lost " << -(players[j].getStars()) << " stars." << endl;
							}

							else
							{
								cout << "Player " << (j+1) << " collected " << players[j].getStars() << " stars." << endl;
							}
						}
						cout << "No prizes for getting (or losing) stars, but you can pat yourselves on the back!" << endl;
						return 0;
					}
					//Landed on a safe space
					if (space == 2 || space == 6 || space == 12 || space == 14 || space == 18 ||
						space == 22 || space == 24 || space == 31 || space == 36 || space == 38 || 
						space == 40 || space == 41)
					{
						spaces[space].toggle(true, i);
						players[i].setSpace(space);
						board.printBoard(p1Piece, p2Piece, p3Piece, p4Piece);
					}

					//Landed on a stars(bank) space
					if (space == 1 || space == 11 || space == 17 || space == 23 || space == 30 || space == 35)
					{
						Bank star;
						star.executeAction(space, 0, i, players, spaces);
						board.printBoard(p1Piece, p2Piece, p3Piece, p4Piece);
					}
					//Landed on a happy card square
					else if (space == 10 || space == 25 || space == 37)
					{
						cout << "You get to draw a happy card!" << endl << "Your card says: You lose 20 stars!" << endl;

						Card1 card1;
						card1.executeAction(space, -20, i, players, spaces);

						spaces[space].toggle(true, i);
						players[i].setSpace(space);
						board.printBoard(p1Piece, p2Piece, p3Piece, p4Piece);

					}
					//Landed on a sad card square
					else if (space == 5 || space == 29 || space == 39)
					{
						cout << "You get to draw a sad card!" << endl << "Your card says: You get 15 stars!" << endl;

						Card2 card2;
						card2.executeAction(space, 15, i, players, spaces);

						spaces[space].toggle(true, i);
						players[i].setSpace(space);
						board.printBoard(p1Piece, p2Piece, p3Piece, p4Piece);

					}

					//Landed on a roll again square
					else if (space == 7 || space == 13 || space == 19 ||
						space == 26 || space == 34)
					{
						cout << "You get to roll again!" << endl;
						moveTo = dice();
						cout << "You rolled a " << moveTo << endl;
						space = space+moveTo;
						//Add note that the action does not apply if you rolled dice twice
						if (space > 41)
						{
							spaces[42].toggle(true, i);
							board.printBoard(p1Piece, p2Piece, p3Piece, p4Piece);
							cout << "Player " << (i+1) << " has reached the finish line!" << endl;
							cout << "PLAYER " << (i+1) << " WINS THE GAME!!!" << endl;

							for (int j = 0; j < numPlayers; j++)
							{
								//If the player has negative stars
								if (players[j].getStars() < 0)
								{
									cout << "Player " << (j+1) << " lost " << -(players[j].getStars()) << " stars." << endl;
								}

								else
								{
									cout << "Player " << (j+1) << " collected " << players[j].getStars() << " stars." << endl;
								}
							}
							cout << "No prizes for getting (or losing) stars, but you can pat yourselves on the back!" << endl;
							return 0;
						}
						else
						{
							spaces[space].toggle(true, i);
							players[i].setSpace(space);
							board.printBoard(p1Piece, p2Piece, p3Piece, p4Piece);

						}

					}
					//Landed on a movement square
					else
					{
						cout << "This space says: " << endl << spaces[space].getAction(0) << endl << spaces[space].getAction(1) <<
						endl << spaces[space].getAction(2) << endl;

						MoveAction move;
						move.executeAction(space, 0, i, players, spaces);

						board.printBoard(p1Piece, p2Piece, p3Piece, p4Piece);
					}
				}//End of if player piece is not blank
			}

		}//End of for loop

	}//End of while loop
	cout << "THE GAME HAS ENDED!" << endl;
	if (spaces[42].ifOccupied(0) == true)
	{
		cout << "PLAYER 1 HAS REACHED THE FINISH LINE AND WINS THE GAME!";
	}

	else if (spaces[42].ifOccupied(1) == true)
	{
		cout << "PLAYER 2 HAS REACHED THE FINISH LINE AND WINS THE GAME!";
	}

	else if (spaces[42].ifOccupied(2) == true)
	{
		cout << "PLAYER 3 HAS REACHED THE FINISH LINE AND WINS THE GAME!";
	}

	else
	{
		cout << "PLAYER 4 HAS REACHED THE FINISH LINE AND WINS THE GAME!";
	}
	cout << endl;
	
	for (int j = 0; j < numPlayers; j++)
	{
		//If the player has negative stars
		if (players[j].getStars() < 0)
		{
			cout << "Player " << (j+1) << " lost " << -(players[j].getStars()) << " stars." << endl;
		}

		else
		{
			cout << "Player " << (j+1) << " collected " << players[j].getStars() << " stars." << endl;
		}
	}
	cout << "No prizes for getting (or losing) stars, but you can pat yourselves on the back!" << endl;
*/
return app.exec();
return 0;
}

//Used to roll the dice once
int dice()
{
	int dice1 = (rand()%6)+1;
	int dice2 = (rand()%6)+1;
	int toMove = dice1+dice2;

	return toMove;
}