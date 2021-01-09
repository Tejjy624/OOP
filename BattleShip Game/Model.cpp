#include <fstream>
#include <algorithm>
#include "Model.h"

void BattleShip::Model::changeTurn() {
    playerTurn = static_cast<int>((playerTurn + 1) % players.size());
}
//get contents of configuration files
void BattleShip::Model::loadGameConfigurationFromFile(const std::string &gameConfigurationFile) {
    std::ifstream myfile(gameConfigurationFile);
    gameAttributes = GameAttributes(myfile);
}
//gets the move from player
BattleShip::Model::Model() = default;
std::unique_ptr<BattleShip::Move> BattleShip::Model::getNextMove() {
    std::unique_ptr<BattleShip::Move> a;
    a = players.at(playerTurn)->getMove();
    return a;
}
//finds the winner
BattleShip::Player &BattleShip::Model::getWinner() {
    if (getDefendingPlayer().ShipsSunk()){
        return getAttackingPlayer();
    } else {
        return getDefendingPlayer();
    }
}
void BattleShip::Model::SetOpponents() {
    players.front()->setOpponent(*(players.back().get()));
    players.back()->setOpponent(*(players.front().get()));
}
//whos turn it is
void BattleShip::Model::setPlayerTurn(int playerTurn) {
    Model::playerTurn = playerTurn;
}
//who is attacking
BattleShip::Player &BattleShip::Model::getAttackingPlayer() {
  return *(players.at(playerTurn));
}
const BattleShip::Player &BattleShip::Model::getAttackingPlayer() const {
  return *(players.at(playerTurn));
}
//who is defending
BattleShip::Player &BattleShip::Model::getDefendingPlayer() {
  return *(players.at((playerTurn + 1) % players.size()));
}
const BattleShip::Player &BattleShip::Model::getDefendingPlayer() const {
  return *(players.at((playerTurn + 1) % players.size()));
}
bool BattleShip::Model::isGameOver() const {
  return getDefendingPlayer().ShipsSunk() || getAttackingPlayer().ShipsSunk();
}
void BattleShip::Model::endGame() {
  if(isGameOver()){
  }
}
