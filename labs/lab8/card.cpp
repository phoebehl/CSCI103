#include <iostream>
#include <sstream>
#include <cstring>
#include "card.h"
using namespace std;

const char* cardVals[] = {"2","3","4", "5", "6", "7", "8", 
		  "9", "10", "J", "Q", "K", "A"};

Card::Card()
{
  _suit = 'C';
  _value = 0;
}

Card::Card(char suit, int value)
{
  _suit = suit;
  _value = value;
}

string Card::toString()
{
  string cardName;
  string tempVal;
  string tempSuit;

  stringstream ss;
  ss << _value;
  ss >> tempVal;
  ss.clear();

  ss << _suit;
  ss >> tempSuit;
  ss.clear();

  if (tempVal == "1")
  {
    cardName = 'A';
  }
  else if (tempVal == "11")
  {
    cardName = 'J';
  }
  else if (tempVal == "12")
  {
    cardName = 'Q';
  }
  else if (tempVal == "13")
  {
    cardName = 'K';
  }
  else
  {
    cardName = tempVal;
  }
  cardName.append("-");
  cardName.append(tempSuit);
  return cardName;
}


int Card::compare(Card other)
{
  if(_value < other._value){
    return -1;
  }
  else if(_value > other._value){
    return 1;
  }
  else {
    return 0;
  }
}
