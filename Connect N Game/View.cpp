#include <algorithm>
#include <string>
#include "View.h"

#include "Board.h"
#include "ValidatedReads.h"
#include "Player.h"
#include "Model.h"
#include "Move.h"
#include "GameStatus.h"

ConnectNGame::View::View(std::istream& in, std::ostream& out) : in(in), out(out) {}

void ConnectNGame::View::displayGameState(const Model& model) {
  const Board& board = model.getBoard();
  const int maxDim = std::max(board.getNumRows(), board.getNumCols());
  const int fieldSize = std::to_string(maxDim).size();

  out << std::string(fieldSize + 1, ' ');
  for (int i = 0; i < board.getNumCols(); ++i) {
    out.width(fieldSize);
    out << i << ' ';
  }
  out << std::endl;

  int rowIndex = board.getNumRows() - 1;

  for(auto rowItr = board.crbegin(); rowItr != board.crend(); ++rowItr) {
    out.width(fieldSize);
    out << rowIndex << ' ';
    for (const auto& piece : *rowItr) {
      out.width(fieldSize);
      out << piece << ' ';
    }
    --rowIndex;
    out << std::endl;
  }

}

int ConnectNGame::View::getPlayColumn(const Player& player) {
  int col;
  std::string prompt(player.getName() + ", please enter a column to play in: ");
  col = getValidInput<int>(in, out, prompt);
  return col;
}

std::string ConnectNGame::View::getPlayerName(int playerNumber) {
  std::string namePrompt("Player " + std::to_string(playerNumber) + ", please enter your name: ");
  return getValidInput<std::string>(in, out, namePrompt);
}

char ConnectNGame::View::getPlayerPiece(const Player& player) {
  std::string piecePrompt(player.getName() + ", please enter the character you want to use for your piece: ");
  return getValidInput<char>(in, out, piecePrompt);
}

void ConnectNGame::View::displayGameResults(const Model& model) {
  const GameStatus& gameStatus = model.getGameStatus();
  if (gameStatus == GameStatus::Tied) {
    out << "Tie game." << std::endl;
  } else if (gameStatus == GameStatus::Won) {
    out << model.getActivePlayer().getName() << " won the game!" << std::endl;
  } else {
    out << "Error. This game is still in progress so why are we declaring the result?" << std::endl;
  }
}




