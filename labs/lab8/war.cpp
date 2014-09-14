#include <iostream>
#include <cstdlib>
#include <ctime>
#include "deck.h"
#include "card.h"
#include "warplayer.h"

using namespace std;

int main(int argc, char* argv[])
{
  if(argc < 3){
    cout << "Provide number of games to simulate and 1=debug, 0=no debug " << endl;
    return 1;
  }
  srand(time(0));
  int numSims = atoi(argv[1]);
  bool debug = atoi(argv[2]);
  int numBattles = 0;
  int numWars = 0;
  int p1Wins = 0;
  int p2Wins = 0;
  for(int i=0; i < numSims; i++){

    // Write your single game of War code here (or decompose 
    // the single game into smaller functions that you write)
    // We've started things for you

    // Declare and prepare your deck then print it out to double check
    Deck d;
    d.shuffle();
    d.cut();
    
    if(debug){
      d.printDeck();
    }
    
    // Declare the two players and deal the cards to the two players
    WarPlayer player1;
    WarPlayer player2;

    for (int i = 0; i < 26; i++)
    {
      Card c = d.getTop();
      player1.addCard(c);
      c = d.getTop();
      player2.addCard(c);

    }
    //Start playing game
    while (player1.noCards() == false && player2.noCards() == false)
    {

      // Write a loop that plays one turn at a time, until the game is over
      // Remember each player takes their top card, compares them, and the
      //  player with the greater-valued card gets back both
      // If there is a tie, each player flips one more card (provided they have
      //  one more), with the player with the greater-valued 2nd card getting
      //  all the cards.  If they don't have one more to flip, that player 
      //  immediately loses
      Card played = player1.removeTopCard();
      Card other = player2.removeTopCard();
      numBattles++;

      if (played.compare(other) == -1)
      {
        //Add back both cards to player 2
        Card c = played;
        player2.addCard(c);
        c = other;
        player2.addCard(c);
        cout << "Player 2 wins this hand." << endl;
        cout << "Player 2 now has " << player2.deckSize() << " cards." << endl;
        cout << "Player 1 now has " << player1.deckSize() << " cards." << endl << endl;
        p2Wins++;

      }
      else if(played.compare(other) == 1)
      {
        //Add back both cards to player 1
        Card c = other;
        player1.addCard(c);
        c = played;
        player1.addCard(c);
        cout << "Player 1 wins this hand." << endl;
        cout << "Player 2 now has " << player2.deckSize() << " cards." << endl;
        cout << "Player 1 now has " << player1.deckSize() << " cards." << endl << endl;
        p1Wins++;
        //Check if game is over
      }
      else 
      {
        cout << "WARRRRR!" << endl;
        int currentWars = 0;
        Card *warCards = new Card[50];
        //warCards[0] = played;
        //warCards[1] = other;
        while (played.compare(other) == 0)//Stay in war while cards are the same
        {
          warCards[currentWars*4] = played;
          warCards[(currentWars*4)+1] = other;
          if (player1.deckSize() < 2) 
          {
            cout << "Player 1 does not have enough cards to war, so player 2 wins." << endl;
            break;
          }
          else if (player2.deckSize() < 2)//Same for Player 2
          {
            cout << "Player 2 does not have enough cards to war, so player 2 wins." << endl;
            break;
          }
          else //Both players have enough cards to war. Save cards to lay down in array warCards, then compare the next cards.
          {
            numWars++;
            currentWars++;
            warCards[(currentWars*4)-2] = player1.removeTopCard();
            warCards[(currentWars*4)-1] = player2.removeTopCard();
            played = player1.removeTopCard();
            other = player2.removeTopCard();

            if (played.compare(other) == -1)
            {
              //Add back both cards to player 2
              cout << "Player 2 wins this war." << endl;
              Card c = played;
              player2.addCard(c);
              c = other;
              player2.addCard(c);
              for (int i = 0; i < (currentWars*4)-1; i++)
              {
                c = warCards[i];
                player2.addCard(c);

              }
              cout << "Player 2 now has " << player2.deckSize() << " cards." << endl;
              cout << "Player 1 now has " << player1.deckSize() << " cards." << endl << endl;
              p2Wins++;

            }
            else if(played.compare(other) == 1)
            {
              //Add back both cards to player 1
              cout << "Player 1 wins this war." << endl;
              Card c = other;
              player1.addCard(c);
              c = played;
              player1.addCard(c);
              
              for (int i = 0; i < (currentWars*4)-1; i++)
              {
                c = warCards[i];
                player1.addCard(c);

              }
              cout << "Player 2 now has " << player2.deckSize() << " cards." << endl;
              cout << "Player 1 now has " << player1.deckSize() << " cards." << endl << endl;
              p1Wins++;
            }
            else
            {
              break;
            }
            
          }
        }//End of staying in war
      }//End of intial war

      // Be sure to update the statistics variables, numBattles, numWars,
      //  p1Wins, p2Wins, etc.


    }//End of While

    //Check if game is over
      if (player1.noCards() == true)
      {
        cout << "Player 2 wins the game." << endl;

      }
      else if (player2.noCards() == true)
      {
        cout << "Player 1 wins the game." << endl;
      }

  } // end for
  // Print statistics
  cout << "Total Battles = " << static_cast<double>(numBattles)/numSims << endl;
  cout << "Total Wars = " << static_cast<double>(numWars)/numSims << endl;
  cout << "P1 wins = " << p1Wins << endl;
  cout << "P2 wins = " << p2Wins << endl;
  return 0;
}
