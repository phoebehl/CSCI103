#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

class Player
{
public:
	Player();
	void give_money(int amount);

	private:
	int _currentSpace;
	int _totPoints;
	string _piece;
};

#endif