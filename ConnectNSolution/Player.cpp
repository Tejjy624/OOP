#include "Player.h"
#include "Model.h"
#include "View.h"
#include "Move.h"

ConnectNGame::Player::Player() : name("unnamed"), piece('\0'){}

ConnectNGame::Move ConnectNGame::Player::getMove(ConnectNGame::Model& model, ConnectNGame::View& view) {
  Move move(*this);
  do {
    int playColumn = view.getPlayColumn(*this);
    move.setCol(playColumn);
  } while (!move.isValid(model));
  return move;
}

const std::string& ConnectNGame::Player::getName() const {
  return name;
}

char ConnectNGame::Player::getPiece() const {
  return piece;
}

void ConnectNGame::Player::setName(const std::string& name) {
  Player::name = name;
}

void ConnectNGame::Player::setPiece(char piece) {
  Player::piece = piece;
}


