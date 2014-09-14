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
bool ipWatch();
void play(string* home, string* away, double* phomeTD, double* phomeFG, double* pawayTD, double* pawayFG, bool* pInPlay, bool* pInPlay2);
/*
The function only plays through one game between two teams. In the main function, I reassign pointers to determine which teams
should be playing the next time play() is called. These assignments are made based on the inPlay bool array. When a team
loses, their corresponding index in inPlay is switched to true. Before choosing which teams will play, I first check if their
bool is true or false. If true, they will not move on to the second or final rounds. 
*/
void stats();

//Variables
bool watch = false;//for watch()
int count = 0; //for play() function
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
string allTeams[8];
string bracket1[8];
string bracket2[4] = {"GAME 1 W", "GAME 2 W", "GAME 3 W", "GAME 4 W"};
string bracket3[2] = {"GAME 5 W", "GAME 6 W"};

double allProb[2][8]; 
double probBracket1[2][8];
double probBracket2[2][4];
double probBracket3[2][2];

//For printBracket()
string* pHome;
string* pAway;

//Stats variables
int cumTD[2][8] = {0}; //Remember to cast as doubles later
int empty[2][8] = {0};//Only to fix memory allocation problems, not used in functions
int cumFG[2][8] = {0};
int empty2[2][8] = {0};//Only to fix memory allocation problems, not used in functions
int attTD[2][8] = {0};
int empty3[2][8] = {0};//Only to fix memory allocation problems, not used in functions
int attFG[2][8] = {0};

int main()
{
	srand(time(0));
	readText();
	bracketShuffle();
	printBracket();

	//Play round 1
	ipWatch();
	for (int i = 0; i < 4; i++)
	{
	pInPlay = &inPlay[i*2];
	pInPlay2 = &inPlay[(i*2)+1];
	home = &bracket1[i*2];
	away = &bracket1[(i*2)+1];
	phomeTD = &probBracket1[0][i*2];
	phomeFG = &probBracket1[1][i*2];
	pawayTD = &probBracket1[0][(i*2)+1];
	pawayFG = &probBracket1[1][(i*2)+1];

	play(home, away, phomeTD, phomeFG, pawayTD, pawayFG, pInPlay, pInPlay2);
	}
	stats();

	//Create bracket 2 for next round from winners of rd 1
	for (int j = 0; j < 4; )
	{
		for (int i = 0; i < 8; i++){

			if (inPlay[i] == false)
			{
				bracket2[j] = bracket1[i];
				probBracket2[0][j] = probBracket1[0][j];
				probBracket2[1][j] = probBracket1[1][j];
				j++;
			}
		}
	}

	printBracket();

	//Play round 2
	//Four loops are to find the first two indexes in inPlay[] that are still false. They will play against each other.
	for (int i = 0; i < 4; i++)
	{
		if (inPlay[i] == false)
		{
			pInPlay = &inPlay[i];

			for (int j = i; j < 4; j++)
			{
				if (inPlay[j] == false)
				{
					pInPlay2 = &inPlay[j];
				}
			}
		}
	}
	ipWatch();

	//Game 5
	home = &bracket2[0];
	away = &bracket2[1];
	phomeTD = &probBracket2[0][0];
	phomeFG = &probBracket2[1][0];
	pawayTD = &probBracket2[0][1];
	pawayFG = &probBracket2[1][1];
	play(home, away, phomeTD, phomeFG, pawayTD, pawayFG, pInPlay, pInPlay2);
	
	for (int i = 4; i < 8; i++)
	{
		if (inPlay[i] == false)
		{
			pInPlay = &inPlay[i];

			for (int j = i; j < 8; j++)
			{
				if (inPlay[j] == false)
				{
					pInPlay2 = &inPlay[j];
				}
			}
		}
	}
	home = &bracket2[2];
	away = &bracket2[3];
	phomeTD = &probBracket2[0][2];
	phomeFG = &probBracket2[1][2];
	pawayTD = &probBracket2[0][3];
	pawayFG = &probBracket2[1][3];
	play(home, away, phomeTD, phomeFG, pawayTD, pawayFG, pInPlay, pInPlay2);

	//Create bracket 3 for next round from winners of rd 2
	for (int j = 0; j < 2; )
	{
		for (int i = 0; i < 8; i++){

			if (inPlay[i] == false)
			{
				bracket3[j] = bracket1[i];
				probBracket3[0][j] = probBracket1[0][i];
				probBracket3[1][j] = probBracket1[1][i];
				j++;
			}
		}
	}
	printBracket();

	//Play final round, first sets pointers to teams in final and their probabilities
	for (int i = 0; i < 4; i++)
	{
		if (inPlay[i] == false)
		{
			pInPlay = &inPlay[i];

			for (int j = 4; j < 8; j++)
			{
				if (inPlay[j] == false)
				{
					pInPlay2 = &inPlay[j];
				}
			}
		}
	}
	ipWatch();
	home = &bracket3[0];
	away = &bracket3[1];
	phomeTD = &probBracket3[0][0];
	phomeFG = &probBracket3[1][0];
	pawayTD = &probBracket3[0][1];
	pawayFG = &probBracket3[1][1];
	play(home, away, phomeTD, phomeFG, pawayTD, pawayFG, pInPlay, pInPlay2);

	//Declare winner
	for (int i = 0; i < 8; i++)
	{
		if (inPlay[i] == false)
		{
			cout << bracket1[i] << " WIN THE CONFERENCE! Four for you, " << bracket1[i] << ". You go " << bracket1[i] << "." << endl << endl;
		}
	}

	//Print out TD and FG stat tables
	stats();

return 0;
}//End of main

int readText()
{
	//Local Variables
	char fileIn[265];
	int counter = 0;
	double value;
	char buffer[100];
	char *token;
	
	//Open file
	cout << "Enter the name of your file with '.txt' at the end: " << endl;
	cin.get(fileIn, 265);
	fstream teamList;
	teamList.open (fileIn);

	if (!teamList)
	{
		while (!teamList)
		{
	    	cout << "Hmm...can't find your file. Please enter it again: " << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			cin.get(fileIn, 265);
			teamList.open (fileIn);
		}
  	}

	// use a stringstream to extract a double value from the buffer
 	stringstream ss;
  	// if the file opened correctly, start reading it
  	if (teamList.is_open())
 	{
	    // while there are lines to read in the file, read them into the buffer one by one
	    for (int k = 0; k < 8; k ++)
	    {
		    teamList.getline(buffer, 100);
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
			 		 allTeams[k] = token;
				}

				else if (counter == 1)  
				{
			  		// convert the string to a double
		          	ss << token;
		          	ss >> value;
		          	if (value > 1 || value < 0)
		          	{
		          		cout << "Looks like your input file is improperly formatted...Please fix it and run the program again." << endl;
						exit(EXIT_FAILURE);
		          	}
		          	if (ss.fail())
		          	{
		          		cout << "Looks like your input file is improperly formatted...Please fix it and run the program again." << endl;
						exit(EXIT_FAILURE);
		          	}
		          	allProb[0][k] = value;
		          	ss.clear();
		        }

		        else if (counter == 2)  
				{
			  		// convert the string to a double
			  	  	ss << token;
			  	  	ss >> value;
			  	  	if (value > 1 || value < 0)
		          	{
		          		cout << "Looks like your input file is improperly formatted...Please fix it and run the program again." << endl;
						exit(EXIT_FAILURE);
		          	}
		          	if (ss.fail())
		          	{
		          		cout << "Looks like your input file is improperly formatted...Please fix it and run the program again." << endl;
						exit(EXIT_FAILURE);
		          	}
		          	allProb[1][k] = value;
		          	ss.clear();
				}

				else if (counter > 2)
				{
					cout << "Looks like your input file is improperly formatted...Please fix it and run the program again." << endl;
					exit(EXIT_FAILURE);
				}

				// read a new comma-delimited string 
				token = strtok(NULL, ",");
				counter++;
      	 	}
      	 	if (counter < 3)
      	 	{
      	 		cout << "Looks like your input file is improperly formatted...Please fix it and run the program again." << endl;
				exit(EXIT_FAILURE);
      	 	}
    	}
    }

    teamList.close();
	return 0;
}//end of readText

void bracketShuffle()
{
	//Local variables
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
}//End of bracketShuffle

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

}//end of printBracket

double randProb()
{
	double x = 0.0;
	x = (rand()%101)/100.0;
	return x;

}//end of randProb

bool ipWatch()
{
	//Local Variables
	char ans;

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
		return watch;
		
}//end of ipWatch

void play(string* home, string* away, double* phomeTD, double* phomeFG, double* pawayTD, double* pawayFG, bool* pInPlay, bool* pInPlay2)
{
	//Plays one game between two teams to be specified by pointers
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
	int homeTDtries = 0;
	int homeFGtries = 0;
	int awayScore = 0;
	int awayTD = 0;
	int awayFG = 0;
	int awayTDtries = 0;
	int awayFGtries = 0;
	int otCount = 0;

	cout << "------" << endl << "GAME " << count+1 << " - " << homeName << " vs " << awayName  << endl;
	cout << "------" << endl << endl;

	//"Home" team and "away" team play for 4 quarters
	for (int j = 0; j < 4; j++)
	{

		if (watch==true)
		{
			cout << "QUARTER " << j+1 << endl;
			cout << homeName << " ball ~ ";
		}
		homeTDtries++;
		if (randProb() < homeTDProb)
		{
			homeTD++;
			if (watch==true)
			{
			cout << "TOUCHDOWN" << endl;
			}
		}
		else 
		{
			homeFGtries++;
			if (randProb() < homeFGProb)
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
			cout << awayName << " ball ~ ";
		}
		awayTDtries++;
		if (randProb() < awayTDProb)
		{
			awayTD++;
			if (watch==true)
			{
				cout << "TOUCHDOWN" << endl << endl;
			}
		}
		else
		{
			awayFGtries++;
			if (randProb() < awayFGProb)
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
	}//End of for loop, 4 quarters

	//Compare team scores
	homeScore = (homeTD*7)+(homeFG*3);
	awayScore = (awayTD*7)+(awayFG*3);

	//If no overtime, then save counters
	if (homeScore != awayScore)
	{
		//Save counters to stats arrays (for first 4 games)
		if (count < 4)
		{
			cumFG[0][count*2] = homeFG;
			cumFG[0][(count*2)+1] = awayFG;
			cumTD[0][count*2] = homeTD;
			cumTD[0][(count*2)+1] = awayTD;
			attTD[0][count*2] = homeTDtries;
			attTD[0][(count*2)+1] = awayTDtries;
			attFG[0][(count*2)] = homeFGtries;
			attFG[0][(count*2)+1] = awayFGtries;
		}

		//For games in second round, must check which teams are still in play with inPlay[]
		else if (count > 3 && count < 6)
		{
			for (int i = 0; i < 8; i++)
			{
				if (inPlay[i] == false && i < 4)
				{
					cumTD[1][i] = homeTD;
					cumFG[1][i] = homeFG;
					attTD[1][i] = homeTDtries;
					attFG[1][i] = homeFGtries;
				}

				if (inPlay[i] == false && i > 3)
				{
					cumTD[1][i] = awayTD;
					cumFG[1][i] = awayFG;
					attTD[1][i] = awayTDtries;
					attFG[1][i] = awayFGtries;
				}
			}
		}
		//Same thing for games in final round
		else if (count > 5)
		{
			for (int i = 0; i < 8; i++)
			{
				if (inPlay[i] == false && i < 4)
				{
					cumTD[2][i] = homeTD;
					cumFG[2][i] = homeFG;
					attTD[2][i] = homeTDtries;
					attFG[2][i] = homeFGtries;
				}

				if (inPlay[i] == false && i > 3)
				{
					cumTD[2][i] = awayTD;
					cumFG[2][i] = awayFG;
					attTD[2][i] = awayTDtries;
					attFG[2][i] = awayFGtries;
				}
			}
		}
	}//End of saving stats for no overtime

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
				cout << homeName << " ball ~ ";
			}
			//Team 1's posession
			if (randProb() < homeTDProb)
			{
				homeTD++;
				if (watch==true)
				{
				cout << "TOUCHDOWN" << endl;
				}
			}
			else 
			{
				if (randProb() < homeFGProb)
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
					continue;
				}
			}
			//Team 2's posession
			if (watch==true)
			{
				cout << awayName << " ball ~ ";
			}
			if (randProb() < awayTDProb)
			{
				awayTD++;
				if (watch==true)
				{
					cout << "TOUCHDOWN" << endl;
				}
			}
			else
			{
				if (randProb() < awayFGProb)
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
					continue;
				}
			}

			//Compare scores to see if we stay in overtime
			homeScore = (homeTD*7)+(homeFG*3);
			awayScore = (awayTD*7)+(awayFG*3);

		}//End of while 

		//Save counters to stats arrays (for first 4 games)
		if (count < 4)
		{	
			cumFG[0][count*2] = homeFG;
			cumFG[0][(count*2)+1] = awayFG;
			cumTD[0][count*2] = homeTD;
			cumTD[0][(count*2)+1] = awayTD;
			attTD[0][count*2] = homeTDtries;
			attTD[0][(count*2)+1] = awayTDtries;
			attFG[0][(count*2)] = homeFGtries;
			attFG[0][(count*2)+1] = awayFGtries;
		}

		//For games in second round
		else if (count > 3 && count < 6)
		{
			for (int i = 0; i < 8; i++)
			{
				if (inPlay[i] == false && i < 4)
				{
					cumTD[1][i] = homeTD;
					cumFG[1][i] = homeFG;
					attTD[1][i] = homeTDtries;
					attFG[1][i] = homeFGtries;
				}

				if (inPlay[i] == false && i > 3)
				{
					cumTD[1][i] = awayTD;
					cumFG[1][i] = awayFG;
					attTD[1][i] = awayTDtries;
					attFG[1][i] = awayFGtries;
				}
			}
		}
		//For final round
		else if (count > 5)
		{
			for (int i = 0; i < 8; i++)
			{
				if (inPlay[i] == false && i < 4)
				{
					cumTD[2][i] = homeTD;
					cumFG[2][i] = homeFG;
					attTD[2][i] = homeTDtries;
					attFG[2][i] = homeFGtries;
				}

				if (inPlay[i] == false && i > 3)
				{
					cumTD[2][i] = awayTD;
					cumFG[2][i] = awayFG;
					attTD[2][i] = awayTDtries;
					attFG[2][i] = awayFGtries;
				}
			}
		}

		if (homeScore > awayScore)//Team 1 wins
		{
			cout << endl << homeName << " beat the " << awayName << " " << homeScore << " - " << awayScore << endl << endl;
			*pInPlay2 = true;
		}
		else if (awayScore > homeScore)//Team 2 wins
		{
			cout << endl << awayName << " beat the " << homeName << " " << awayScore << " - " << homeScore << endl << endl;
			*pInPlay = true;
		}
	}//end of else

	count++;
}//end of play

void stats()
{
	//Local variables
	int TD1 = 0;
	int attTD1 = 0;
	int TD2 = 0;
	int attTD2 = 0;
	int TD3 = 0;
	int attTD3 = 0;
	int FG1 = 0;
	int attFG1 = 0;
	int FG2 = 0;
	int attFG2 = 0;
	int FG3 = 0;
	int attFG3 = 0;
	double totDiff = 0.0;
	double totDiffFG = 0.0;
	
	cout << "TOUCHDOWNS TABLE" << endl;
	cout << "              ROUND #" << endl;
	cout << "Team      1     2     3   Total   %   Prob  Diff" << endl;
	cout << "----    ----- ----- ----- ----- ----- ----- -----" << endl;
	for (int i = 0; i < 8; i ++)
	{
		
		cout << setw(10) << left << bracket1[i] << cumTD[0][i] << "/" << setw(4) << attTD[0][i] << cumTD[1][i] << "/" << setw(4) << attTD[1][i];
		cout << cumTD[2][i] << "/" << setw(3) << attTD[2][i] << cumTD[0][i]+cumTD[1][i]+cumTD[2][i] << "/";
		cout << setw(4) << attTD[0][i]+attTD[1][i]+attTD[2][i];
		cout.precision(2);
		cout << setw(6) << (double)(cumTD[0][i]+cumTD[1][i]+cumTD[2][i])/(attTD[0][i]+attTD[1][i]+attTD[2][i]);
		cout << setw(6) << probBracket1[0][i];
		cout.precision(2);
		cout << (probBracket1[0][i]-((double)(cumTD[0][i]+cumTD[1][i]+cumTD[2][i])/(attTD[0][i]+attTD[1][i]+attTD[2][i]))) << endl;
	}
	cout << setw(9) << left << "TOTAL";
	for (int i = 0; i < 8; i++)
	{
		TD1 = TD1+cumTD[0][i];
		attTD1 = attTD1+attTD[0][i];
	}
	cout << TD1 << "/" << setw(4) << attTD1;
	for (int i = 0; i < 8; i++)
	{
		TD2 = TD2+cumTD[1][i];
		attTD2 = attTD2+attTD[1][i];
	}
	cout << TD2 << "/" << setw(3) << attTD2;
	for (int i = 0; i < 8; i++)
	{
		TD3 = TD3+cumTD[2][i];
		attTD3 = attTD3+attTD[2][i];
	}
	cout << TD3 << "/" << setw(3) << attTD3 << (TD1+TD2+TD3) << "/" << setw(16) << (attTD1+attTD2+attTD3);
	for (int i = 0; i < 8; i++)
	{
		totDiff = totDiff + ((probBracket1[0][i]-((double)(cumTD[0][i]+cumTD[1][i]+cumTD[2][i])/(attTD[0][i]+attTD[1][i]+attTD[2][i]))));
	}
	cout << totDiff << endl << endl;

	//Field goals table must also account for when 0 FGs were attempted, can't divide by 0
	cout << "FIELD GOALS TABLE" << endl;
	cout << "              ROUND #" << endl;
	cout << "Team      1     2     3   Total   %   Prob  Diff" << endl;
	cout << "----    ----- ----- ----- ----- ----- ----- -----" << endl;
	for (int i = 0; i < 8; i ++)
	{
		cout << setw(9) << left << bracket1[i] << cumFG[0][i] << "/" << setw(4) << attFG[0][i] << cumFG[1][i] << "/" << setw(4) << attFG[1][i];
		cout << cumFG[2][i] << "/" << setw(3) << attFG[2][i] << cumFG[0][i]+cumFG[1][i]+cumFG[2][i] << "/";
		cout << setw(4) << attFG[0][i]+attFG[1][i]+attFG[2][i];
		if ((attFG[0][i]+attFG[1][i]+attFG[2][i]) == 0)
		{
			cout << setw(6) << "0";
		}
		else
		{
			cout.precision(2);
			cout << setw(6) << (double)(cumFG[0][i]+cumFG[1][i]+cumFG[2][i])/(attFG[0][i]+attFG[1][i]+attFG[2][i]);
		}
		cout << setw(6) << probBracket1[1][i];
		if ((attFG[0][i]+attFG[1][i]+attFG[2][i]) == 0)
		{
			cout << probBracket1[1][i] << endl;
		}
		else
		{
			cout.precision(2);
			cout << probBracket1[1][i]-((double)cumFG[0][i]+cumFG[1][i]+cumFG[2][i])/(attFG[0][i]+attFG[1][i]+attFG[2][i]) << endl;
		}
		
	}
	cout << setw(8) << left << "TOTAL";
	for (int i = 0; i < 8; i++)
	{
		FG1 = FG1+cumFG[0][i];
		attFG1 = attFG1+attFG[0][i];
	}
	cout << FG1 << "/" << setw(4) << attFG1;
	for (int i = 0; i < 8; i++)
	{
		FG2 = FG2+cumFG[1][i];
		attFG2 = attFG2+attFG[1][i];
	}
	cout << FG2 << "/" << setw(4) << attFG2;
	for (int i = 0; i < 8; i++)
	{
		FG3 = FG3+cumFG[2][i];
		attFG3 = attFG3+attFG[2][i];
	}
	cout << FG3 << "/" << setw(3) << attFG3 << (FG1+FG2+FG3) << "/" << setw(15) << (attFG1+attFG2+attFG3);
	for (int i = 0; i < 8; i++)
	{
		if ((attFG[0][i]+attFG[1][i]+attFG[2][i])==0)
		{
			totDiffFG = totDiffFG;
		}
		else
		{
		totDiffFG = totDiffFG + (probBracket1[1][i]-((double)cumFG[0][i]+cumFG[1][i]+cumFG[2][i])/(attFG[0][i]+attFG[1][i]+attFG[2][i]));
		}
	}
	cout << totDiff << endl << endl;

	cout << endl << endl;
}
