#ifndef BATTLESHIP__CHEATINGAI_H_
#define BATTLESHIP__CHEATINGAI_H_
#include "AiPlayer.h"

namespace BattleShip {
class CheatingAI  : public AiPlayer{
 public:
  CheatingAI(const GameAttributes& gameAttributes, View& view);
  virtual std::unique_ptr<Move> getMove() override;
 protected:
  std::vector<std::pair<int, int>> firingLocations;
};
}

#endif
