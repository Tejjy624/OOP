#include "Board.h"

ConnectNGame::Board::Board(int numRows, int numCols, char blankChar) :
    boardState(numRows, std::string(numCols, blankChar)),
    piecesInColumn(numCols, 0),
    blankChar(blankChar),
    rowPieceFellIn(-65){

}

int ConnectNGame::Board::getNumRows() const {
  return boardState.size();
}

int ConnectNGame::Board::getNumCols() const {
  return boardState.front().size();
}

ConnectNGame::Board::const_iterator ConnectNGame::Board::begin() const {
  return boardState.cbegin();
}

ConnectNGame::Board::const_iterator ConnectNGame::Board::end() const {
  return boardState.cend();
}

ConnectNGame::Board::iterator ConnectNGame::Board::begin() {
  return boardState.begin();
}

ConnectNGame::Board::iterator ConnectNGame::Board::end() {
  return boardState.end();
}

ConnectNGame::Board::reverse_iterator ConnectNGame::Board::rbegin() {
  return boardState.rbegin();
}

ConnectNGame::Board::reverse_iterator ConnectNGame::Board::rend() {
  return boardState.rend();
}

ConnectNGame::Board::const_reverse_iterator ConnectNGame::Board::crbegin() const {
  return boardState.crbegin();
}

ConnectNGame::Board::const_reverse_iterator ConnectNGame::Board::crend() const {
  return boardState.crend();
}

bool ConnectNGame::Board::canAddPieceTo(int col) const {
  return isColInBounds(col) && !columnIsFull(col);
}

bool ConnectNGame::Board::isColInBounds(int col) const {
  return isBetween(col, 0, getNumCols() - 1);
}

bool ConnectNGame::Board::isInBounds(int row, int col) const {
  return isBetween(row, 0, getNumRows() - 1) &&
      isBetween(col, 0, getNumCols() - 1);
}

bool ConnectNGame::Board::columnIsFull(int col) const {
  return getNumPiecesInColumn(col) == getNumRows();
}

bool ConnectNGame::Board::isBetween(int val, int low, int high) {
  return val >= low && val <= high;
}

void ConnectNGame::Board::addPiece(char piece, int col) {
  rowPieceFellIn = piecesInColumn.at(col);
  boardState.at(rowPieceFellIn).at(col) = piece;
  piecesInColumn.at(col)++;
}

const char& ConnectNGame::Board::at(int row, int col) const {
  return boardState.at(row).at(col);
}

char& ConnectNGame::Board::at(int row, int col) {
  return boardState.at(row).at(col);
}

int ConnectNGame::Board::getNumPiecesInColumn(int col) const {
  return piecesInColumn.at(col);
}

bool ConnectNGame::Board::isFull() const {
  for (const auto& numPieces : piecesInColumn) {
    if (numPieces < getNumRows()) {
      return false;
    }
  }
  return true;
}

int ConnectNGame::Board::getRowLastPiecePlayedFellIn() const {
  return rowPieceFellIn;
}








