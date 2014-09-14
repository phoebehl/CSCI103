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
void bracketShuffle();
int printBracket();
double randProb();
void play(bool watch, string* home, string* away, double* phomeTD, double* phomeFG, double* pawayTD, double* pawayFG, bool* pInPlay, bool* pInPlay2);


//Variables
int count = 1; //for play() function
double prob; //for play() function, is probability to be compared to teams'
string* home;
string* away;
double* phomeTD;
double* phomeFG;
double* pawayTD;
double* pawayFG;
bool* pInPlay;
bool* pInPlay2;

bool inPlay[8] = {false};
string allTeams[8] = {"trojans", "bruins", "trees", "ducks", "cougars", "bears", "dogs", "fish"};
string bracket1[8];
string bracket2[4];
string bracket3[2];

double allProb[2][8] = {{0.80, 0.20, 0.60, 0.50, 0.40, 0.50, 0.80, 0.10}, {0.60, 0.30, 0.50, 0.40, 0.80, 0.10, 0.40, 0.90}};
double probBracket1[2][8];
double probBracket2[2][4];
double probBracket3[2][2];

//For printBracket()
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

	int y;
	string tempTeam;
	double tempTD;
	double tempFG;

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
		probBracket1[0][i] = allProb[0][i];
		probBracket1[1][i] = allProb[1][i];
		cout << probBracket1[0][i] << endl;
	}

}