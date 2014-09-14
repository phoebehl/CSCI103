#include <iostream>
#include "action.h"

using namespace std;

Action::Action()
{
	for (int i = 0; i < 3; i++)
	{
		_text[i] = "      ";
	}
}

//void Action::setAction()
//{

//}

string Action::getText(int j)
{
	return _text[j];
}