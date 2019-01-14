#ifndef BOX_H
#define BOX_H

#include "boxStruct.h"
#include "piece.h"
#include <iostream>

#pragma once

class Box {
private:
  box *pBaseDrawing;
  box *pCurrentDrawing /* = (box *)malloc(sizeof(box))*/;
  Position currentPos;
  Piece *pPiece = nullptr;
  bool occupied = false;
  bool blackBox;

public:
  Box(box *, bool, Position);
  virtual ~Box();

  void setPiece(Piece *piece);
  void removePiece();
  bool isBlackBox();
  Piece *getPiece();
  box *getCurrentDrawing();
  bool hasPiece() { return occupied; }
};

#endif /* BOX_H */
