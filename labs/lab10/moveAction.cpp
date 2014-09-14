#include <iostream>
#include "action.h"
#include "moveAction.h"

using namespace std;

moveAction::moveAction(string title) : Action(title)
{
	_amount = 0;
}

void moveAction::set_amount()
{
	cout << "The amount is: " << _amount << endl;
}

void moveAction::get_amount(int num)
{
	_amount = num;

}

void moveAction::executeAction()
{
	cout << "in moveAction executeAction" << endl;
}