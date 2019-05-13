// File: pawn.h
#ifndef PAWN_H
#define PAWN_H

#pragma once
#include "piece.h"

class Pawn : public Piece {
 private:
  IDrawing* w_sq_drawing = new WhiteSquare(new PieceDrawing("pawn"));
  IDrawing* b_sq_drawing = new PieceDrawing("pawn");

 public:
    explicit Pawn(bool black, U64);
    virtual ~Pawn();
};
#endif /* PAWN_H */
