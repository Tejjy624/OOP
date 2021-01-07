#ifndef CONNECTN_CONNECTN_H
#define CONNECTN_CONNECTN_H
#include <string>
#include "Model.h"
#include "View.h"
namespace ConnectNGame {
  class Player;
  class ConnectN {
   public:
    ConnectN(int numRows, int numCols, int numPiecesToWin, char blankSpace);
    void playGame();

   private:
    void addPlayers() ;
    ConnectNGame::Player getPlayerInfo(int playerNumber);
    std::string getPlayerName(int playerNumber);
    char getPlayerPiece(const Player& player);

   private:
    Model model;
    View view;
  };
}

#endif //CONNECTN_CONNECTN_H
