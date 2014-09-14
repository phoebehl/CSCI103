#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QtGui>
#include <QTextEdit>

#include "guiplayer.h"
#include "player.h"

class StartWindow : public QWidget
{
  Q_OBJECT

  protected:
  QLabel* text;
  QLabel* playerText;
  QPushButton* onePlayer;
  QPushButton* twoPlayer;
  QPushButton* threePlayer;
  QPushButton* fourPlayer;

  QPixmap* icon1;
  QPixmap* icon2;
  QPixmap* icon3;
  QPixmap* icon4;
  QPixmap* icon5;
  QPixmap* icon6;
  QPixmap* icon7;
  QPixmap* icon8;
  QPixmap* icon9;
  QPixmap* icon10;

  QPushButton* icon1Button;
  QPushButton* icon2Button;
  QPushButton* icon3Button;
  QPushButton* icon4Button;
  QPushButton* icon5Button;
  QPushButton* icon6Button;
  QPushButton* icon7Button;
  QPushButton* icon8Button;
  QPushButton* icon9Button;
  QPushButton* icon10Button;


  QString icon1url;
  QString icon2url;
  QString icon3url;
  QString icon4url;
  QString icon5url;
  QString icon6url;
  QString icon7url;
  QString icon8url;
  QString icon9url;
  QString icon10url;

  QWidget* startWindow;
  QWidget* playerWindow;

  bool used[10];

public:
  StartWindow();
  int PlayerWindow(int numPlayers, int pressCount);
  void selectPlayers(int chosen);

};

#endif