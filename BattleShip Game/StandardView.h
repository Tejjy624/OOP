#ifndef BATTLESHIP__STANDARDVIEW_H_
#define BATTLESHIP__STANDARDVIEW_H_
#include <iostream>
#include <utility>
#include "PlayerConfiguration.h"
#include "View.h"

namespace BattleShip  {
class StandardView : public View{
 public:
  StandardView();
  StandardView(std::istream& in, std::ostream& out);
  virtual PlayerConfiguration getPlayerConfiguration() override;
  virtual std::string getPlayerName(int i) override;
  virtual ShipPlacement getShipPlacement(const Player& player, char shipChar, int shipLen) override;
  virtual void updateShipPlacementView(const Player& player) override;
  virtual std::pair<int, int> Coordinates(const BattleShip::Player &attacker) override;
  virtual void Winner(const Player &winner) override;
  virtual void AttackResult(const BattleShip::Player &attacker,
                            const BattleShip::AttackResult &attackResult) override;

  virtual void PlayerBoard(const Player &player) override;
  virtual void BoardPlacement(const Player &player) override;
 protected:
  void printBoard(const std::vector<std::string>& board);
  void printBoardAsVisible(const Board& board);
  void printBoardAsObscured(const Board& board);
 public:
  virtual int ChooseAI() override;
 protected:

  void clearInput();

  std::istream& in;
  std::ostream& out;
};
}

#endif
