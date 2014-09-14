#include <QtGui>

#ifndef PLAYERGUI_H
#define PLAYERGUI_H

#include "player.h"

class PlayerGUI : public QDockWidget {
  Q_OBJECT

  protected:
    Player* player;
    QLabel *nameLabel;
    QLabel* iconLabel;
    QPushButton* roll;
    QPushButton* resign;
    QLabel* stars;

    bool resigned;

  public:
    PlayerGUI( Player* p );

};

#endif