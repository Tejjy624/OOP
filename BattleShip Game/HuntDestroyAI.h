#ifndef BATTLESHIP__HUNTDESTROYAI_H_
#define BATTLESHIP__HUNTDESTROYAI_H_
#include <vector>
#include <algorithm>
#include "RandomAI.h"
namespace BattleShip {
class HuntDestroyAI : public RandomAI{
 public:
  HuntDestroyAI(const GameAttributes& gameAttributes, View& view);
  virtual std::unique_ptr<Move> getMove() override;
 protected:
  std::vector<std::pair<int, int>> getSurroundingLocations(const std::pair<int, int>& center) const;
  std::vector<std::pair<int,int>> priorityFiringQueue;
};
}
#endif
