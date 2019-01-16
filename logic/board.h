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
  // Input input;
  char side = 'w';

  void createBoardBoxes();
  void createBoxBases();
  void setPiecesOnBoard();
  Piece *createPiece(std::string, Player *);

public:
  Board();
  ~Board();
  Player *player1, *player2, *playerTurn;

  void setPieceAtPos(Piece *piece, Position pos);
  Box *getBoxAtPos(Position);
  string getTurn();
  void initialize(Player *, Player *);
  void setTurn(char side);
  // print Board
  void print();
  void changeTurn();

  bool isValidPosition(Position pos);
  Piece *getPieceAtPos(Position);
};

#endif /* BOARD_H */
