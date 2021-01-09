#include <algorithm>
#include <vector>
#include <cctype>
#include "StandardView.h"
#include "Utility.h"
//gets user input to place ships on every board
ShipPlacement BattleShip::StandardView::getShipPlacement(const BattleShip::Player &player, char shipChar, int shipLen) {
    char orientationChar;
    do {
        out << player.getName() << ", do you want to place " << shipChar << " horizontally or vertically?" << std::endl;
        out << "Enter h for horizontal or v for vertical" << std::endl;
        out << "Your choice: " << std::endl;
        in >> orientationChar;
    } while (orientationChar != 'h' && orientationChar != 'v');

    int rowStart = 0, colStart = 0;
    int rowEnd = 0, colEnd = 0;
    do {
        out << player.getName() << ",  enter the row and column you want to place " << shipChar << ", which is " << shipLen
            << " long, at with a space in between row and col: " << std::endl;
        in >> rowStart >> colStart;
    } while (rowStart < 0 || rowStart > player.getBoard().getNumRows() || colStart < 0 || colStart > player.getBoard().getNumCols());

    if (orientationChar == 'h') {
        rowEnd = rowStart;
        colEnd = colStart + shipLen - 1;
        return ShipPlacement(rowStart, colStart, rowEnd, colEnd);
    } else {
        rowEnd = rowStart + shipLen - 1;
        colEnd = colStart;
        return ShipPlacement(rowStart, colStart, rowEnd, colEnd);
    }
}
BattleShip::StandardView::StandardView(): in(std::cin), out(std::cout) {
}
BattleShip::StandardView::StandardView(std::istream &in, std::ostream &out) :in(in), out(out) {
}
//gets the type of game along with players
BattleShip::PlayerConfiguration BattleShip::StandardView::getPlayerConfiguration() {
  out << "What type of game do you want to play?" << std::endl;
  out << "1. Human vs Human" << std::endl;
  out << "2. Human vs AI" << std::endl;
  out << "3. AI vs AI" << std::endl;
  out << "Your choice: " << std::endl;
  int choice;
  in >> choice;
  if (choice == 1) {
    return PlayerConfiguration(2, 0);
  } else if (choice == 2) {
    return PlayerConfiguration(1, 1);
  } else {
    return PlayerConfiguration(0, 2);
  }
}
std::string BattleShip::StandardView::getPlayerName(int i) {
  return std::string();
}

void BattleShip::StandardView::updateShipPlacementView(const BattleShip::Player &player) {
  printBoard(player.getBoard().getVisibleVersion());
}
std::pair<int, int> BattleShip::StandardView::Coordinates(const BattleShip::Player &attacker) {
  std::pair<int, int> cellLocation;
  do {
    out << attacker.getName() << ", where would you like to fire? " << std::endl;
    out << "Enter your attack coordinate in the form row col: " << std::endl;
    in >> cellLocation.first >> cellLocation.second;
  } while (cellLocation.first < 0 || cellLocation.first > attacker.getBoard().getNumRows()
      || cellLocation.second < 0 || cellLocation.second > attacker.getBoard().getNumCols());

  return cellLocation;
}
void BattleShip::StandardView::Winner(const BattleShip::Player &winner) {
  out << winner.getName() << " won the game!" << std::endl;
}
//result of attacked space
void BattleShip::StandardView::AttackResult(const BattleShip::Player &attacker,
                                            const BattleShip::AttackResult &attackResult) {
  if(!attackResult.hit){
    out << "Missed." << std::endl << std::endl;
  } else if(attackResult.hit && !attackResult.destroyed){
    out << attacker.getName() << " hit " << attacker.getOpponent().getName() << "'s "
        << attackResult.shipChar << "!" << std::endl<< std::endl;
  } else if (attackResult.hit && attackResult.destroyed){
    out << attacker.getName() << " hit " << attacker.getOpponent().getName() << "'s "
        << attackResult.shipChar << "!" << std::endl;
    out << attacker.getName() << " destroyed " << attacker.getOpponent().getName() << "'s "
        << attackResult.shipChar << "!" << std::endl<< std::endl;
  }
}
void BattleShip::StandardView::PlayerBoard(const BattleShip::Player &player) {
  printBoardAsObscured(player.getBoard());
}
void BattleShip::StandardView::BoardPlacement(const BattleShip::Player &player) {
  printBoardAsVisible(player.getBoard());
}
//show the board to players
void BattleShip::StandardView::printBoard(const std::vector<std::string> &board) {
  out << ' ';
  out << ' ';
  for (unsigned int i = 0; i < board.size(); ++i) {
    out << i << ' ';
  }
  out << std::endl;
  int counter = -1;
  for(const auto& row : board){
    counter++;
    out << counter << ' ';
    for(const auto & elem : row){
      out << elem << ' ';
    }
    out << std::endl;
  }
}
void BattleShip::StandardView::clearInput() {
}
void BattleShip::StandardView::printBoardAsVisible(const BattleShip::Board &board) {
  printBoard(board.getVisibleVersion());
}
void BattleShip::StandardView::printBoardAsObscured(const BattleShip::Board &board) {
  printBoard(board.getHiddenVersion());
}
//choose the ai that will be playing
int BattleShip::StandardView::ChooseAI() {
  int AiChoice;
  do{
    out << "What AI do you want?" << std::endl;
    out << "1. Cheating AI" << std::endl;
    out << "2. Random AI" << std::endl;
    out << "3. Hunt Destroy AI" << std::endl;
    out << "Your choice: " << std::endl;
    in >> AiChoice;
  } while (AiChoice < 0 || AiChoice > 3);
  return AiChoice;
}


