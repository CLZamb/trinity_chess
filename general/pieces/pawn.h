// File: pawn.h
#ifndef PAWN_H
#define PAWN_H

#pragma once

#include "boxStruct.h"
#include "piece.h"

class Pawn : public Piece {
private:
  static box pawnA;
  static box pawnB;

public:
  explicit Pawn(Player *side);
  virtual ~Pawn();
  box *getDrawingA();
  box *getDrawingB();
  bool checkMove(Position, Position);
};

#endif /* PAWN_H */
