#include <iostream>
#include <string>
#include "ConnectN.h"

int main(int argc, char** argv) {

  if (argc < 4) {
    std::cout << "Not enough command line parameters provided." << std::endl;
    std::cout << "Usage: ./ConnectN numRows numCols numPiecesToWin" << std::endl;

  } else {
    int numRows = std::stoi(argv[1]);
    int numCols = std::stoi(argv[2]);
    int numPiecesToWin = std::stoi(argv[3]);
    ConnectNGame::ConnectN game(numRows, numCols, numPiecesToWin, '*');
    game.playGame();
  }

  return 0;
}
