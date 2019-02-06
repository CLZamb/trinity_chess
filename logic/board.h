// File: board.h
#ifndef BOARD_H
#define BOARD_H

#pragma once

#include "Idisplay.h"
#include "pieceFactory.h"
#include "player.h"
#include <iostream>
#include <string>
#include <utility> // std::pair, std::make_pair
#include <vector>

class Board : public IDisplay {
private:
  Player *player1, *player2;
  box wBox, bBox;

  void createBoardSquares();
  void createSquareBases();
  void setPiecesOnBoard();

  class Square {
  private:
    box *pBaseDrawing;
    box *pCurrentDrawing;
    const Position squarePos;
    Piece *pPiece = nullptr;
    bool occupied = false;
    bool blackBox;

  public:
    Square(box *, bool, Position);
    virtual ~Square();

    void setPiece(Piece *piece);
    void clearSquare();
    bool hasPiece() { return occupied; }
    bool isBlackBox();
    Piece *getPiece();
    box *getCurrentDrawing();
  };

  Square *board[8][8] = {{nullptr}};

public:
  Board();
  ~Board();

  Square *getSquareAtPos(Position);
  bool isPieceAt(Position pos);
  void initialize(Player *, Player *);
  void clearSquareAt(Position pos);
  void setPieceAtPos(Piece *piece, Position pos);
  void saveCapturedPiece(Piece *);
  // print Board
  void print();

  Piece *getPieceAtPos(Position);
};

#endif /* BOARD_H */
