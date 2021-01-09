#include <utility>
#include "HumanPlayer.h"
#include "ShipPlacement.h"
#include "Attack.h"
#include "StandardView.h"

void BattleShip::HumanPlayer::initializeName() {
    std::cout << "Player " << getId() + 1 << " please enter your name: " << std::endl;
    std::string name;
    std::cin >> name;
    Name(name);
}
void BattleShip::HumanPlayer::placeShips() {
    ShipPlacement placement;
    view.PlayerBoard(*this);
    for(auto& ship : this->shipHealths){
        placement = view.getShipPlacement(*this , ship.first, ship.second);
        board.AddShip(ship.first, placement);
        view.updateShipPlacementView(*this);
    }
}
BattleShip::HumanPlayer::HumanPlayer(const BattleShip::GameAttributes &gameAttributes, BattleShip::View &view)
    : Player(gameAttributes ,view) {
}
std::unique_ptr<BattleShip::Move> BattleShip::HumanPlayer::getMove() {
  std::pair<int, int> cellLocation;
  std::cout << this->getName() << "'s Firing Board" << std::endl;
    view.PlayerBoard(this->getOpponent());
  std::cout<< std::endl << std::endl;
  std::cout << this->getName() << "'s Placement Board" << std::endl;
    view.BoardPlacement(*this);
  cellLocation= view.Coordinates(*this);
  return std::make_unique<BattleShip::Attack>(*this, cellLocation.first, cellLocation.second);
}
