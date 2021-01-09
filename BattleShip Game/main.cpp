#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Controller.h"


int main(int argc, char** argv) {
  BattleShip::Controller controller;
  if (argc > 2){
      controller.setup(argv[1], std::stoi(argv[2]));
  } else {
      controller.setup(argv[1]);
  }
  return 0;
}
