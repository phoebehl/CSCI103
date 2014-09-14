#include <QtGui>

#include "playergui.h"

PlayerGUI::PlayerGUI( Player* p ) 
{
  player = p;
  nameLabel = new QLabel( this );
  nameLabel->setText( player->getName() );
  nameLabel->setGeometry(0, 0, 213, 20);

  //iconLabel = new QLabel ( this );
  //iconLabel->setPixmap(QPixmap(player->getIcon()));

  roll = new QPushButton(this);
  roll-> setText("Roll Dice");
  roll->setGeometry(0, 20, 71,60);

  resign = new QPushButton(this);
  resign->setText("Quit Game");
  resign->setGeometry(71, 20, 71, 60);

  stars = new QLabel(this);
  stars->setText(player->getStars());
  stars->setGeometry(142, 20, 71, 60);

  resigned = false;


}
/*
bool PlayerGUI::takeTurn()
{
  if ( resign = false)

}
*/
