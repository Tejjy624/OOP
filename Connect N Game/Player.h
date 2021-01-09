#ifndef CONNECTN_PLAYER_H
#define CONNECTN_PLAYER_H
#include <string>


namespace ConnectNGame {
  class Move;
  class Model;
  class View;

  class Player {
   public:
    Player();
    Move getMove(Model& model, View& view);
    const std::string& getName() const;
    char getPiece() const;
    void setName(const std::string& name);
    void setPiece(char piece);
   private:
    std::string name;
    char piece;

  };
}

#endif //CONNECTN_PLAYER_H
