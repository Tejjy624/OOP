#ifndef CONNECTN_MOVE_H
#define CONNECTN_MOVE_H

namespace ConnectNGame {
  class Player;
  class Model;
  class Move {
   public:
    Move(const Player& maker);
    bool isValid(const Model& model) const;
    void make(Model& model);
    void setCol(int col);
   private:
    int col;
    const Player& maker;
  };
}
#endif //CONNECTN_MOVE_H
