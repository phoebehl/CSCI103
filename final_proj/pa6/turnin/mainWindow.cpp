
#include "mainWindow.h"
#include "centralwidg.h"
#include "startWindow.h"

using namespace std;

MainWindow::MainWindow() 
{
  setGeometry( 0, 0, 855, 420 );

  //Display the board in the central widget
  centralWidget = new CentralWidg();
  setCentralWidget( centralWidget );

  //Create the 4 players
  players[0] = new Player( "Player 1" );
  players[1] = new Player( "Player 2" );
  players[2] = new Player( "Player 3" );
  players[3] = new Player( "Player 4" );

  //Player 1 is at the bottom. 2 at the left. 3 on top. 4 on the right
  //Create the GUIPlayers
  guiPlayers[0] = new PlayerGUI( players[0] );
  guiPlayers[1] = new PlayerGUI( players[1] );
  guiPlayers[2] = new PlayerGUI( players[2] );
  guiPlayers[3] = new PlayerGUI( players[3] );

  addDockWidget( Qt::BottomDockWidgetArea, guiPlayers[0] );
  addDockWidget( Qt::BottomDockWidgetArea, guiPlayers[1] );
  addDockWidget( Qt::BottomDockWidgetArea, guiPlayers[2] );
  addDockWidget( Qt::BottomDockWidgetArea, guiPlayers[3] );


}
