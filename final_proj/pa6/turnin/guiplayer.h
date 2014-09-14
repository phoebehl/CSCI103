
#include <QtGui>

#ifndef GUIPLAYER_H
#define GUIPLAYER_H

#include "player.h"
#include "playergui.h"

class GUIPlayer : public PlayerGUI 
{
  Q_OBJECT

  private:
    Player* player;

 public:
    GUIPlayer( Player* p );

};

#endif

