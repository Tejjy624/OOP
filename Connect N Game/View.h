#ifndef CONNECTN_VIEW_H
#define CONNECTN_VIEW_H
#include <string>
#include <istream>
#include <ostream>
namespace ConnectNGame {
  class Model;
  class Move;
  class Player;
  class View {
   public:
    View(std::istream& in, std::ostream& out);
    void displayGameState(const Model& board);
    int getPlayColumn(const Player& player);

    std::string getPlayerName(int playerNumber);
    char getPlayerPiece(const Player& player);

    void displayGameResults(const Model& model);
   private:
    std::istream& in;
    std::ostream& out;

  };
}

#endif //CONNECTN_VIEW_H
