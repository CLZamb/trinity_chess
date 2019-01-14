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

public:
  Position pos;
  explicit Piece(Player *side);
  virtual ~Piece();

  virtual box *getDrawingA() { return nullptr; }
  virtual box *getDrawingB() { return nullptr; }
  virtual bool isValidMove(Position, Position) { return false; }

  Position *getPosition();
  // void pieceDrawing();
  Player *getOwner() { return pPlayer; }
};

#endif /* PIECE_H */
