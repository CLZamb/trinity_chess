// File: board.h
#ifndef BOARD_H
#define BOARD_H

#pragma once

#include "Idisplay.h"
#include "piece.h"
#include "pieceFactory.h"
#include "position.h"
#include "square.h"
#include <iostream>
#include <string>
#include <vector>

class Board : public IDisplay {
private:
  Square *board[8][8] = {{nullptr}};

  Player *player1, *player2;
  box wBox, bBox;

  void createBoardSquares();
  void createSquareBases();
  void setPiecesOnBoard();
  std::vector<Piece *> capturedPieces;

public:
  Board();
  ~Board();

  Square *getSquareAtPos(Position);
  void initialize(Player *, Player *);
  void setPieceAtPos(Piece *piece, Position pos);
  void saveCapturedPiece(Piece *);
  // print Board
  void print();

  bool isValidPosition(Position pos);
  Piece *getPieceAtPos(Position);
};

#endif /* BOARD_H */
