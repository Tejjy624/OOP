#include <algorithm>
#include "HuntDestroyAI.h"
#include "Attack.h"
#include "Utility.h"
#include "AttackResult.h"

std::vector<std::pair<int, int>> BattleShip::HuntDestroyAI::getSurroundingLocations(const std::pair<int,
        int> &center) const {
    std::vector<std::pair<int, int>> points{{center.first, center.second - 1}, {center.first - 1, center.second}, {center.first, center.second + 1}, {center.first + 1, center.second}};
    auto new_end = std::remove_if(points.begin(), points.end(),
                                  [&board = opponent->getBoard()](auto point) {
                                      return !(board.inBounds(point.first, point.second) &&
                                               !board.at(point.first, point.second).HasBeenFiredAt());
                                  }
    );
    points.erase(new_end, points.end());
    return points;
}
BattleShip::HuntDestroyAI::HuntDestroyAI(const BattleShip::GameAttributes &gameAttributes, BattleShip::View &view)
    : RandomAI(gameAttributes, view) {
}
std::unique_ptr<BattleShip::Move> BattleShip::HuntDestroyAI::getMove() {
  std::unique_ptr<Attack> attack;
  if (priorityFiringQueue.empty()) {
    attack.reset(dynamic_cast<Attack *>(RandomAI::getMove().release()));
  } else {
    auto location = priorityFiringQueue.front();
    attack = std::make_unique<Attack>(*this, location.first, location.second);
    priorityFiringQueue.erase(priorityFiringQueue.begin());
  }
  if (getOpponent().getBoard().at(attack->getRow(), attack->getCol()).containsShip()) {
    auto points = getSurroundingLocations({attack->getRow(), attack->getCol()});
    for (const auto&p : points) {
      auto pos = std::find(firingLocations.begin(), firingLocations.end(), p);
      if (pos != firingLocations.end()) {
        priorityFiringQueue.push_back(p);
        firingLocations.erase(pos);
      }
    }
  }
  return attack;
}
