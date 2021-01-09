#include "Board.h"
#include <iostream>
#include <string>
BattleShip::Board::Board() : numRows(getNumRows()), numCols(getNumCols()), blankChar('*'){};
//creates a simple board
BattleShip::Board::Board(int numRows, int numCols, char blankChar) : numRows(numRows), numCols(numCols), blankChar(blankChar) {
  int rows = 0;
  while (rows < numRows) {
    std::vector<Cell> curRow;
    int cols = 0;
    while( cols < numCols) {
      curRow.push_back(blankChar);
      cols++;
    }
    boardState.push_back(curRow);
    rows++;
  }
}
//create a private board
std::vector<std::string> BattleShip::Board::getHiddenVersion() const {
    std::vector<std::string> cellContent;
    std::string str = "";

    int row = 0;
    while ( row < getNumRows()) {
        str.clear();
        int cols = 0;
        while (cols < getNumCols()) {
            str.push_back(boardState[row][cols].getContentsIfHidden());
            cols++;
        }
        cellContent.push_back(str);
        row++;
    }
    return cellContent;
}
//used to add multiple ships onto all boards
void BattleShip::Board::AddShip(char shipChar, const ShipPlacement &shipPlacement) {
    if(canPlaceShipAt(shipPlacement)) {
        if (shipPlacement.rowStart == shipPlacement.rowEnd) {
          int i = shipPlacement.colStart;
            while (i < shipPlacement.colEnd + 1) {
                boardState[shipPlacement.rowStart][i].setContents(shipChar);
                i++;
            }
        } else {
          int i = shipPlacement.rowStart;
           while (i< shipPlacement.rowEnd + 1) {
                boardState[i][shipPlacement.colStart].setContents(shipChar);
                i++;
            }
        }
    }
}
BattleShip::Board::Board(int numRows, int numCols) : numRows(numRows), numCols(numCols), blankChar('*'){
  int rows = 0;
  while (rows < numRows){
    std::vector<Cell> curRow;
    int cols = 0;
    while (cols < numCols){
      curRow.push_back(blankChar);
      cols++;
    }
    boardState.push_back(curRow);
    rows++;
  }
}

bool BattleShip::Board::canPlaceShipAt(const ShipPlacement &shipPlacement) const {
  return (inBounds(shipPlacement) && spacesAreEmpty(shipPlacement));
}
int BattleShip::Board::getNumRows() const {
  return numRows;
}
int BattleShip::Board::getNumCols() const {
  return numCols;
}
std::vector<std::string> BattleShip::Board::getVisibleVersion() const {
  std::vector<std::string> cellContent;
  std::string str = "";
  int rows = 0;
  while (rows < getNumRows()) {
    str.clear();
    int cols = 0;
    while (cols < getNumCols()) {
      str.push_back(boardState[rows][cols].getContentsIfVisible());
      cols++;
    }
    cellContent.push_back(str);
    rows++;
  }
  return cellContent;
}

bool BattleShip::Board::inBounds(int row, int col) const {
  return (row < getNumRows() && col < getNumCols() && row >= 0 && col >= 0);
}

BattleShip::Cell &BattleShip::Board::at(int row, int col) {
  return boardState[row][col];
}

const BattleShip::Cell &BattleShip::Board::at(int row, int col) const {
  return boardState[row][col];
}
bool BattleShip::Board::inBounds(const ShipPlacement &shipPlacement) const {
  return inBounds(shipPlacement.rowStart, shipPlacement.colStart) && inBounds(shipPlacement.rowEnd, shipPlacement.colEnd);
}
bool BattleShip::Board::between(int value, int low, int high) const {
  return value >= low && value <= high;
}
bool BattleShip::Board::spacesAreEmpty(const ShipPlacement &shipPlacement) const {
  int row = shipPlacement.rowStart;
  while (row < shipPlacement.rowEnd + 1) {
    int col = shipPlacement.colStart;
    while (col < shipPlacement.colEnd + 1) {
      if(boardState[row][col].containsShip()){
        return false;
      }
      col++;
    }
    row++;
  }
  return true;
}
