#ifndef PLAYER_H
#define PLAYER_H

#include <string.h>
#include <QtGui>
#include <QString>
#include "game_board.h"

using namespace std;

class Player
{
public:
	Player(QString name);
	void selectPiece(string choice);
	string showPiece();
	int getSpace();
	void setSpace(int space);
	QString getStars();
	void setStars(int num);
	QString getName();
	string getIcon();
	void setIcon(string url);

	private:
	int _currentSpace;
	int _totStars;
	string _piece;
	QString _name;
	string _icon;
};

#endif