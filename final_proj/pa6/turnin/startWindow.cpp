#include <QtGui>
#include <QWidget>
#include <QErrorMessage>

#include "startWindow.h"

using namespace std;

StartWindow::StartWindow() : QWidget()
{
	for (int i = 0; i < 10; i++)
	{
		used[i] = false;
	}

	setGeometry(0,0, 90, 100);
	text = new QLabel(this);
	text->setText("Click the button corresponding to the number of players:");
	text->setGeometry(0,0, 90,25);

	twoPlayer = new QPushButton(this);
	twoPlayer->setGeometry( 0, 25, 30, 25 );
	threePlayer = new QPushButton(this);
	threePlayer->setGeometry( 30, 25, 30, 25 );
	fourPlayer = new QPushButton(this);
	fourPlayer->setGeometry( 60, 25, 30, 25 );

	connect( twoPlayer, SIGNAL(clicked()), this, SLOT(PlayerWindow(2, 0) ));
	connect( threePlayer, SIGNAL(clicked()), this, SLOT(PlayerWindow(3, 0) ));
	connect( fourPlayer, SIGNAL(clicked()), this, SLOT(PlayerWindow(4, 0) ));

}

int StartWindow::PlayerWindow(int numPlayers, int pressCount)
{

	playerWindow = new QWidget;
	playerWindow->setGeometry(0,0,200, 125);
	playerText = new QLabel(this);
	playerText->setGeometry(0,0,200,25);
	playerText->setText("Click the icon you wish to use. Players may not use the same icon.");
	icon1 = new QPixmap("Chococat_solid.png");
	icon2 = new QPixmap("Keroppi_solid.png");
	icon3 = new QPixmap("Kitty_solid.png");
	icon4 = new QPixmap("Kururin_solid.png");
	icon5 = new QPixmap("maru_solid.png");
	icon6 = new QPixmap("Melody-chan_solid.png");
	icon7 = new QPixmap("Pekkle_solid.png");
	icon8 = new QPixmap("Pochacco_solid.png");
	icon9 = new QPixmap("Purin_solid.png");
	icon10 = new QPixmap("Sweet_solid.png");


		//create icons

		icon1Button->setIcon( *icon1 );
		icon1Button->setIconSize( QSize(25, 25) );
	  	icon1Button->setGeometry(0, 25, 25, 25 );
	  	icon2Button->setIcon( *icon2 );
		icon2Button->setIconSize( QSize(25, 25) );
	  	icon2Button->setGeometry(25, 25, 25, 25 );
	  	icon3Button->setIcon( *icon3 );
		icon3Button->setIconSize( QSize(25, 25) );
	  	icon3Button->setGeometry(50, 25, 25, 25 );
	  	icon4Button->setIcon( *icon4 );
		icon4Button->setIconSize( QSize(25, 25) );
	  	icon4Button->setGeometry(75, 25, 25, 25 );
	  	icon5Button->setIcon( *icon5 );
		icon5Button->setIconSize( QSize(25, 25) );
	  	icon5Button->setGeometry(100, 25,25, 25 );
	  	icon6Button->setIcon( *icon6 );
		icon6Button->setIconSize( QSize(25, 25) );
	  	icon6Button->setGeometry(0, 50, 25, 25 );
	  	icon7Button->setIcon( *icon7 );
		icon7Button->setIconSize( QSize(25, 25) );
	  	icon7Button->setGeometry(25, 50, 25, 25 );
	  	icon8Button->setIcon( *icon8 );
		icon8Button->setIconSize( QSize(25, 25) );
	  	icon8Button->setGeometry(50, 50, 25, 25 );
	  	icon9Button->setIcon( *icon9 );
		icon9Button->setIconSize( QSize(25, 25) );
	  	icon9Button->setGeometry( 75, 50, 25, 25 );
	  	icon10Button->setIcon( *icon10 );
		icon10Button->setIconSize( QSize(25, 25) );
	  	icon10Button->setGeometry( 100, 50, 25, 25 );
	for (pressCount; pressCount < numPlayers; pressCount++)
	{
		

	  	connect( icon1Button, SIGNAL(clicked()), this, SLOT(selectPlayers(1) ));
    	connect( icon2Button, SIGNAL(clicked()), this, SLOT(selectPlayers(2) ));
    	connect( icon3Button, SIGNAL(clicked()), this, SLOT(selectPlayers(3) ));
    	connect( icon4Button, SIGNAL(clicked()), this, SLOT(selectPlayers(4) ));
    	connect( icon5Button, SIGNAL(clicked()), this, SLOT(selectPlayers(5) ));
    	connect( icon6Button, SIGNAL(clicked()), this, SLOT(selectPlayers(6) ));
    	connect( icon7Button, SIGNAL(clicked()), this, SLOT(selectPlayers(7) ));
    	connect( icon8Button, SIGNAL(clicked()), this, SLOT(selectPlayers(8) ));
    	connect( icon9Button, SIGNAL(clicked()), this, SLOT(selectPlayers(9) ));
    	connect( icon10Button, SIGNAL(clicked()), this, SLOT(selectPlayers(10) ));

	}    	
}
/*

void StartWindow::selectPlayers(int chosen)
{

	if (used[chosen] == true)
	{
		QErrorMessage *iconError = new QErrorMessage(this);
		iconError->setMessage("Another player has already chosen that piece.");
	}
	else
	{
		used[chosen] == true;
	}

}
*/