// wscramble.cpp
// Word Scramble guessing game
// Illustrates string library functions, character arrays,
//  arrays of pointers, etc.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>

using namespace std;

// Prototype
void permute(char items[], int len);

// Define an array of strings (since a string is just a char array)
//  and since string are just char *'s, we really want an array of char *'s


int main(int argc, char* argv[])
{
//Read in textfile with word bank
  int numWords;
  int counter;
  char name[265];
  char**wordBank;

  if (argc!=2)
  {
    cout<< "Your input didn't work T_T" <<endl;
    return 1; 
  }

  else {

    fstream fin(argv[1]);

    if (fin.fail())
    {
      cout<< "Your file is invalid..." <<endl; 
      return 1;
    }
    else 
    {
      fin >> numWords;

      if (fin.fail())
      {
        cout << "The first line of your text file isn't an integer..." << endl;
        return 1;
      }
      else
      {
        cout << "There are " << numWords << " words in your text file." << endl;  
      }

      //Allocate array of char*s
      wordBank = new char*[numWords];
      char buffer[40];

      for (int i = 0; i < numWords; i++)
      {
        fin >> buffer;
        int len = strlen(buffer);
        wordBank[i] = new char[len+1];
        strcpy(wordBank[i], buffer);
      }
    }
  }


  srand(time(0));
  char guess[80];

  bool wordGuessed = false;
  int numTurns = 10;

  // Pick a random word from the wordBank
  int target = rand() % numWords;
  int targetLen = strlen(wordBank[target]);

  // More initialization code
  char* word = new char[targetLen+1];
  strcpy(word, wordBank[target]);
  permute(word, targetLen);
  
  // An individual game continues until a word
  //  is guessed correctly or 10 turns have elapsed
  while ( !wordGuessed && numTurns > 0 ){
    cout << "\nCurrent word:  " << word << endl;
    cin >> guess;
    wordGuessed = (strncmp(guess, wordBank[target], targetLen+1) == 0);
    numTurns--;
  }
  if(wordGuessed){
    cout << "You win!" << endl;
  }
  else {
    cout << "Too many turns...You lose!" << endl;
  }
  delete [] word;
  

  for(int i=0; i<numWords; i++)
  {
    delete [] wordBank[i];
  }
  delete [] wordBank;
  return 0;
}

// Scramble the letters
void permute(char items[], int len)
{
  for(int i=len-1; i > 0; --i){
    int r =  rand() % i;
    int temp = items[i];
    items[i] = items[r];
    items[r] = temp;
  }

}


