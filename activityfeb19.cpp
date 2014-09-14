#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void createNumbers( int* values, int size){
	//Generate 'size' random numbers and sstore in 'values'
	int *a = new int;
	for (int i = 0; i < size; i++) 
	{	
		values[i] = rand()% 100;

	}
	delete a;

}


int main(){
	/*
	prompt the user for the num of rand values between 0 and 99 to generate. pass prompted value to a function. function generates that many rand values.

	back in main, compute average of all rand values and output average. is it close to 50?
	*/

	int count;
	srand(time(0));
	cout <<"Enter the num of rand values to be created: ";
	cin>> count;
	int* myArray = new int[count];

	createNumbers( myArray, count );

	int sum = 0;
	for (int i = 0; i < count; i++)
	{
		sum += myArray[i];
	}

	double average = (double)sum/count;

	cout << "the average of your" << count << "numbers is" << << average << endl;
	delete [] myArray;
	return 0;

}

int example2()
{
	char temp_buf [40];
	char* names [3];

	for (int i = 0; i < 3; i++ )
	{
		cin >> temp_buf;
		names[i] = temp_buf;

	}
	for (int i = 0; i < 3; i++)
	{
		cout << names[i] << endl;
	}
return 0;
}