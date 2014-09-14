#ifndef ACTION_H
#define ACTION_H

#include <string.h>

using namespace std;

class Action
{
public:
	Action();
	Action(string input);
	void print_name();
	virtual void executeAction() = 0;
	/*
	void setAction(Action* a)
	*/

private:
	string _title;
	Action* action;

};

#endif