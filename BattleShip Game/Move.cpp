#include "Move.h"

BattleShip::Move::~Move() = default;
BattleShip::Move::Move(BattleShip::Player& moveMaker) : moveMaker(moveMaker) {}