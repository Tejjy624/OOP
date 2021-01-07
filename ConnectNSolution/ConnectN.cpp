#include <iostream>
#include "ConnectN.h"
#include "Move.h"

ConnectNGame::ConnectN::ConnectN(int numRows, int numCols, int numPiecesToWin, char blankSpace) :
    model(numRows, numCols, numPiecesToWin, blankSpace),
    view(std::cin, std::cout) {

}

void ConnectNGame::ConnectN::playGame() {
  //add in the players for this game
  addPlayers();

  while (true) { //while the game isn't over
    view.displayGameState(model);
    Move move = model.getActivePlayer().getMove(model, view);
    move.make(model);

    //this is needed so that it stays the current player's turn when they win
    if (model.isGameOver()) {
      break;
    } else {
      model.changeTurn();
    }

  }
  view.displayGameState(model); // show the game one last time
  view.displayGameResults(model);
}

void ConnectNGame::ConnectN::addPlayers() {
  for (int i = 1; i <= 2; ++i) {
    Player player(getPlayerInfo(i));
    model.addPlayer(player);
  }

}

ConnectNGame::Player ConnectNGame::ConnectN::getPlayerInfo(int playerNumber) {
  Player player;
  player.setName(getPlayerName(playerNumber));
  player.setPiece(getPlayerPiece(player));
  return player;
}

std::string ConnectNGame::ConnectN::getPlayerName(int playerNumber) {
  std::string playerName;
  do {
    playerName = view.getPlayerName(playerNumber);
  } while (!model.isValidPlayerName(playerName));
  return playerName;
}

char ConnectNGame::ConnectN::getPlayerPiece(const ConnectNGame::Player& player) {
  char piece;
  do {
    piece = view.getPlayerPiece(player);
  } while (!model.isValidPieceChoice(piece));
  return piece;
}
