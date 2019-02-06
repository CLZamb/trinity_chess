#include "pieceFactory.h"

Piece *PieceFactory::createPiece(std::string type, std::string color,
                                 Position pos) {
  Piece *piece = nullptr;

  if (type == "pawn")
    piece = createPawn(color, pos);
  else if (type == "rook")
    piece = createRook(color);
  else if (type == "queen")
    piece = createQueen(color);
  else if (type == "king")
    piece = createKing(color);
  else if (type == "bishop")
    piece = createBishop(color);
  else if (type == "knight")
    piece = createKnight(color);
  else
    std::cout << "Piece " << type << " not created" << std::endl;

  allPieces.push_back(piece);
  if (color == "white")
    blackPieces.push_back(piece);
  else if (color == "black")
    whitePieces.push_back(piece);

  return piece;
}

PiecesSetPtr PieceFactory::getPieces(std::string colorPieces) {
  if (colorPieces == "white")
    return blackPieces;
  else if (colorPieces == "black")
    return whitePieces;
  else if (colorPieces == "all")
    return allPieces;
  else
    return nullPieces;
}

Piece *PieceFactory::createBishop(std::string colorPiece) {
  return new Bishop(colorPiece);
}
Piece *PieceFactory::createKing(std::string colorPiece) {
  return new King(colorPiece);
}
Piece *PieceFactory::createKnight(std::string colorPiece) {
  return new Knight(colorPiece);
}
Piece *PieceFactory::createPawn(std::string colorPiece, Position initial) {
  return new Pawn(colorPiece, initial);
}
Piece *PieceFactory::createQueen(std::string colorPiece) {
  return new Queen(colorPiece);
}
Piece *PieceFactory::createRook(std::string colorPiece) {
  return new Rook(colorPiece);
}
