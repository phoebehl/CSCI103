#ifndef ACTION_H
#define ACTION_H

#include <string.h>

using namespace std;

class Action
{
public:
	Action();
	//void setAction();
	string getText(int j);

private:
	string _text[3];//3 lines of text to describe action
};

#endif