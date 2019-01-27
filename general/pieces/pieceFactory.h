#ifndef PIECEFACTORY_H
#define PIECEFACTORY_H

#include "piecesheaders.h"

class PieceFactory {
private:
public:
  Piece *createPiece(std::string pieceType, Player *player);
  Piece *createBishop(Player *player);
  Piece *createKing(Player *player);
  Piece *createKnight(Player *player);
  Piece *createPawn(Player *player);
  Piece *createQueen(Player *player);
  Piece *createRook(Player *player);
  PieceFactory() {}
  virtual ~PieceFactory() {}
};

#endif /* PIECEFACTORY_H */
