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
void play(bool watch);


//Variables
string bracket1[8] = {"trojans", "trees", "numba1", "final", "still", "not", "done", "more"} ;
double probBracket1 [2][8];
string bracket2[4] = {"tean1", "next", "third", "last"};
string bracket3[2] = {"abcde", "other"};
string* pHome = &bracket1[0];
string* pAway = &bracket1[1];
char ans;



int main(){


	cout << "---------------" << endl;
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



	cout << "Feeling voyeuristic this round? (Answer y/n)" << endl;
		cin >> ans;
		while (ans != 'y' && ans != 'n'){
			cout << "Your answer was invalid...answer with y/n: " << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			cin >> ans;
		}

		cout << endl << endl;


}