// File: pawn.h
#ifndef PAWN_H
#define PAWN_H

#pragma once

#include "boxStruct.h"
#include "piece.h"

class Pawn : public Piece {
private:
  int oneSpaceForward = 0;
  bool firstMove = true;
  static box PawnWhiteBoxP2;
  static box PawnWhiteBoxP1;
  static box PawnBlackBoxP2;
  static box PawnBlackBoxP1;

public:
  explicit Pawn(Player *side);
  virtual ~Pawn();
  bool checkMove(Position, Position);
  std::string getPieceType() { return "pawn"; }
};

#endif /* PAWN_H */
