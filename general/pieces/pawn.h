// File: pawn.h
#ifndef PAWN_H
#define PAWN_H

#pragma once
#include "piece.h"

class Pawn : public Piece {
private:
  int oneSpaceForward = 0;
  static box PawnWhiteBoxP2;
  static box PawnWhiteBoxP1;
  static box PawnBlackBoxP2;
  static box PawnBlackBoxP1;
  bool isFirstMove();

public:
  explicit Pawn(std::string pieceColor, U64);
  virtual ~Pawn();
  std::string getPieceType() { return "pawn"; }
};

#endif /* PAWN_H */
