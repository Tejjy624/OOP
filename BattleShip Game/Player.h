#ifndef BATTLESHIP__PLAYER_H_
#define BATTLESHIP__PLAYER_H_
#include <functional>
#include <string>
#include <memory>
#include <map>
#include "Move.h"
#include "GameAttributes.h"
#include "View.h"
#include "Board.h"
#include "AttackResult.h"

namespace BattleShip {
class View;
class Move;
class Model;
class Player {
 public:
  Player(const GameAttributes& gameAttributes, View& view);
  const std::string& getName() const;
  void Name(const std::string &name);
  const Board& getBoard() const;
  Board& getBoard();
  const int getId() const;
  virtual std::unique_ptr<BattleShip::Move> getMove() = 0;
  virtual void placeShips() = 0;
  virtual void initializeName() = 0;
  virtual bool ShipsSunk() const;
  virtual BattleShip::AttackResult fireAt(int row, int col);
  Player& getOpponent();
  const Player& getOpponent() const;
  void setOpponent(Player& opponent);
  virtual ~Player();
 protected:
  virtual bool hit(char shipChar);
  static int num_instances;
  const int id;
  std::string name;
  std::map<char, int> shipHealths;
  View& view;
  Board board;
  Player* opponent;
};
}
namespace std{
template <>
class hash<BattleShip::Player&>{
  std::size_t operator()(const BattleShip::Player& player) const{
    return player.getId();
  }
};
}

#endif
