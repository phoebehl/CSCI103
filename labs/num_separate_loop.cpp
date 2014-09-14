#include <iostream>
#include <cmath>

using namespace std;
int main(int argc, char *argv[])
{
  //Declare variables
  int number;
  int digit;
  int iteration;

  number = 0;
  digit = 0;
  iteration = 1;
 

  //Prompt the user
  cout << "Enter your number:  ";

  //Get input
  cin >> number;


  //Do operations to separate number into its components
  while (number != 0) {

  digit = number%10;
  cout << iteration << "'s digit: " << digit << endl;
  iteration = iteration*10;
  number = (number-digit)/10;
  }

  //Finished
  return 0;

}
