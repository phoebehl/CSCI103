
#include "mainwindow.h"

MainWindow::MainWindow() {
  setGeometry( 0, 0, 960, 1480 );

  //Display the board in the central widget
  centralWidget = new CentralWidget();
  setCentralWidget( centralWidget );

  //Create the 4 players
  players[0] = new Player( "Player 1" );
  players[1] = new Player( "Player 2" );
  players[2] = new Player( "Player 3" );
  players[3] = new Player( "Player 4" );

  //Player 1 is at the bottom. 2 at the left. 3 on top. 4 on the right
  //Create the GUIPlayers
  guiPlayers[0] = new GUIPlayer( players[0] );
  guiPlayers[1] = new GUIPlayer( players[1] );
  guiPlayers[2] = new GUIPlayer( players[2] );
  guiPlayers[3] = new GUIPlayer( players[3] );

  addDockWidget( Qt::BottomDockWidgetArea, guiPlayers[0] );
  addDockWidget( Qt::LeftDockWidgetArea, guiPlayers[1] );
  addDockWidget( Qt::TopDockWidgetArea, guiPlayers[2] );
  addDockWidget( Qt::RightDockWidgetArea, guiPlayers[3] );
}
