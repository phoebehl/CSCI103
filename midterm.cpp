//Sorting doesn't work, is commented out

#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

struct Team
{
	string name1;
	string name2;
	int wins;
	int losses;
};

//Gobal Variables
int numTeams = 0;

int main()
{

	fstream fin;
	stringstream ss;
	string name;
	string temp;
	string lines[100];

	cout << "Enter the name of your text file: " << endl;
	cin >> name;
	fin.open(name.c_str());

	while (fin.fail())
	{
		cin.ignore(10000, '\n');
		cin.clear();
		cout << "Sorry, there was an error opening your file. Please enter the name again: " << endl;
		cin >> name;
		fin.open(name.c_str());

	}

	getline(fin, temp);

	if (fin.fail())
	{
		cout << "Your file is improperly formatted." << endl;
		exit(EXIT_FAILURE);
	}


	while (!fin.fail() && temp.size() != 0)
	{
		lines[numTeams] = temp;
		numTeams++;
		getline(fin, temp);//Read another line in
	}

	//Dynamically allocate array of teams
	Team *teams = new Team[numTeams];
	//Populate array of teams
	for (int i = 0; i < numTeams; i++)
	{
		ss << lines[i];
		ss >> teams[i].name1 >> teams[i].name2 >> teams[i].wins >> teams[i].losses;

		if (ss.fail())
		{
			cout << "Your file is improperly formatted." << endl;
			exit(EXIT_FAILURE);
		}
		ss.clear();
	}
	//Error checking
	for (int i = 0; i < numTeams; i++)
	{
		cout << teams[i].name1 << " " << teams[i].name2 << endl;
		cout << teams[i].wins << endl;
		cout << teams[i].losses << endl;
	}

	//sort and print;
/*
	int *highWin;
	&highWin = &teams[0].wins;
	int *winCmp;
	&winCmp = &teams[1].wins;
	Team order[numTeams];
	int j = 0;

	for (int i = 0; i < numTeams; i++)
	{
		if (*highWin > *winCmp)
		{
			&winCmp = teams[i+2];

		}

		else if (*highWin < *winCmp)
		{
			//Moves the first team's data into temporary Team variable
			buffer.name1 = teams[j].name1;
			buffer.name2 = teams[j].name2;
			buffer.wins = teams[j].wins;
			buffer.losses = teams[j].losses;

			//Switches team 2's data into team 1's position
			teams[j].name1 = teams[i].name1;
			teams[j].name2 = teams[i].name2;
			teams[j].wins = teams[i].wins;
			teams[j].losses = teams[i].losses;

			//Puts team 1's data back into the second position
			teams[i].name1 = buffer.name1;
			teams[i].name2 = buffer.name2;
			teams[i].wins = buffer.wins;
			teams[i].losses = buffer.losses;

		}

	}//Done sorting array
*/
	//Print sorted array
	for (int i = 0; i < numTeams; i++)
	{
		cout << teams[i].name1 << " " << teams[i].name2 << ": " << teams[i].wins << " " << teams[i].losses << endl;
	}



	//Have user prompt for a team name and display their wins/losses
	string firstName;
	string secondName;

	cout << "Enter a team name: " << endl;
	cin >> firstName >> secondName;

	while (!cin.fail() && firstName.size() != 0)
	{

		for (int i = 0; i < numTeams; i++)
		{
			if (firstName == teams[i].name1)
			{
				cout << teams[i].name1 << " " << teams[i].name2 << " has " << teams[i].wins << " wins and " << teams[i].losses << " losses." << endl;
				break;
			}

			if (i == numTeams-1)
			{
				cout << "That team was not found" << endl;
				break;
			}

		}

		cin.ignore(10000, '\n');
		cin.clear();
		cout << "Enter a team name: " << endl;
		cin >> firstName >> secondName;
	}



	//Display total wins and losses
	int totWins = 0;
	int totLosses = 0;
	for(int i = 0; i < numTeams; i++)
	{
		totWins += teams[i].wins;
		totLosses += teams[i].losses;
	}

	cout << "Wins: " << totWins << " Losses: " << totLosses << endl;

return 0;
}

