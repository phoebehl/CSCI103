#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <QtGui>
#include <QString>
#include "player.h"
#include "game_board.h"

using namespace std;

Player::Player(QString name)
{
	_currentSpace = 0;
	_totStars = 0;
	_piece = " ";
	_name = name;
}

void Player::selectPiece(string choice)
{
	_piece = choice;

}

string Player::showPiece()
{
	return _piece;
}

int Player::getSpace()
{
	return _currentSpace;
}

void Player::setSpace(int space)
{
	_currentSpace = space;
}

QString Player::getStars()
{
	string stars;
	stringstream ss;
	ss >> _totStars;
	ss <<  stars;
	ss.clear();
	QString qstars = QString::fromStdString(stars);
	return qstars;
}

void Player::setStars(int num)
{
	_totStars = _totStars+num;
}

QString Player::getName()
{
	return _name;
}

string Player::getIcon()
{
	return _icon;
}

void Player::setIcon(string url)
{
	_icon = url;

}