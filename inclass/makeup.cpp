#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

//Structs
struct Item
{
	string name;
	double price;
	int ordered;

};

//Prototypes
void printMenu();
void placeOrder();
void printOrder();


//Global variables
Item *menu;
int numLines = 0;
int numItems = 0;//Counts number of menu items

int main()
{
	fstream fin;
	stringstream ss;
	string name;//Stores name of the file
	string line;//Stores each line of the input file
	string allLines[100];//Takes a menu of max 100 items
	string tempName;


	//cout << "Please enter the file name with .txt at the end: ";
	//cin >> name;

	//fin.open(name.c_str());
	fin.open("input.txt");

	while (fin.fail())
	{
		fin.clear();
		cout << "You have entered an invalid file name. Please try again: ";
		cin >> name;
		fin.open(name.c_str());

	}
	//File successfully open, now read it
	getline(fin, line, '|');
	if (fin.fail())
	{
		cout << "Looks like your file is improperly formatted. The program will now exit.";
		return -1;
	}

	while (!fin.fail() && line.size() != 0)
	{
		allLines[numLines] = line;
		numLines++;
		getline(fin, line, '\n');
		allLines[numLines] = line;
		numLines++;
		getline(fin, line, '|');
		//if (fin.fail())
		//{
		//	cout << "Looks like your file is improperly formatted. The program will now exit.";
		//	return -1;
		//}

	}
	fin.close();
	//Done reading file, all the menu items are stored in a string array called allLines
	//Dynamically create array of item type Item
	menu = new Item[numLines/2];
	numItems = numLines/2;
	for (int i = 0; i < numLines; i++ )
	{
		if (i%2 == 0)
		{
			menu[i/2].name = allLines[i];
		
			//continue;
		}
		else
		{
			ss << allLines[i];
			ss >> menu[i/2].price;
			if (ss.fail())
			{
				cout << "There is something wrong with your file...the program will now exit.";
				return -1;
			}
			ss.clear();
		}

		

	}

	printMenu();
	placeOrder();

	return 0;

}

void printMenu()
{
	cout << "MENU" << endl << "____" << endl;
	for (int i =0; i < numItems; i++)
	{
		cout << i+1 << ". " << menu[i].name << "~" << menu[i].price << endl;
	}
}

void placeOrder()
{
	for (int i = 0; i < numItems; i++)
	{
		menu[i].ordered = 0;
	}

	string order = "AB";
	while (order != "\n")
	{
	cout << "Enter the number of the items you want, separated by spaces: ";
	cin >> order;

	//for (int i = 0; i < numItems; i++)
	
		//string search = i;
		//size_t found = order.find(search);
		//if (found != string::npos)
		{
		//	int a = menu[i].ordered;
		//	menu[i].ordered += a;
		}

	}
}

void printOrder()
{

}
