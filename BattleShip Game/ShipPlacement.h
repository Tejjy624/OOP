#ifndef BATTLESHIP__SHIPPLACEMENT_H_
#define BATTLESHIP__SHIPPLACEMENT_H_
class ShipPlacement {
 public:
  ShipPlacement();
  ShipPlacement(int rowStart, int colStart, int rowEnd, int colEnd);
  int rowStart, colStart;
  int rowEnd, colEnd;
 protected:
  void normalize();
};

#endif
