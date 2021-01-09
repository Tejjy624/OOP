#include <stdexcept>
#include "Cell.h"

BattleShip::Cell::Cell(char contents, const char hiddenMarker, const char hitMarker, const char missMarker)
    :contents(contents), firedAt(false), hiddenMarker('*'), hitMarker('X'), missMarker('O'){}
    //gets private content
char BattleShip::Cell::getContentsIfHidden() const {
    if (HasBeenFiredAt()) {
        if (containsShip()){
            return hitMarker;
        }else{
            return missMarker;
        }
    } else {
        return hiddenMarker;
    }
}
//gets public content
char BattleShip::Cell::getContentsIfVisible() const {
    if (HasBeenFiredAt()) {
        if (containsShip()){
            return hitMarker;
        }else{
            return missMarker;
        }
    } else {
        return contents;
    }
}
bool BattleShip::Cell::HasBeenFiredAt() const {
    return firedAt;
}
BattleShip::Cell::Cell(char contents): contents(contents), firedAt(false), hiddenMarker('*'), hitMarker('X'), missMarker('O'){}
void BattleShip::Cell::setHasBeenFiredAt(bool hasBeenFiredAt) {
    firedAt = hasBeenFiredAt;
}
bool BattleShip::Cell::containsShip() const {
    return contents >= 'A' && contents <= 'Z' && contents != 'X' && contents != 'O';
}
char BattleShip::Cell::getContents() const {
  return contents;
}
void BattleShip::Cell::setContents(char contents) {
  BattleShip::Cell::contents = contents;
}


