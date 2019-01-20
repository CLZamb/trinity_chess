// File: pawn.h
#ifndef PAWN_H
#define PAWN_H

#pragma once

#include "boxStruct.h"
#include "piece.h"

class Pawn : public Piece {
private:
  bool firstMove = true;
  static box PawnWhiteBoxP2;
  static box PawnWhiteBoxP1;
  static box PawnBlackBoxP2;
  static box PawnBlackBoxP1;

public:
  explicit Pawn(Player *side);
  virtual ~Pawn();
  box *getDrawingWSquare();
  box *getDrawingBSquare();
  bool checkMove(Position, Position);
};

#endif /* PAWN_H */
