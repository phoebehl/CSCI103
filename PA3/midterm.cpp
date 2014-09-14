#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>

using namespace std;

struct Team
{
	string name1;
	string name2;
	int wins;
	int losses;
};

//Prototypes
void readFile();
void sort();
int promptTeam();
int displayAll();

//Gobal Variables

int main()
{

}//End of main

void readFile()
{
	//Local variables
	fstream fin;
	string name;

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


}