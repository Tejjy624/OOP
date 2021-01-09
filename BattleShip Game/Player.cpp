#include "Player.h"
#include "StandardView.h"
//fired spot is shown
BattleShip::AttackResult BattleShip::Player::fireAt(int row, int col) {
    char boardChar = opponent->getBoard().at(row, col).getContents();
    opponent->getBoard().at(row, col).setHasBeenFiredAt(true);
    bool destroy = false;
    bool hit = false;
    if (opponent->getBoard().at(row, col).containsShip()){
        hit = true;
        opponent->shipHealths[boardChar]--;
        if (opponent->shipHealths[boardChar] == 0){
            destroy = true;
        }
    }
    return BattleShip::AttackResult(hit, destroy, boardChar);
}
//records the ships sunk
bool BattleShip::Player::ShipsSunk() const {
    for (auto& x: shipHealths){
        if (x.second > 0){
            return false;
        }
    }
    return true;
}
//return player moves and names
BattleShip::Player &BattleShip::Player::getOpponent() {
    return *opponent;
}
const BattleShip::Player &BattleShip::Player::getOpponent() const {
    return *opponent;
}
void BattleShip::Player::setOpponent(BattleShip::Player &opponent) {
    this->opponent = &opponent;
}
bool BattleShip::Player::hit(char shipChar) {
    shipHealths[shipChar]--;
    return true;
}
int BattleShip::Player::num_instances = 0;
BattleShip::Player::Player(const BattleShip::GameAttributes &gameAttributes, BattleShip::View &view) : id(num_instances), shipHealths(gameAttributes.getShipAttributes()),view(view), board(Board(gameAttributes.getNumRows(), gameAttributes.getNumCols(), '*')){
  ++num_instances;
}
const std::string &BattleShip::Player::getName() const {
  return name;
}
void BattleShip::Player::Name(const std::string &name) {
  BattleShip::Player::name = name;
}
const BattleShip::Board &BattleShip::Player::getBoard() const {
  return board;
}
BattleShip::Board &BattleShip::Player::getBoard() {
  return board;
}
const int BattleShip::Player::getId() const {
  return id;
}

BattleShip::Player::~Player() = default;
