#include "Move.h"
#include "Model.h"

ConnectNGame::Move::Move(const Player& maker) : col(-17), maker(maker) {}

bool ConnectNGame::Move::isValid(const Model& model) const {
  return model.getBoard().canAddPieceTo(col);
}

void ConnectNGame::Move::make(ConnectNGame::Model& model) {
  model.addPiece(maker.getPiece(), col);
}

void ConnectNGame::Move::setCol(int col) {
  Move::col = col;
}



