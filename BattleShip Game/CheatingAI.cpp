#include <stdexcept>
#include "CheatingAI.h"
#include "Attack.h"

std::unique_ptr<BattleShip::Move> BattleShip::CheatingAI::getMove() {

  int i = 0;
  while (i < this->getOpponent().getBoard().getNumRows()) {
    int j = 0;
    while (j < this->getOpponent().getBoard().getNumCols()) {
      if(this->getOpponent().getBoard().at(i,j).containsShip()){
        firingLocations.push_back(std::make_pair(i,j));
      }
      j++;
    }
    i++;
  }



  int holder = 0;
  std::vector<std::pair<int,int>> cellLocation;
  for (auto const& v: firingLocations){
    if(this->getOpponent().getBoard().at(v.first,v.second).getContents() != 'X'){
      cellLocation.push_back(std::make_pair(v.first, v.second));
      firingLocations.erase(firingLocations.begin());
      break;
    } else {
      holder++;
    }
  }
  Attack attack(*this, cellLocation.at(holder).first, cellLocation.at(holder).second);
  return std::make_unique<BattleShip::Attack>(attack);
}
BattleShip::CheatingAI::CheatingAI(const BattleShip::GameAttributes &gameAttributes, BattleShip::View &view) : AiPlayer(
        gameAttributes,
        view) {
}