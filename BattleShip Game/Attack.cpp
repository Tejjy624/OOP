#include "Attack.h"
#include <iostream>
BattleShip::Attack::Attack(BattleShip::Player &attacker, int row, int col) : Move(attacker), row(row), col(col){
}
//checks for valid attack
bool BattleShip::Attack::isValid() const {
    return getRow() < 0 || getRow() > moveMaker.getBoard().getNumRows()
           || getCol() < 0 || getCol() > moveMaker.getBoard().getNumCols();
}
//gets the row
const int BattleShip::Attack::getRow() const {
    return row;
}
//gets the column
const int BattleShip::Attack::getCol() const {
    return col;
}
//sets up the board firing positions
void BattleShip::Attack::enact(BattleShip::Model &model, BattleShip::View &view) {
  AttackResult attackResult = this->moveMaker.fireAt(row, col);
  std::cout << this->moveMaker.getName() << "'s Firing Board" << std::endl;
    view.PlayerBoard(moveMaker.getOpponent());
  std::cout << std::endl << std::endl;
  std::cout << this->moveMaker.getName() << "'s Placement Board" << std::endl;
    view.BoardPlacement(moveMaker);
    view.AttackResult(moveMaker, attackResult);
}
