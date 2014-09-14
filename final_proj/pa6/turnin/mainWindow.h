#include <QtGui>

#include "guiplayer.h"
#include "player.h"
#include "centralwidg.h"
#include "startWindow.h"

class MainWindow : public QMainWindow 
{
  Q_OBJECT

  private:
  QLabel *boardLabel;
  Player* players[4];
  PlayerGUI* guiPlayers[4];
  QPushButton* sadDeckButton;
  QPushButton* happyDeckButton;
  QWidget* centralWidget;
  //QLabel* dice;

  public:
    MainWindow();

};
