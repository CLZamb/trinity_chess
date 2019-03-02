// File: board.h
#ifndef BOARD_H
#define BOARD_H

#pragma once

#include "Idisplay.h"
#include "bitboard.h"
#include "player.h"
#include <iostream>
#include <string>
#include <utility> // std::pair, std::make_pair
#include <vector>

class Board : public IDisplay {
private:
  // PieceFactory piecefactory;
  Player *player1, *player2;
  box wSquare, bSquare;
  Bitboard m_bb;

  void addToBoard(string type, int position, string color);
  void createBoardSquares();
  void createSquareBases();
  void setPiecesOnBoard();

  class Square {
    private:
      box *pBaseDrawing;
      box *pCurrentDrawing;
      const int squarePos;
      Piece *pPiece = nullptr;
      bool occupied = false;
      bool blackBox;

    public:
      Square(box *, bool, int position);
      virtual ~Square();

      char* getContent(int i);
      void setPiece(Piece *piece);
      void clearSquare();
      bool hasPiece() { return occupied; }
      bool isBlackBox();
      Piece *getPiece();
      box *getCurrentDrawing();
  };

  Square *board[64] = {nullptr};

public:
  Board();
  ~Board();

  Square *getSquareAtPos(int pos);
  U64 rookAttacks(U64 occ, SquareIndices sq) { return m_bb.rookAttacks(occ, sq); }
  U64 getPieceAttacks(Piece *piece, SquareIndices from);
  U64 getNonAttackMoves(Piece *piece, SquareIndices from);
  bool isPieceAt(int pos);
  void initialize(Player *, Player *);
  void clearSquareAt(int pos);
  void saveCapturedPiece(Piece *);
  void make_move(Piece*, int from, int to);
  std::string get_str_type(int type);
  // print Board
  void print();

  Piece *getPieceAtPos(int);
  U64 getPiecesBB(int pieceType);
  U64 getOwnPiecesOcc(std::string side) {
    if (side == "black")
      return m_bb.m_allBlackPieces;

    return  m_bb.m_allWhitePieces;
  }

  U64 getAllWhitePieces() { return m_bb.m_allWhitePieces; }
  U64 getAllBlackPieces() { return m_bb.m_allBlackPieces; }
  void generateAllMoves(std::string side, MoveList *moveList) {
    return m_bb.generateAllMoves(side, moveList);
  }

  void undo_move(int pieceType, int pos);
  void capture_piece(Piece* p, int pos);
  int evalPosition() { return m_bb.evaluateBoard(); }
};

#endif /* BOARD_H */
