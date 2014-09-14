#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main(){

  srand(time(0));

  int guess;
  int secretNum;
  char response;

  guess = 0;

  while ( true ) {
    response = 'n';
  secretNum = rand() % 20;

  for ( int i=0; i < 5; i++ ){
    cout << "Enter your guess: ";
    cin >> guess;
    if (guess > secretNum) {
      cout << "Your guess is too high." << endl;
    } else if (guess < secretNum) {
      cout << "Your guess is too low." << endl;
    } else {
      cout << "You win!" << endl;
     
    cout << "To play agan, enter an uppercase Y: ";
    cin >> response;
    }

    if ( response == 'Y' ) {
      break;
    } else {
      return 0;
    }
   
  } //end of for loop

  if (response == 'Y' ) {
    //user won and wants to play again
    continue;
  }

  //User has lost if we get here
  cout << "You lost." << endl;

  cout << "To play agan, enter an uppercase Y: ";
  cin >> response;

    if ( response != 'Y' ) { 

} //end of while loop
return 0;
  
}
}
