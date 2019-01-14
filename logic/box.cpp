#include "box.h"

Box::Box(box *baseDrawing, bool blackBox, Position pos)
    : pBaseDrawing(baseDrawing), pCurrentDrawing(baseDrawing), currentPos(pos),
      blackBox(blackBox) {}

Box::~Box() {}

void Box::setPiece(Piece *piece) {
  occupied = true;
  this->pPiece = piece;
  *this->pPiece->getPosition() = currentPos;

  if (blackBox)
    pCurrentDrawing = pPiece->getDrawingB();
  else
    pCurrentDrawing = pPiece->getDrawingA();
}

void Box::removePiece() {
  occupied = false;
  pCurrentDrawing = pBaseDrawing;
  pPiece = nullptr;
}

box *Box::getCurrentDrawing() { return pCurrentDrawing; }
Piece *Box::getPiece() { return this->pPiece; }
bool Box::isBlackBox() { return blackBox; }

// Implementation of [] operator.  This function must return a
// refernce as array element can be put on left side
