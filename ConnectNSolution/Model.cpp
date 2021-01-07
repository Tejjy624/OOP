#include <cctype>
#include "Model.h"

ConnectNGame::Model::Model(int numRows, int numCols, int numPiecesToWin, char blankSpace) :
    board(numRows, numCols, blankSpace),
    numPiecesToWin(numPiecesToWin),
    curPlayerTurn(0),
    _isGameOver(false),
    gameStatus(GameStatus::InProgress) {

}

const ConnectNGame::Player& ConnectNGame::Model::getActivePlayer() const {
  return players.at(curPlayerTurn);
}

ConnectNGame::Player& ConnectNGame::Model::getActivePlayer() {
  return players.at(curPlayerTurn);
}

void ConnectNGame::Model::changeTurn() {
  curPlayerTurn = (curPlayerTurn + 1) % players.size();
}

const ConnectNGame::Board& ConnectNGame::Model::getBoard() const {
  return board;
}

ConnectNGame::Board& ConnectNGame::Model::getBoard() {
  return board;
}

bool ConnectNGame::Model::isGameOver() const {
  return _isGameOver;
}

void ConnectNGame::Model::addPiece(char piece, int col) {
  board.addPiece(piece, col);
  checkIsGameOver(col);
}

void ConnectNGame::Model::checkIsGameOver(int colPlayed) {
  _isGameOver = horizontalWin(colPlayed) || verticalWin(colPlayed) || diagonalWin(colPlayed);
  if (_isGameOver) {
    gameStatus = GameStatus::Won;
  } else {
    _isGameOver = board.isFull(); // game ties if the board is full and no one has won
    if (_isGameOver) {
      gameStatus = GameStatus::Tied;
    }
  }
}

bool ConnectNGame::Model::horizontalWin(int colPlayed) const {
  int row = board.getRowLastPiecePlayedFellIn();
  return winChecker(row, colPlayed, 0, 1);
}

bool ConnectNGame::Model::verticalWin(int colPlayed) const {
  int row = board.getRowLastPiecePlayedFellIn();
  return winChecker(row, colPlayed, 1, 0);
}

bool ConnectNGame::Model::diagonalWin(int colPlayed) const {
  return leftDiagonalWin(colPlayed) || rightDiagonalWin(colPlayed);
}

bool ConnectNGame::Model::leftDiagonalWin(int colPlayed) const {
  /*
   * Looking for wins like
   *     X
   *   X
   * X
   */
  int row = board.getRowLastPiecePlayedFellIn();
  return winChecker(row, colPlayed, 1, 1);
}

bool ConnectNGame::Model::rightDiagonalWin(int colPlayed) const {
  /*
   * Looking for wins like
   *  X
   *   X
   *    X
   */
  int row = board.getRowLastPiecePlayedFellIn();
  return winChecker(row, colPlayed, 1, -1);
}

bool ConnectNGame::Model::winChecker(int startRow, int startCol, int rowStep, int colStep) const {
  int piecesInARow = 1;
  const char piecePlayed = board.at(startRow, startCol);

  //matching elements going forward
  piecesInARow += matchCounter(startRow + rowStep, startCol + colStep, rowStep, colStep, piecePlayed);

  //matching elements going back wards
  piecesInARow += matchCounter(startRow - rowStep, startCol - colStep, -rowStep, -colStep, piecePlayed);

  return piecesInARow >= numPiecesToWin;
}

int ConnectNGame::Model::matchCounter(int startRow, int startCol, int rowStep, int colStep, char piece) const {
  int piecesInARow = 0;
  for (int row = startRow, col = startCol;
       board.isInBounds(row, col) && board.at(row, col) == piece;
       row += rowStep, col += colStep) {
    piecesInARow++;
  }
  return piecesInARow;

}

void ConnectNGame::Model::addPlayer(const Player& player) {
  players.push_back(player);
}

ConnectNGame::GameStatus ConnectNGame::Model::getGameStatus() const {
  return gameStatus;
}

bool ConnectNGame::Model::isValidPlayerName(const std::string& potentialName) const {
  for(const auto& player: players){
    if(potentialName == player.getName()){
      return false;
    }
  }
  return true;
}

bool ConnectNGame::Model::isValidPieceChoice(char potentialPieceChoice) const {
  for(const auto& player: players){
    if(tolower(potentialPieceChoice) == tolower(player.getPiece())){
      return false;
    }
  }
  return true;
}

