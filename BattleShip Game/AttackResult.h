#ifndef BATTLESHIP__ATTACKRESULT_H_
#define BATTLESHIP__ATTACKRESULT_H_
namespace BattleShip {
class AttackResult {
 public:
  AttackResult(bool hit, bool destroyed, char shipChar);
  bool hit;
  bool destroyed;
  char shipChar;
};
}
#endif
