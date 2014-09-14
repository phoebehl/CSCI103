#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;
int main(){
  srand(time(0));
 
  int cardsPerDeck = 52;
  int decks = 1;
  int allValues[260];
  int allSuits[260];
  int p1Values[260];
  int p1Suits[260];
  int p2Values[260];
  int p2Suits[260];
  int p1total;
  int p2total;
  /*
 for (int i = 0; i < (cardsPerDeck*decks); i++){
    for (int j = 0; j < 13; j++){
      allValues[j] = j;
      ;
    }
 }
  */
 for (int i=0; i< (decks);i++){
   for (int j=0; j< 52; j++){
     allValues[i + j] = j%13;
   }
 }

 for (int i = 0; i < (decks); i++){
   for (int k = 0; k < 4; k++){
     for (int j = 0; j < 13; j++){
       allSuits[i+k*13+j] = k;
     }
   }
 }

  for (int i = 0; i < 260; i++ ){
    cout << allValues[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < (cardsPerDeck*decks); i++ ){
    cout << allSuits[i] << " ";
  }
  cout << endl << endl;



 int x;
  int tempVal;
  int tempSuit;
  
  //Shuffle functioin
  for ( int i = 0; i < 6; i++){
    for ( int j = 0; j < (cardsPerDeck*decks); j++ ){
      x = (rand() % (cardsPerDeck*decks));
      tempVal = allValues[j];
      tempSuit = allSuits[j];
      allValues[j] = allValues[x];
      allSuits[j] = allSuits[x];
      allValues[x] = tempVal;
      allSuits[x] = tempSuit;
    }
  }


   for (int i = 0; i < (cardsPerDeck*decks); i++ ){
    cout << allValues[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < (cardsPerDeck*decks); i++ ){
    cout << allSuits[i] << " ";
  }

  cout << endl << endl;



  //Deal function
 for (int i = 0; i < ((decks*cardsPerDeck)/2); i++){ //places odd indexes in player 2's deck, places even indexes in player 1's deck. Only fills half the size of player arrays.
    p1Values[i] = allValues[2*i];
    p1Suits[i] = allSuits[2*i];
    p2Values[i] = allValues[(2*i)+1];
    p2Suits[i] = allSuits[(2*i)+1];
  }
  p1total = (decks*cardsPerDeck)/2;
  p2total = (decks*cardsPerDeck)/2;
 cout << "hi"<<endl;
 for (int i = p1total; i < 260; i++){
    p1Values[i] = 100;
    p2Values[i] = 100;
    
 }
 
  //Establishes starting amount of cards each player has

  cout << p1total << " P1total" << endl;

  for (int i = 0; i < 260; i++ ){
    cout << p1Values[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < 260; i++ ){
    cout << p1Suits[i] << " ";
  }
  cout << endl << endl;

 for (int i = 0; i < p2total; i++ ){
    cout << p2Values[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < p2total; i++ ){
    cout << p2Suits[i] << " ";
  }
 
}
