#ifndef SQUARE_H
#define SQUARE_H

#include "boxStruct.h"
#include "piece.h"
#include <iostream>

#pragma once

class Square {
private:
  box *pBaseDrawing;
  box *pCurrentDrawing;
  Position currentPos;
  Piece *pPiece = nullptr;
  bool occupied = false;
  bool blackBox;

public:
  Square(box *, bool, Position);
  virtual ~Square();

  void setPiece(Piece *piece);
  void clearSquare();
  bool hasPiece() { return occupied; }
  bool isBlackBox();
  Piece *removePiece();
  Piece *getPiece();
  box *getCurrentDrawing();
};

#endif /* SQUARE_H */
