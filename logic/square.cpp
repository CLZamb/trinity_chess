#include "square.h"

Square::Square(box *baseDrawing, bool blackBox, Position pos)
    : pBaseDrawing(baseDrawing), pCurrentDrawing(baseDrawing), currentPos(pos),
      blackBox(blackBox) {}

Square::~Square() {}

void Square::setPiece(Piece *piece) {
  occupied = true;
  this->pPiece = piece;
  *this->pPiece->getPosition() = currentPos;

  if (blackBox)
    pCurrentDrawing = pPiece->getDrawingB();
  else
    pCurrentDrawing = pPiece->getDrawingA();
}

Piece *Square::removePiece() {
  Piece *removedPiece = pPiece;
  pPiece = nullptr;

  return removedPiece;
}

void Square::clearSquare() {
  occupied = false;
  pCurrentDrawing = pBaseDrawing;
  pPiece = nullptr;
}

box *Square::getCurrentDrawing() { return pCurrentDrawing; }
Piece *Square::getPiece() { return this->pPiece; }
bool Square::isBlackBox() { return blackBox; }

// Implementation of [] operator.  This function must return a
// refernce as array element can be put on left side
