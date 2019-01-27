#ifndef PIECE_H
#define PIECE_H
// #include "../logic/board.h"
// #include "../display/display.h"
// #include "../logic/box.h"
#include "AiPlayer.h"
#include "boxStruct.h"
#include "player.h"
#include "position.h"

class Piece {
private:
protected:
  Player *pPlayer;
  bool capturing = false;

public:
  Position pos;
  box *pieceCurrentBlackBox = nullptr;
  box *pieceCurrentWhiteBox = nullptr;

  explicit Piece(Player *side);
  virtual ~Piece();

  virtual box *getDrawingBSquare() { return pieceCurrentBlackBox; }
  virtual box *getDrawingWSquare() { return pieceCurrentWhiteBox; }
  virtual bool checkMove(Position, Position) { return false; }
  virtual std::string getPieceType() { return ""; }

  Position *getPosition();
  Player *getOwner() { return pPlayer; }
  bool isCapturing() { return capturing; }
  void setCapturingState(bool capturing) { this->capturing = capturing; }
};

#endif /* PIECE_H */
