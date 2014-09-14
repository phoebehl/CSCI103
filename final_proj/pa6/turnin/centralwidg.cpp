#include "centralwidg.h"

CentralWidg::CentralWidg(): QWidget() 
{
  setGeometry( 0, 0, 855, 420 );
  boardLabel = new QLabel( this );
  QImage board;
  board.load("gameBoard.jpg");
  boardLabel->setPixmap( QPixmap::fromImage(board));
  /*
  //Create the two card images
  happyFaceDown = new QPixmap( "happyDownUnfin.jpg" );
  happyFaceUp = new QPixmap( "happyUpUnfin.jpg" );

  sadFaceDown = new QPixmap( "sadDownUnfin.jpg");
  sadFaceUp = new QPixmap ("sadUpUnfin.jpg");

  //Create the buttons for the card decks
  happyDeckButton = new QPushButton( this );
  happyDeckButton->setIcon( *happyFaceDown );
  ///need to update these sizes
  happyDeckButton->setIconSize( QSize(173, 231) );
  happyDeckButton->setGeometry( 275, 150, 173, 231 );

  sadDeckButton = new QPushButton( this );
  sadDeckButton->setIcon( *sadFaceDown );
  sadDeckButton->setIconSize ( QSize(173, 231));

  //Connect the button to drawCard
  connect( happyDeckButton, SIGNAL(clicked()), this, SLOT(drawHappyCard()) );
  happyCardFaceDown = true;

  connect (sadDeckButton, SIGNAL(clicked()), this, SLOT(drawSadCard()) );
  sadCardFaceDown = true;
  */
}

/*
void CentralWidg::drawHappyCard() 
{
  //Show the face up card
  if ( happyFaceDown ) 
  {
    happyDeckButton->setIcon( *happyFaceUp );
    happyCardFaceDown = false;
  } 
  else 
  {
    happyDeckButton->setIcon( *happyFaceDown );
    happyCardFaceDown = true;
  }
}

void CentralWidg::drawSadCard()
{
  if (sadFaceDown) 
  {
    sadDeckButton->setIcon( *sadFaceUp );
    sadCardFaceDown = false;
  }
  else
  {
    sadDeckButton->setIcon( *sadFaceDown );
    sadCardFaceDown = true;
  }
}
*/