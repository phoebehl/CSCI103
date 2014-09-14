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





int main()
{
	char ans;
	bool watch=0;

	srand(time(0));
	//readText();
	bracketShuffle();

	//for ( int i = 0; i < 3; i++ ){

		printBracket();
		//Input if want to watch
		cout << "Wanna watch this round? (Answer y/n)" << endl;
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
		if (ans == 'n') {
		watch = false;
		}

		//Play round 1
		pInPlay = &inPlay[0];
		pInPlay2 = &inPlay[1];
		home = &bracket1[0];
		away = &bracket1[1];
		phomeTD = &probBracket1[0][0];
		phomeFG = &probBracket1[1][0];
		pawayTD = &probBracket1[0][1];
		pawayFG = &probBracket1[1][1];
		play(watch, home, away, phomeTD, phomeFG, pawayTD, pawayFG, pInPlay, pInPlay2);

		pInPlay = &inPlay[2];
		pInPlay2 = &inPlay[3];
		home = &bracket1[2];
		away = &bracket1[3];
		phomeTD = &probBracket1[0][2];
		phomeFG = &probBracket1[1][2];
		pawayTD = &probBracket1[0][3];
		pawayFG = &probBracket1[1][3];
		play(watch, home, away, phomeTD, phomeFG, pawayTD, pawayFG, pInPlay, pInPlay2);

		pInPlay = &inPlay[4];
		pInPlay2 = &inPlay[5];
		home = &bracket1[4];
		away = &bracket1[5];
		phomeTD = &probBracket1[0][4];
		phomeFG = &probBracket1[1][4];
		pawayTD = &probBracket1[0][5];
		pawayFG = &probBracket1[1][5];
		play(watch, home, away, phomeTD, phomeFG, pawayTD, pawayFG, pInPlay, pInPlay2);

		pInPlay = &inPlay[6];
		pInPlay2 = &inPlay[7];
		home = &bracket1[6];
		away = &bracket1[7];
		phomeTD = &probBracket1[0][6];
		phomeFG = &probBracket1[1][6];
		pawayTD = &probBracket1[0][7];
		pawayFG = &probBracket1[1][7];
		play(watch, home, away, phomeTD, phomeFG, pawayTD, pawayFG, pInPlay, pInPlay2);

		//Create bracket 2 for next round
		for (int i = 0; i<8; i++)
		{
			if (inPlay[i] == 0)
			{
				cout << inPlay[i] << " " << i << endl;
			}
		}
		

		//Play round 2

	//}


}

int readText()
{

  int i,j,k,l;
  int visited[8] = {0,0,0,0,0,0,0,0};
  int PlayOrder[8];
  string TeamName[8], TeamName_1st[8];           //1st --> in random order; 
  string input_file_name;
  double TouchDown_Prob[8], TouchDown_Prob_1st[8];
  double FieldGoal_Prob[8], FieldGoal_Prob_1st[8];
  int counter = 0;
  double value;
  char buffer[100];
  char *token;
  //My variables


  // use a stringstream to extract a double value from the buffer
  stringstream ss;

  // load the file into ifstream
  ifstream file ("Input.txt");
  // if the file opened correctly, start reading it
  if (file.is_open())
  {
    // while there are lines to read in the file, read them into the buffer one by one
    for (intk=0;k<8;k++)
    {
      file.getline(buffer, 100);
      counter = 0;
      // use strtok to pull out the first comma-delimited string from the buffer
      token = strtok(buffer,",");
      
      // while the token is not null, parse it
      while (token)
      {
	/* print out the string so we know it's working
	   cout << token << endl; */
	if(counter == 0)
	{
	  TeamName[k] = token;
	}
	else if (counter == 1)  
	{
	  // convert the string to a double
          value = atof (token);
          TouchDown_Prob[k] = value;
        }
        else if (counter == 2)  
	{
	  // convert the string to a double
	  value = atof (token);
          FieldGoal_Prob[k] = value;
	}
	// read a new comma-delimited string                       figure out what this does******
	token = strtok(NULL, ",");
	counter++;
      }
    
    }
    file.close();
}
}

void bracketShuffle()
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
	}
}


int printBracket()
{	
	string* pHome = &bracket1[0];
	string* pAway = &bracket1[1];
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

}

double randProb()
{
	double x = (rand()%101)/100.0;
	return x;

}


void play(bool watch, string* home, string* away, double* phomeTD, double* phomeFG, double* pawayTD, double* pawayFG, bool* pInPlay, bool* pInPlay2)
//Plays one game between two teams to be specified by pointers
{
	//Local Variables

	//Who's playing and their probabilities
	string homeName = *home;
	string awayName = *away;
	double homeTDProb = *phomeTD;
	double homeFGProb = *phomeFG;
	double awayTDProb = *pawayTD;
	double awayFGProb = *pawayFG;

	//Counters
	int homeScore = 0;
	int homeTD = 0;
	int homeFG = 0;
	int awayScore = 0;
	int awayTD = 0;
	int awayFG = 0;
	int otCount = 0;

	cout << "GAME " << count << " - " << homeName << " vs " << awayName  << endl;
	cout << "------" << endl << endl;
	count++;

		

		//Teams 1 and 2 play for 4 quarters
		for (int j = 0; j < 4; j++)
		{

			if (watch==true)
			{
				cout << "QUARTER " << j+1 << endl;
				cout << homeName << "'s ball ~ ";
			}

			prob = randProb();
			if (prob < homeTDProb)
			{
				homeTD++;
				if (watch==true)
				{
				cout << "TOUCHDOWN" << endl;
				}
			}
			else 
			{
				prob = randProb();
				if (prob< homeFGProb)
				{
					homeFG++;
					if (watch==true)
					{
						cout << "FIELD GOAL" << endl;
					}
				}
				else 
				{
					if (watch==true)
					{
						cout << "NO SCORE" << endl;
					}
				}
			}

			if (watch==true)
			{

				cout << awayName << "'s ball ~ ";
			}

			prob = randProb();
			if (prob < awayTDProb)
			{
				awayTD++;
				if (watch==true)
					{
						cout << "TOUCHDOWN" << endl << endl;
					}
			}
			else
			{
				prob = randProb();
				if (prob < awayFGProb)
				{
					awayFG++;
					if (watch==true)
					{
						cout << "FIELD GOAL" << endl << endl;
					}
				}
				else
				{
					if (watch==true)
					{
						cout << "NO SCORE" << endl << endl;
					}
				}
			}
		}
		

		//Compare team scores
		homeScore = (homeTD*7)+(homeFG*3);
		awayScore = (awayTD*7)+(awayFG*3);

		if (homeScore > awayScore)//Team 1 wins
		{
			cout << homeName << " beat the " << awayName << " " << homeScore << " - " << awayScore << endl << endl;
			*pInPlay2 = true;

		}

		else if (awayScore > homeScore)//Team 2 wins
		{
			cout << awayName << " beat the " << homeName << " " << awayScore << " - " << homeScore << endl << endl;
			*pInPlay = true;
		}

		else //Overtime
		{

			while (awayScore == homeScore)
			{
				otCount++;
				if (watch==true)
				{
					cout << "Both teams are tied with " << homeScore << " points...OVERTIME " << otCount << endl << endl;
					cout << homeName << "'s ball ~ ";
				}
				//Team 1's posession
				prob = randProb();
				if (prob < homeTDProb)
				{
					homeTD++;
					if (watch==true)
					{
					cout << "TOUCHDOWN" << endl;
					}
				}
				else 
				{
					prob = randProb();
					if (prob < homeFGProb)
					{
						homeFG++;
						if (watch==true)
						{
							cout << "FIELD GOAL" << endl;
						}
					}
					else 
					{
						if (watch==true)
						{
							cout << "NO SCORE" << endl;
						}
					}
				}

				//Team 2's posession
				if (watch==true)
				{

					cout << awayName << "'s ball ~ ";
				}

				prob = randProb();
				if (prob < awayTDProb)
				{
					awayTD++;
					if (watch==true)
						{
							cout << "TOUCHDOWN" << endl;
						}
				}
				else
				{
					prob = randProb();
					if (prob < awayFGProb)
					{
						awayFG++;
						if (watch==true)
						{
							cout << "FIELD GOAL" << endl << endl;
						}
					}
					else
					{
						if (watch==true)
						{
							cout << "NO SCORE" << endl << endl;
						}
					}
				}
				//Compare scores
				homeScore = (homeTD*7)+(homeFG*3);
				awayScore = (awayTD*7)+(awayFG*3);

				if (homeScore > awayScore)//Team 1 wins
				{
					cout << homeName << " beat the " << awayName << " " << homeScore << " - " << awayScore << endl << endl;
					*pInPlay2 = true;

				}

				else if (awayScore > homeScore)//Team 2 wins
				{
					cout << awayName << " beat the " << homeName << " " << awayScore << " - " << homeScore << endl << endl;
					*pInPlay = true;
				}

			}
			
		}
		//Save counters to some kind of stats array
	
}