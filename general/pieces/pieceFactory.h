#ifndef PIECEFACTORY_H
#define PIECEFACTORY_H

#include "piecesheaders.h"

class PieceFactory {
private:
  PiecesSetPtr allPieces;
  PiecesSetPtr blackPieces;
  PiecesSetPtr whitePieces;
  PiecesSetPtr nullPieces = {nullptr};

public:
  Piece *createPiece(std::string type, std::string color);
  PiecesSetPtr getPieces(std::string);

  Piece *createBishop(std::string colorPiece);
  Piece *createKing(std::string colorPiece);
  Piece *createKnight(std::string colorPiece);
  Piece *createPawn(std::string colorPiece);
  Piece *createQueen(std::string colorPiece);
  Piece *createRook(std::string colorPiece);
  PieceFactory() {}
  virtual ~PieceFactory() {}
};

#endif /* PIECEFACTORY_H */
