#ifndef BATTLESHIP__HUMANPLAYER_H_
#define BATTLESHIP__HUMANPLAYER_H_
#include "Player.h"
#include "View.h"
#include "GameAttributes.h"
namespace BattleShip {
    class HumanPlayer : public Player {
    public:
        HumanPlayer(const GameAttributes& gameAttributes, View& view);
        virtual std::unique_ptr<BattleShip::Move> getMove() override;
        virtual void placeShips() override;
        virtual void initializeName() override;
    protected:
    };
    class Move;
}
#endif
