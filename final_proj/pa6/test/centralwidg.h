#ifndef CENTRALWIDG_H
#define CENTRALWIDG_H

#include <QtGui>

class CentralWidg: public QWidget 
{
  Q_OBJECT

public:
  CentralWidg();

private:
  QPushButton* happyDeckButton;
  QPushButton* sadDeckButton;
  QLabel* boardLabel;
  QPixmap* happyFaceUp;
  QPixmap* happyFaceDown;
  QPixmap* sadFaceUp;
  QPixmap* sadFaceDown;
  bool happyCardFaceDown;
  bool sadCardFaceDown;

private slots:
 // void drawHappyCard();
//  void drawSadCard();
  

};

#endif
