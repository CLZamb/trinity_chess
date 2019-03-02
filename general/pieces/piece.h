#ifndef PIECE_H
#define PIECE_H
#include "boxStruct.h"
#include "position.h"
#include <iostream>
#include <string>
#include <vector>
#include "../defs.h"

class Piece {
 protected:
  U64 SetMask[64];
  U64 ClearMask[64];
  std::string m_colorPiece;
  bool capturing = false;
  int value = 0;
  U64 m_bbPiece;
  Piecetype m_piece_type = EMPTY;

 public:
  box *pieceCurrentBlackBox = nullptr;
  box *pieceCurrentWhiteBox = nullptr;

  explicit Piece(std::string c, U64 bb);
  virtual ~Piece();

  virtual box *getDrawingBSquare() { return pieceCurrentBlackBox; }
  virtual box *getDrawingWSquare() { return pieceCurrentWhiteBox; }
  virtual std::string getPieceType() { return ""; }
  virtual int getValue() { return value; }
  virtual Piecetype getTypeAndColor() { return m_piece_type; }

  box *getDrawingSquare(char c) { return (c == 'w') ? pieceCurrentBlackBox : pieceCurrentWhiteBox; }

  std::string getColorPiece();
  bool isCapturing() { return capturing; }
  void setCapturingState(bool capturing) { this->capturing = capturing; }
  void make_move(int from, int to) {
    CLRBIT(m_bbPiece, from);
    SETBIT(m_bbPiece, to);
  }
  U64 getPieceBB();
  void clearBit(int pos) { CLRBIT(m_bbPiece, pos); }
  void setBit(int pos) { SETBIT(m_bbPiece, pos); }
};

#endif /* PIECE_H */
