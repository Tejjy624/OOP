#ifndef BATTLESHIP__CONTROLLER_H_
#define BATTLESHIP__CONTROLLER_H_
#include <memory>
#include <string>
#include "Model.h"
#include "View.h"
#include "Player.h"
#include "Move.h"

namespace BattleShip {
class Controller {
 public:
  Controller();
  void setup(const std::string &GameConfigurationFile, int seed);
  void setup(const std::string &GameConfigurationFile);
  void setup();
  void playGame();
 protected:
  bool hasBeenSetUp;
  Model model;
  std::unique_ptr<View> view;
};
}
#endif