#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;
//Variables to make players' decks
int decks;
int allValues[260];
int allSuits[260];
int p1Values[260];
int p1Suits[260];
int p2Values[260];
int p2Suits[260];

//Variables tracking gameplay
int p1current;
int p2current;
int p1currentSuit;
int p2currentSuit;
int p1total;
int p2total;
const int cardsPerDeck = 52;

//Variables tracking statistics
float handsPlayed;
float warHands;
float p1wins;
float p2wins;
float p1warWins;
float p2warWins;
char watchAns;

//Function prototypes
void makeDeck(int decks); 
void shuffle();
void deal();
void draw();
void pop();
void tie();
int stats();

int main(){
  
  cout << "Enter a number of decks between 1 and 5 to be played with: " << endl;
  cin >> decks;

  cout << "Would you like to watch the game? Enter Y for yes or N for no: " << endl;
  cin >> watchAns;

  makeDeck(decks);  
  shuffle();
  deal();

  //Starts counters
  handsPlayed = 0;
  warHands = 0;
  p1wins = 0;
  p2wins = 0;
  p1warWins = 0;
  p2warWins = 0;

  while ( p1total != (decks*cardsPerDeck) && p2total != (decks*cardsPerDeck) ){ //Run until either player has all the cards
         
          draw();

	  if ( watchAns == 'Y' ){//Executes only if user wants to watch the game. Displays the card of each player.
	      cout << "Hand #: " << handsPlayed << endl << endl;
	      cout << "Player 1 now has " << p1total << " cards." << endl;
	      cout << "Player 2 now has " << p2total << " cards." << endl << endl;


	      if ( p1current != 0 && p1current != 10 && p1current != 11 && p1current != 12){ 
	         cout << "Player 1: " << (p1current+1) << " of ";

	         if (p1currentSuit == 0){
	  	    cout << "Spades" << endl;
	         }
	         else if (p1currentSuit == 1){
		    cout << "Clubs" << endl;
	         }
	         else if (p1currentSuit == 2){
		    cout << "Hearts" << endl;
	         }
	         else {
		    cout << "Diamonds" << endl;
	         }
	      }
	  
	  

	      else{ //Executes if card is an ace, jack, queen, or king
		if (p1current == 0) {
	            cout << "Player 1: Ace of ";
		 }
		else if (p1current == 10){
		    cout << "Player 1: Jack of "; 
		 }
		else if (p1current == 11){
		    cout << "Player 1: Queen of ";
		 }
		else {
		  cout << "Player 1: King of ";
		 }

		 //The next four if statements check and print what suit the card is.
		 if (p1currentSuit == 0){
		    cout << "Spades" << endl;
		 }
		 else if (p1currentSuit == 1){
		    cout << "Clubs" << endl;
		 }
		 else if (p1currentSuit == 2){
		    cout << "Hearts" << endl;
		 }
		 else {
		    cout << "Diamonds" << endl;
		 }
	      }
  


	      //Does the same thing for player 2's card
              if ( p2current != 0 && p2current != 10 && p2current != 11 && p2current != 12){ 
                 cout << "Player 2: " << (p2current+1) << " of ";
                 if (p2currentSuit == 0){
                    cout << "Spades" << endl;
                 }
                 else if (p2currentSuit == 1){
                    cout << "Clubs" << endl;
                 }
                 else if (p2currentSuit == 2){
                    cout << "Hearts" << endl;
                 }
                 else {
                    cout << "Diamonds" << endl;
                 }
              }
  

              else { //Executes if card is an ace, jack, queen, or king
		 if (p2current == 0){
      	            cout << "Player 2: Ace of ";
                 }
		 else if (p2current == 10){
	            cout << "Player 2: Jack of "; 
                 }
		 else if (p2current == 11){
	            cout << "Player 2: Queen of ";
                 }
		 else {
		   cout << "Player 2: King of ";
		 }
	      
                 //The next four if statements check and print what suit the card is.
                 if (p2currentSuit == 0){
		   cout << "Spades" << endl << endl;
                 }
                 else if (p2currentSuit == 1){
		   cout << "Clubs" << endl << endl;
                 }
                 else if (p2currentSuit == 2){
		   cout << "Hearts" << endl << endl;
                 }
                 else {
		   cout << "Diamonds" << endl << endl;
		 }
	      }


	      //Compare the cards to decide a winner
	      if ( p1current > p2current ){//P1 wins
		p1Values[p1total] = p1current;
 		p1Suits[p1total] = p1currentSuit;
		p1Values[p1total+1] = p2current;
		p1Suits[p1total+1] = p2currentSuit;
		cout << "p1total " << p1total<< endl;
		p1total = p1total + 2;
		cout << "p1total " << p1total<< endl;
		
		pop();
		cout << "Player 1 wins!" << endl << endl;

	      } 
	      else if ( p2current > p1current ){//P2 wins
	        p2Values[p2total] = p2current;
		p2Suits[p2total] = p2currentSuit;
		p2Values[p2total+1] = p1current;
		p2Suits[p2total+1] = p1currentSuit;
cout << "p2total" << p2total<< endl;
		p2total = p2total + 2;
		cout << "p2total" << p2total<< endl;

		pop();
		cout << "Player 2 wins!" << endl << endl;
	      }
	      else {//War
		tie();
	      }
	  }//End of watching game



	  else {//Not watching the game
              //Compare the cards to decide a winner
	      if ( p1current > p2current ){//P1 wins
		p1Values[p1total] = p1current;
		p1Suits[p1total] = p1currentSuit;
		p1Values[p1total+1] = p2current;
		p1Suits[p1total+1] = p2currentSuit;
		p1total++;
		p2total--;

		pop();
	      } 
	      else if ( p2current > p1current ){//P2 wins
	        p2Values[p2total] = p2current;
		p2Suits[p2total] = p2currentSuit;
		p2Values[p2total+1] = p1current;
		p2Suits[p2total+1] = p1currentSuit;
		p2total++;
		p1total--;
		
		pop();
	      }
	      else {//War
		tie();
	      }
	  }//End of not watching game
  }//End of while


  stats();//Returns game statistics   
  return 0;
  
}//end of main



void makeDeck(int decks){

 //Inserts 0-12 in value array and 0-3 representing suits in suit array
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

}//end of makeDeck



void shuffle(){
  
  int x;
  int tempVal;
  int tempSuit;
  
 
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

}//end of shuffle



void deal(){

  for (int i = 0; i < ((decks*cardsPerDeck)/2); i++){ //places odd indexes in player 2's deck, places even indexes in player 1's deck. Only fills half the size of player arrays.
    p1Values[i] = allValues[2*i];
    p1Suits[i] = allSuits[2*i];
    p2Values[i] = allValues[(2*i)+1];
    p2Suits[i] = allSuits[(2*i)+1];

   
  }
 
  //Establishes starting amount of cards each player has
  p1total = (decks*cardsPerDeck)/2;
  p2total = (decks*cardsPerDeck)/2;

  for (int i = p1total; i < 260; i++){
    p1Values[i] = -1;
    p2Values[i] = -1;
  }
 
}//End of deal



void pop(){
  for ( int i = 1; i < (decks*cardsPerDeck); i++){
    p1Values[i-1] = p1Values[i];
    p1Suits[i-1] = p1Suits[i];
    p2Values[i-1] = p2Values[i];
    p2Suits[i-1] = p2Suits[i];

  }
  p1total--;
  p2total--;
}

void draw(){
  handsPlayed++;
  p1current = p1Values[0];
  p1currentSuit = p1Suits[0];
  p2current = p2Values[0];
  p2currentSuit = p2Suits[0];

  //Moves all elements in player arrays one to the left
}//End of draw





void tie(){
  //In the case of a tie, players put down 3 cards and their 4th is compared.
  warHands++;//Increases counter every time tie() is called, does not increase if there are consecutive instances of war.

  int warValues [260];//Array stores the cards played during a war
  int warSuits [260];

 
  warValues[0] = p1current;
  warSuits[0] = p1currentSuit;
  warValues[1] = p2current;
  warSuits[1] = p2currentSuit;

 for (int i = 1; i < 4; i++){
    warValues[2*i] = p1Values[0];
    warSuits[2*i] = p1Suits[0];
    warValues[2*i+1] = p2Values[0];
    warSuits[2*i+1] = p2Suits[0];
    pop();
  }

 int count = 0;

  while (p1current == p2current){//Runs until players do not tie
    count++;
    p1current = p1Values[0];
    p1currentSuit = p1Suits[0];
    p2current = p2Values[0];
    p2currentSuit = p2Suits[0];
    
    warValues[count*8] = p1Values[0];
    warSuits[count*8] = p1Suits[0];
    warValues[count*8+1] = p2Values[0];
    warSuits[count*8+1] = p2Suits[0];
    pop();
   
   

    //Compares players' cards using saved values (p1current, p1currentSuit, etc)
    if ( watchAns == 'Y' ){//Executes only if user wants to watch the game. Displays the card of each player.

            cout << "WAR!" << endl << endl;
	    cout << "Player 1 places 3 cards down." << endl;
	    cout << "Player 2 places 3 cards down." << endl << endl;

	    if ( p1current != 0 && p1current != 10 && p1current != 11 && p1current != 12){ 
	         cout << "Player 1: " << (p1current+1) << " of ";

	         if (p1currentSuit == 0){
	  	    cout << " Spades" << endl;
	         }
	         else if (p1currentSuit == 1){
		    cout << " Clubs" << endl;
	         }
	         else if (p1currentSuit == 2){
		    cout << " Hearts" << endl;
	         }
	         else {
		    cout << " Diamonds" << endl;
		 }
	    }


	      else{ //Executes if card is an ace, jack, queen, or king
		if (p1current == 0) {
	            cout << "Player 1: Ace of ";
		 }
		else if (p1current == 10){
		    cout << "Player 1: Jack of "; 
		 }
		else if (p1current == 11){
		    cout << "Player 1: Queen of ";
		 }
		else {
		  cout << "Player 1: King of ";
		 }
		 //The next four if statements check and print what suit the card is.
		 if (p1currentSuit == 0){
		    cout << " Spades" << endl;
		 }
		 else if (p1currentSuit == 1){
		    cout << " Clubs" << endl;
		 }
		 else if (p1currentSuit == 2){
		    cout << " Hearts" << endl;
		 }
		 else {
		   cout << " Diamonds" << endl;
		 }
	      }
	
		 //Does the same thing for player 2
             if ( p2current != 0 && p2current != 10 && p2current != 11 && p2current != 12){ 
	         cout << "Player 2: " << (p2current+1) << " of ";

	         if (p2currentSuit == 0){
	  	    cout << " Spades" << endl;
	         }
	         else if (p2currentSuit == 1){
		    cout << " Clubs" << endl;
	         }
	         else if (p2currentSuit == 2){
		    cout << " Hearts" << endl;
	         }
	         else {
		    cout << " Diamonds" << endl;
	         }
	     }


	      else{ //Executes if card is an ace, jack, queen, or king
		if (p2current == 0) {
	            cout << "Player 1: Ace of ";
		 }
		else if (p2current == 10){
		    cout << "Player 1: Jack of "; 
		 }
		else if (p2current == 11){
		    cout << "Player 1: Queen of ";
		 }
		else {
		  cout << "Player 1: King of ";
		 }
		 //The next four if statements check and print what suit the card is.
		 if (p2currentSuit == 0){
		    cout << " Spades" << endl;
		 }
		 else if (p2currentSuit == 1){
		    cout << " Clubs" << endl;
		 }
		 else if (p2currentSuit == 2){
		    cout << " Hearts" << endl;
		 }
		 else {
		   cout << " Diamonds" << endl;
		 }
	      }
 

	      //Compare the cards to decide a winner
	      if ( p1current > p2current ){//P1 wins
		for (int i = 0; i < count*10; i++){
	 	    p1Suits[p1total+i] = warSuits[i];
		    p1Values[p1total+i] = warValues[i];
		}
		//adds cards in warValues to winner's deck
		p1total = p1total+(count*10);
	       
	       
	        cout << "Player 1 wins the war!" << endl << endl;

		p1warWins++;

	      }

	      else if ( p2current > p1current ){//P2 wins
		for (int i = 0; i < count*10; i++){
	            p2Suits[p2total+i] = warValues[i];
	  	    p2Values[p2total+i] = warSuits[i];
		}
	       
		p2total = p2total+(count*10);
		
	      
	  	cout << "Player 2 wins the war!" << endl << endl;
		
		p2warWins++;
	      }
	      else if(p1current == p2current){

		for (int i = 0; i < 3; i++){
		  warValues[count*10 + 2*i] = p1Values[0];
		  warSuits[count*10 + 2*i] = p1Suits[0];
		  warValues[count*10 + (2*i+1)] = p2Values[0];
		  warSuits[count*10 + (2*i+1)] = p2Suits[0];
		  pop();
		}

	      }

    }//End of watching game

 

    else { //Player doesn't watch the game
    //Compare the cards to decide a winner
	      if ( p1current > p2current ){//P1 wins
		for (int i = 0; i < 3; i++){
	 	    p1Suits[p1total+i] = warSuits[i];
		    p1Values[p1total+i] = warValues[i];
		}
		//adds 3 cards to the winner's total
		p1total = p1total+3;
		p2total = p2total-3;
		p1warWins++;
	      }


	      else if ( p2current > p1current ){//P2 wins
		for (int i = 0; i < 3; i++){
	            p2Suits[p2total+i] = warValues[i];
	  	    p2Values[p2total+i] = warSuits[i];
		}
		p2total = p2total+3;
		p1total = p1total-3;
		p2warWins++;
	      }

	      
    }//End of not watching game
  }//End of while loop
 
}//End of tie


int stats(){
  cout.precision(3);
  cout << "Statistics" << endl << endl;
  cout << "Number of hands: " << warHands+handsPlayed << endl;
  cout << "Number of hands won by Player 1: " << (p1wins+p1warWins) << " (" << (p1wins+p1warWins)/(warHands+handsPlayed)*100 << "%)" << endl;
  cout << "Number of hands won by Player 2: " << (p2wins+p2warWins) << " (" << (p2wins+p2warWins)/(warHands+handsPlayed)*100 << "%)" << endl;
  cout << "Number of war: " << warHands << endl;
  cout << "Number of wars won by Player 1: " << p1warWins << " (" << (p1warWins/warHands)*100 << "%)" << endl;
  cout << "Number of wars won by Player 2: " << p2warWins << " (" << (p2warWins/warHands)*100 << "%)" << endl;

  return 0;

}//End of stats
 

