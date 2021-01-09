#ifndef BATTLESHIP__MODEL_H_
#define BATTLESHIP__MODEL_H_
#include <vector>
#include <memory>
#include "View.h"
#include "Player.h"
#include "GameAttributes.h"
namespace BattleShip {
class Move;
class Player;
class View;
class Model {
 public:
  Model();
  Player& getAttackingPlayer();
  const Player& getAttackingPlayer() const;
  Player& getDefendingPlayer();
  const Player& getDefendingPlayer() const;
  bool isGameOver() const;
  void changeTurn();
  void loadGameConfigurationFromFile(const std::string& gameConfigurationFile);
  template <typename PlayerType>
  void addPlayer(View& view);
  void endGame();
  std::unique_ptr<Move> getNextMove();
  Player& getWinner();
  void setPlayerTurn(int playerTurn);
  void SetOpponents();
 protected:
  GameAttributes gameAttributes;
  std::vector<std::unique_ptr<Player>> players;
  int playerTurn;
  bool forcedGameOver;
};
template<typename PlayerType>
void BattleShip::Model::addPlayer(View& view) {
  std::unique_ptr<PlayerType> player = std::make_unique<PlayerType>(gameAttributes, view);
  player->initializeName();
  player->placeShips();
  players.push_back(std::move(player));
}
}
#endif
