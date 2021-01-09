#ifndef BATTLESHIP__VIEW_H_
#define BATTLESHIP__VIEW_H_
#include <unordered_map>
#include "PlayerConfiguration.h"
#include "ShipPlacement.h"
#include "Player.h"
#include "AttackResult.h"
namespace BattleShip {
class Player;
class Model;
class Move;
class View {
 public:
  virtual PlayerConfiguration getPlayerConfiguration() = 0;
  virtual std::string getPlayerName(int i) = 0;
  virtual ShipPlacement getShipPlacement(const Player& player, char shipChar, int shipLen) = 0;
  virtual void updateShipPlacementView(const Player& player) = 0;
  virtual std::pair<int, int> Coordinates(const BattleShip::Player &attacker) = 0;
  virtual void Winner(const Player &winner) = 0;
  virtual void AttackResult(const BattleShip::Player &attacker,
                            const BattleShip::AttackResult &attackResult) = 0;
  virtual void PlayerBoard(const Player &player) = 0;
  virtual void BoardPlacement(const Player &player) = 0;
  virtual int ChooseAI() = 0;
  virtual ~View();
};
}
#endif
