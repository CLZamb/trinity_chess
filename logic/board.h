// File: board.h
#ifndef BOARD_H
#define BOARD_H

#pragma once

#include "box.h"
#include "display.h"
#include "piecesheaders.h"
#include "position.h"
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
  Box *board[8][8];
  box wBox, bBox;
  Player *player1, *player2;

  void createBoardBoxes();
  void createBoxBases();
  void setPiecesOnBoard();
  void setPieceAtPos(Piece *piece, Position pos);
  bool isValidPosition(Position pos);
  Piece *createPiece(std::string, Player *);
  Box *getBoxAtPos(Position);

public:
  Board();
  ~Board();

  bool isValidMove(Player *, Position, Position);
  void initialize(Player *, Player *);
  void movePiece(Position from, Position to);
  // print Board
  void print();
  void changeTurn();
  Piece *getPieceAtPos(Position);
};

#endif /* BOARD_H */
