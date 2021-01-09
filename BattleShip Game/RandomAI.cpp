#include "RandomAI.h"
#include "Attack.h"
#include "Utility.h"

//finds a position to fire randomly
std::unique_ptr<BattleShip::Move> BattleShip::RandomAI::getMove() {
    auto itr = chooseRandom(firingLocations, randomNumberGenerator);
    std::pair<int,int> location = *itr;
    firingLocations.erase(itr);
    return std::unique_ptr<BattleShip::Move>(new Attack(*this, location.first, location.second));
}
BattleShip::RandomAI::RandomAI(const BattleShip::GameAttributes &gameAttributes, BattleShip::View &view)
    : AiPlayer(gameAttributes, view) {
  int i = 0;
  while ( i < this->getBoard().getNumRows()) {
    int j = 0;
    while (j < this->getBoard().getNumCols()) {
      firingLocations.push_back(std::make_pair(i,j));
      j++;
    }
    i++;
  }
}
