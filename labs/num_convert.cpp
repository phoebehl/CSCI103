#include <iostream>
#include <cmath>

using namespace std;
int main(int argc, char *argv[])
{
  // Declare any other variables you need here
  // and/or delete the integer declared below 
  float Temp;
  float TempInCelsius;

  Temp = 0.0;
  TempInCelsius = 0.0;
  
  // Prompt the user
  cout << "Enter the temperature in Fahrenheit:  ";

  // get input  
  cin >> Temp;
  

  // Do some operations
  TempInCelsius = ((Temp - 32.00)/1.80);


  // Print the result to the user
  cout << "Your temperature in Celsius is " << TempInCelsius << endl;

  
  // You're done
  return 0;
  
}

