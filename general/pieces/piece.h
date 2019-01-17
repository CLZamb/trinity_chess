#ifndef PIECE_H
#define PIECE_H
// #include "../logic/board.h"
// #include "../display/display.h"
// #include "../logic/box.h"
#include "boxStruct.h"
#include "player.h"
#include "position.h"
// #include <string>

class Piece {
private:
protected:
  Player *pPlayer;
  bool capturing = false;
  bool knight = false;
  bool king = false;

public:
  Position pos;
  explicit Piece(Player *side);
  virtual ~Piece();

  virtual box *getDrawingA() { return nullptr; }
  virtual box *getDrawingB() { return nullptr; }
  virtual bool checkMove(Position, Position) { return false; }

  Position *getPosition();
  // void pieceDrawing();
  Player *getOwner() { return pPlayer; }
  bool isCapturing() { return capturing; }
  bool isKnight() { return knight; }
  bool isKing() { return king; }
  void setCapturingState(bool capturing) { this->capturing = capturing; }
};

#endif /* PIECE_H */
