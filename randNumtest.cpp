#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>

using namespace std;

double randNum();

//Variables


int main()
{
	srand(time(0));
	double j = randNum();

	if (j < 0.5)
	{
		cout << j;
		cout << "First time" << endl;

	}

	else
	{
		cout << j;
		cout << "Second case" << endl;
	}
 
 return 0;
	
}

double randNum()
{
	double x = (rand()%101)/100.0;
	return x;

	
}