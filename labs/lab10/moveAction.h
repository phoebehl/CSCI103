#ifndef MOVEACTION_H
#define MOVEACTION_H

#include <string.h>

using namespace std;

class moveAction: public Action
{
public:
	moveAction(string title);
	void set_amount();
	void get_amount(int num);
	void executeAction();

private:
	int _amount;

};

#endif