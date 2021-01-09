#ifndef BATTLESHIP__ATTACK_H_
#define BATTLESHIP__ATTACK_H_
#include "Move.h"
#include "Player.h"

namespace BattleShip {
class Attack : public Move {
 public:
  Attack(BattleShip::Player& attacker, int row, int col);
  virtual void enact(Model& model, View& view) override;
  virtual bool isValid() const override;
  const int getRow() const;
  const int getCol() const;
protected:
  const int row, col;
};
}
#endif
