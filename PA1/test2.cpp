#include <iostream>
#include <ctime> 
#include <cstdlib>

using namespace std;
int main(){

srand(time(0));

  int cardsPerDeck = 52;
  int decks = 3;
int player1[2][(cardsPerDeck*decks)];
int player2[2][(cardsPerDeck*decks)];

int allCards[2][(cardsPerDeck*decks)];
 for (int i = 0; i < (cardsPerDeck*decks); i){
    for (int j = 0; j < 13; j++){
      allCards[0][i] = j;
      i++;
    }
 }
 for (int i = 0; i < (cardsPerDeck*decks); i){
   for (int k = 0; k < 4; k++){
     for (int j = 0; j < 13; j++){
       allCards[1][i] = k;
      i++;
 
    }
   }
 }
 
  for (int i = 0; i < (cardsPerDeck*decks); i++ ){
    cout << allCards[0][i] << " ";
  }
  cout << endl;
  for (int i = 0; i < (cardsPerDeck*decks); i++ ){
    cout << allCards[1][i] << " ";
  }
  cout << endl;

  //Shuffle function
  int x;
  int tempVal;
  int tempSuit;
  
 
  for ( int i = 0; i < 6; i++){
    for ( int j = 0; j < (cardsPerDeck*decks); j++ ){
      x = (rand() % 52);
      tempVal = allCards[0][j];
      tempSuit = allCards[1][j];
      allCards[0][j] = allCards[0][x];
      allCards[1][j] = allCards[1][x];
      allCards[0][x] = tempVal;
      allCards[1][x] = tempSuit;
    }
  }  
  //end of shuffle function

 for (int i = 0; i < (cardsPerDeck*decks); i++ ){
    cout << allCards[0][i] << " ";
  }
  cout << endl;
  for (int i = 0; i < (cardsPerDeck*decks); i++ ){
    cout << allCards[1][i] << " ";
  }

  /*

 for (int i = 0; i < ((decks*cardsPerDeck)/2); i++){
    //places odd indexes in player 2's deck, places even indexes in player 1's deck. Only fills half the size of player arrays.
    player1[0][i] = allCards[0][2*i];
    player1[1][i] = allCards[1][2*i];
    player2[0][i] = allCards[0][(2*i)+1];
    player2[1][i] = allCards[1][(2*i)+1];
  }
  for (int i = (((decks*cardsPerDeck)/2)+1); i > ((decks*cardsPerDeck)/2) && i < (decks*cardsPerDeck); i++){
    //fills the rest of player arrays with zeros
     player1[0][i] = 0;
     player1[1][i] = 0;
     player2[0][i] = 0;
     player2[1][i] = 0;
  }

  for (int i = 0; i < (cardsPerDeck*decks); i++ ){
    cout << player1[0][i] << " ";
  }
  cout << endl;
  for (int i = 0; i < (cardsPerDeck*decks); i++ ){
    cout << player1[1][i] << " ";
  }
  cout << endl;
  /*
  for (int i = 0; i < (cardsPerDeck*decks); i++ ){
    cout << player2[0][i] << " ";
  }
  cout << endl;
  for (int i = 0; i < (cardsPerDeck*decks); i++ ){
    cout << player2[1][i] << " ";
  }
  */
  return 0;
 }

//make start at 1?


