#ifndef BATTLESHIP__CELL_H_
#define BATTLESHIP__CELL_H_
namespace BattleShip {
class Cell {
 public:
  Cell(char contents, const char hiddenMarker, const char hitMarker, const char missMarker);
  Cell(char contents);
  char getContents() const;
  void setContents(char contents);
  char getContentsIfHidden() const;
  char getContentsIfVisible() const;
  bool HasBeenFiredAt() const;
  void setHasBeenFiredAt(bool hasBeenFiredAt);
  bool containsShip()const;
 protected:
  char contents;
  bool firedAt;
  const char hiddenMarker;
  const char hitMarker;
  const char missMarker;
};
}
#endif
