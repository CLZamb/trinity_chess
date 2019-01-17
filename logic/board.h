// File: board.h
#ifndef BOARD_H
#define BOARD_H

#pragma once

#include "display.h"
#include "piecesheaders.h"
#include "position.h"
#include "square.h"
#include <iostream>
#include <string>
#include <vector>

/*
 * @class take care of the position
 * on the board  such that the board konws
 * every position aviliable and what position can be used
 * and where are all the pieces
 * o*/
class Board : public Display {
private:
  // static Board *m_mainBoard;
  Square *board[8][8] = {{nullptr}};

  box wBox, bBox;
  // Input input;

  void createBoardSquares();
  void createSquareBases();
  void setPiecesOnBoard();
  Piece *createPiece(std::string, Player *);
  std::vector<Piece *> capturedPieces;

public:
  Board();
  ~Board();
  Player *player1, *player2, *playerTurn;

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
