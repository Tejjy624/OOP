#ifndef BATTLESHIP__MOVE_H_
#define BATTLESHIP__MOVE_H_
#include "Player.h"
#include "Model.h"
#include "View.h"

namespace BattleShip {
class Player;
class AiPlayer;
class HumanPlayer;
class Model;
class View;

class Move {
 public:
    Move(Player& moveMaker);
    virtual void enact(Model& model, View& view) = 0;
    virtual bool isValid() const = 0;
    virtual ~Move();
 protected:
    Player& moveMaker;
};
}

#endif
