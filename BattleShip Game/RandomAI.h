#ifndef BATTLESHIP__RANDOMAI_H_
#define BATTLESHIP__RANDOMAI_H_
#include <vector>
#include <algorithm>
#include "AiPlayer.h"

namespace BattleShip {
class RandomAI  : public AiPlayer{
 public:
  RandomAI(const GameAttributes& gameAttributes, View& view);
  virtual std::unique_ptr<Move> getMove() override;
 protected:
  std::vector<std::pair<int, int>> firingLocations;
};
}

#endif
