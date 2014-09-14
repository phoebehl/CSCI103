#include <iostream>
//#include <cstring>
#include "action.h"

using namespace std;

Action::Action()
{
	_title = "empty";
}

Action::Action(string input)
{
	_title = input;

}

void Action::print_name()
{
	cout << "The name of the action is: " << _title << endl;
}

void Action::executeAction()
{
	cout << "in action executeAction" << endl;
}

/*
void setAction(Action* a)
