#include "pieceFactory.h"

Piece *PieceFactory::createPiece(std::string pieceType, Player *player) {
  Piece *piece = nullptr;

  if (pieceType == "pawn")
    piece = createPawn(player);
  else if (pieceType == "rook")
    piece = createRook(player);
  else if (pieceType == "queen")
    piece = createQueen(player);
  else if (pieceType == "king")
    piece = createKing(player);
  else if (pieceType == "bishop")
    piece = createBishop(player);
  else if (pieceType == "knight")
    piece = createKnight(player);
  else
    std::cout << "Piece " << pieceType << " not created" << std::endl;

  return piece;
}
Piece *PieceFactory::createBishop(Player *player) { return new Bishop(player); }
Piece *PieceFactory::createKing(Player *player) { return new King(player); }
Piece *PieceFactory::createKnight(Player *player) { return new Knight(player); }
Piece *PieceFactory::createPawn(Player *player) { return new Pawn(player); }
Piece *PieceFactory::createQueen(Player *player) { return new Queen(player); }
Piece *PieceFactory::createRook(Player *player) { return new Rook(player); }
