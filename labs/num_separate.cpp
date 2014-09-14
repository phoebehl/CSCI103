#include <iostream>
#include <cmath>

using namespace std;
int main(int argc, char *argv[])
{
  //Declare variables
  int number;
  int digit1;
  int digit10;
  int digit100;

  number = 0;
  digit1 = 0;
  digit10 = 0;
  digit100 = 0;

  //Prompt the user
  cout << "Enter your number:  ";

  //Get input
  cin >> number;


  //Do operations to separate number into its components
  digit1 = number%10;
  number = number - digit1;
  digit10 = (number%100)/10;
  number = number - digit10;
  digit100 = (number%1000)/100;

  //Print the result to the user
  cout << "1's digit is: " << digit1 << endl;
  cout << "10's digit is: " << digit10 << endl;
  cout << "100's digit is: " << digit100 << endl;

  //Finished
  return 0;

}
