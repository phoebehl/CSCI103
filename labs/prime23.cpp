#include <iostream>
#include <cmath>

using namespace std;
int main()
{

  //declare variables
  int number;
  int div2;
  int div3;
  int i2;
  int i3;

  i2 = 0;
  i3 = 0;

  //Prompt the user
  cout << "Enter an integer: ";

  //Get input
  cin >> number;

  //Do operations
  if ( number%2 != 0 && number%3 != 0) {
  cout << "No.\n"; //Case 4, neither is a factor
  }
  else {
    while ( number%2 == 0 || number%3 == 0 ){

       if ( number%2 == 0 ){ //Check if 2 is factor
       i2++;
       number =  number/2;
     
       } if ( number%3 == 0 ){ //Check if 3 is factor
       i3++;
      number = number/3;
       } 
  

    }//end of while
  cout << "Yes. Twos: " << i2 << " Threes: " << i3 << endl;
  }//end of else
  
}



