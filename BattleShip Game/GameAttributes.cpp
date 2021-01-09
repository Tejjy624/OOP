#include <utility>
#include "Utility.h"
#include "GameAttributes.h"

int BattleShip::GameAttributes::getNumRows() const {
    return numRows;
}
void BattleShip::GameAttributes::setNumRows(int numRows) {
    BattleShip::GameAttributes::numRows = numRows;
}
int BattleShip::GameAttributes::getNumCols() const {
    return numCols;
}
void BattleShip::GameAttributes::setNumCols(int numCols) {
    BattleShip::GameAttributes::numCols = numCols;
}
BattleShip::GameAttributes::GameAttributes(std::istream &in) {
  if (in){
    int numShips = -1;
    verifiedRead(in, numRows);
    verifiedRead(in, numCols);
    verifiedRead(in, numShips);
    char shipChar;
    int shipLen;
    for (int i = 0; i < numShips; ++i) {
      verifiedRead(in, shipChar);
      verifiedRead(in, shipLen);
      shipAttributes.insert(std::make_pair(shipChar, shipLen));
    }
  }
}
int BattleShip::GameAttributes::getShipSize(const char ShipChar) const {
  return shipAttributes.at(ShipChar);
}
const std::map<char, int> &BattleShip::GameAttributes::getShipAttributes() const {
  return shipAttributes;
}
BattleShip::GameAttributes::GameAttributes() = default;
BattleShip::GameAttributes::GameAttributes(int numRows, int numCols) : numRows(numRows), numCols(numCols){}
std::istream &BattleShip::operator>>(std::istream &in, BattleShip::GameAttributes &gameAttributes) {
  gameAttributes = GameAttributes(in);
  return in;
}
