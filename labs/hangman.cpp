// hangman.cpp
// Hangman game illustrates string library functions, 
// character arrays, arrays of pointers, etc.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

// Prototype
int processGuess(char* word, const char* targetWord, char guess);

// Define an array of strings (since a string is just a char array)
//  and since string are just char *'s, we really want an array of char *'s
char *wordBank[] = {"computer","president","trojan","program","coffee",
			  "library","football","popcorn","science","engineer"};

const int numWords = 10;
int numTurns = 10;
int targetLen;

int main()
{
  srand(time(0));
  char guess;
  bool wordGuessed = false;

  // Pick a random word from the wordBank
  char* targetWord = wordBank[rand()%10];

  // More initialization code as needed
  char word[80];  // a blank array to use to build up the answer
  for (int i = 0; i < 80; i++)
  {
    word[i] = '*';//Fills array with * to be changed when user guesses correct letter
  } 
  //Determine how many characters target word is
  targetLen = strlen(targetWord);              




  
  // An individual game continues until a word
  //  is guessed correctly or 10 turns have elapsed
  while (wordGuessed == false && numTurns > 0)
  {
    cout << "Current word: " ;
    for (int i = 0; i < targetLen; i++){
      cout << word[i];
    }
    cout << endl;
    cout << numTurns << " turns remaining...Enter a letter to guess: " << endl;
    cin >> guess;

    processGuess(word, targetWord, guess);

    for (int i = 0; i < targetLen; i++){
      if (word[i] != targetWord[i]){
        break;
      }
      if (i == targetLen-1){
        wordGuessed = true;
      }
    }

  }




  // Print out end of game status
  if (wordGuessed == true){
    cout << "The word was: ";
    for (int i = 0; i < targetLen; i++){
      cout << word[i];
    }
    cout << ". You win!" << endl;
  }
  else{
    cout << "Too many turns...you lost." << endl;
  }


    
  return 0;
}

// Given the current version of the word, target/selected word, and
// the character that the user just guessed, change the word to 
// "turn on" any occurrences the guess character and return a count
// of how many occurrences of 'guess' were found
int processGuess(char* word, const char* targetWord, char guess)
{
  int occurence = 0;
  for (int i = 0; i < targetLen; i++){
    if (guess == targetWord[i]){
      word[i] = guess;
      occurence++;
      
    }

    
  }
  if (occurence == 0){
    numTurns--;
  }
  
  
}