#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

//Prototypes
int readText();
void rd1Shuffle();
int printBracket();
double randProb();
void playRd1(bool watch);
void overtime(bool watch, int i);


//Variables
int count = 1; //for play() function
int roundOf = 8; //for play() function
string allTeams[8] = {"trojans", "bruins", "trees", "ducks", "cougars", "bears", "dogs", "fish"};
string bracket1[8];
string bracket2[4];
string bracket3[2];
double probBracket1[2][8];
double probBracket2[2][4];
double probBracket3[2][2];
bool inPlay[8] = {false};
string* pHome;
string* pAway;

//Stats variables
int homeScore = 0;
int homeTD = 0;
int homeFG = 0;
int awayScore = 0;
int awayTD = 0;
int awayFG = 0;




int main()
{
	char ans;
	bool watch;

	srand(time(0));
	readText();
	rd1Shuffle();

	for ( int i = 0; i < 3; i++ ){

		printBracket();
		//Input if want to watch
		cout << "Feeling voyeuristic this round? (Answer y/n)" << endl;
		cin >> ans;

		while (ans != 'y' && ans != 'n'){
			cout << "Your answer was invalid...answer with y/n: " << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			cin >> ans;
		}
		cout << endl << endl;

		if (ans == 'y') {
		watch = true;
		}
		else {
		watch = false;

		playRd1(watch);



		}
	}


}

int readText()
{

	
}

void rd1Shuffle()
{
	int y;
	string tempTeam;
	int tempTD;
	int tempFG;

	for ( int i = 0; i < 10; i++ ){
		for (int j = 0; j < 8; j++ ){

			tempTeam = allTeams[j];
			tempTD = allProb[0][j];
			tempFG = allProb[1][j];
			y = rand()%8;
			allTeams[j] = allTeams[y];
			allProb[0][j] = allProb[0][y];
			allProb[1][j] = allProb[1][y];
			allTeams[y] = tempTeam;
			allProb[0][y] = tempTD;
			allProb[1][y] = tempFG;

		}
	
	}
	//Fills an array identical to allTeams to be used in later functions
	for (int i = 0; i < 8; i++)
	{
		bracket1[i] = allTeams[i];
	}


}


int printBracket();
{	cout << "---------------" << endl;
	cout << "| " << setw(11) << *pHome;
	cout << " |" << endl;
	cout << "| " << setw(11) << left << "GAME 1";
	cout << " |" << "~~~~|" << endl;
	cout << "| " << setw(11) << right << *pAway;
	cout << " |    |    ---------------" << endl;
	pHome = &bracket2[0];
	pAway = &bracket2[1];
	cout << "---------------    |    | " << setw(11) << *pHome;
	cout << " |" << endl;
	cout << "                   |~~~~| " << setw(11) << left << "GAME 5";
	cout << " |~~~~|" << endl;
	cout << "---------------    |    | " << setw(11) << right << *pAway;
	cout << " |    |" << endl;
	pHome = &bracket1[2];
	pAway = &bracket1[3];
	cout << "| " << setw(11) << *pHome;
	cout << " |    |    ---------------    |" << endl;
	cout << "| " << setw(11) << left << "GAME 2";
	cout << " |~~~~|                       |" << endl;
	cout << "| " << setw(11) << right << *pAway;
	cout << " |                            |    ---------------"<< endl;
	pHome = &bracket3[0];
	pAway = &bracket3[1];
	cout << "---------------                            |    | "<< setw(11) << *pHome;
	cout << " |" << endl;
	cout << "                                           |~~~~| " << setw(11) << left << "GAME 7";
	cout << " |" << endl;
	cout << "---------------                            |    | " << setw(11) << right << *pAway;
	cout << " |" << endl;
	pHome = &bracket1[4];
	pAway = &bracket1[5];
	cout << "| " << setw(11) << *pHome;
	cout << " |                            |    ---------------" << endl;
	cout << "| " << setw(11) << left << "GAME 3";
	cout << " |~~~~|                       |" << endl;
	cout << "| " << setw(11) << right << *pAway;
	cout << " |    |    ---------------    |" << endl;
	pHome = &bracket2[2];
	pAway = &bracket2[3];
	cout << "---------------    |    | " << setw(11) << *pHome;
	cout << " |    |" << endl;
	cout << "                   |~~~~| " << setw(11) << left << "GAME 6" << " |~~~~|" << endl;
	cout << "---------------    |    | " << setw(11) << right << *pAway;
	cout << " |" << endl;
	pHome = &bracket1[6];
	pAway = &bracket1[7];
	cout << "| " << setw(11) << *pHome;
	cout << " |    |    ---------------" << endl;
	cout << "| " << setw(11) << left << "GAME 4";
	cout << " |~~~~|" << endl;
	cout << "| " << setw(11) << right << *pAway;
	cout << " |" << endl;
	cout << "---------------" << endl << endl;

}

double randProb()
{
	double x;
	x = (rand()%101)/100;
	return x;

}


void playRd1(bool watch )
{
	
	for (int i = 0; i < 4 ; i++)
	{
		cout << "GAME " << count << " - " << bracket1[i*2] << " vs " << bracket1[(i*2)+1]  << endl;
		cout << "------" << endl << endl;
		count++;

		//Teams 1 and 2 play for 4 quarters
		for (int j = 0; j < 4; j++)
		{
			if (watch == true)
			{
				cout << "QUARTER " << j << endl;
				cout << bracket1[i*2] << "'s ball ~~~ ";
			}

			randProb();
			if (x < probBracket1[0][i*2])
			{
				homeTD++;
				if (watch == true)
				{
				cout << "TOUCHDOWN" << endl;
				}
			}
			else 
			{
				randProb();
				if (x < probBracket1[1][i*2])
				{
					homeFG++;
					if (watch == true)
					{
						cout << "FIELD GOAL" << endl;
					}
				}
				else 
				{
					if (watch == true)
					{
						cout << "NO SCORE" << endl;
					}
					break;//Where does this break to?
				}
			}

			if (watch == true)
			{

				cout << bracket1[(i*2)+1] << "'s ball ~~~ ;"
			}
			randProb();
			if (x < probBracket1[0][(i*2)+1])
			{
				awayTD++;
				if (watch == true)
					{
						cout << "TOUCHDOWN" << endl;
					}
			}
			else
			{
				randProb();
				if (x < probBracket1[1][(i*2)+1])
				{
					awayFG++;
					if (watch == true)
					{
						cout << "FIELD GOAL" << endl;
					}
				}
				else
				{
					if (watch == true)
					{
						cout << "NO SCORE" << endl;
					}
					break;
				}
			}
		}

		//Compare team scores
		homeScore = (homeTD*7)+(homeFG*3);
		awayScore = (awayTD*7)+(awayFG*3);

		if (homeScore > awayScore)
		{
			cout << bracket1[i*2] << " beat the " << bracket1[(i*2)+1] << homeScore << " to " << awayScore << endl << endl;
			inPlay[(i*2)+1] = true;

		}

		else if (awayScore > homeScore)
		{
			cout << bracket1[(i*2)+1] << " beat the " << bracket1[i*2] << awayScore << " to " << homeScore << endl << endl;
			inPlay[i*2] = true;
		}

		else if (homeScore == awayScore)
		{
			//overtime(watch, i);
		}

	}
	//Creates bracket 2

	//Saves all statistics to new array to use in the end

}
/*
void overtime(bool watch, int i)
{
	while (homeScore == awayScore)
	{
		if (watch == true)
				{
					cout << bracket1[i*2] << "'s ball ~~~ ";
				}

				randProb();
				if (x < probBracket1[0][i*2])
				{
					homeTD++;
					if (watch == true)
					{
					cout << "TOUCHDOWN" << endl;
					}
				}
				else 
				{
					randProb();
					if (x < probBracket1[1][i*2])
					{
						homeFG++;
						if (watch == true)
						{
							cout << "FIELD GOAL" << endl;
						}
					}
					else 
					{
						if (watch == true)
						{
							cout << "NO SCORE" << endl;
						}
						break;//Where does this break to?
					}
				}

				if (watch == true)
				{

					cout << bracket1[(i*2)+1] << "'s ball ~~~ ;"
				}
				randProb();
				if (x < probBracket1[0][(i*2)+1])
				{
					awayTD++;
					if (watch == true)
						{
							cout << "TOUCHDOWN" << endl;
						}
				}
				else
				{
					randProb();
					if (x < probBracket1[1][(i*2)+1])
					{
						awayFG++;
						if (watch == true)
						{
							cout << "FIELD GOAL" << endl;
						}
					}
					else
					{
						if (watch == true)
						{
							cout << "NO SCORE" << endl;
						}
						break;
					}
				}
			}

			//Compare team scores
			homeScore = (homeTD*7)+(homeFG*3);
			awayScore = (awayTD*7)+(awayFG*3);

			if (homeScore > awayScore)
			{
				cout << bracket1[i*2] << " beat the " << bracket1[(i*2)+1] << homeScore << " to " << awayScore << endl << endl;
				inPlay[(i*2)+1] = true;

			}

			else if (awayScore > homeScore)
			{
				cout << bracket1[(i*2)+1] << " beat the " << bracket1[i*2] << awayScore << " to " << homeScore << endl << endl;
				inPlay[i*2] = true;
			}

*/
}



