#ifndef PIECE_H
#define PIECE_H
#include "drawings.hpp"
#include "boxStruct.h"
#include <iostream>
#include <string>
#include <vector>
#include "../defs.h"

class Piece {
 protected:
  U64 m_bitboard;
  Piecetype m_type = EMPTY;
  box* p_b_sq_drawing = nullptr;
  box* p_w_sq_drawing = nullptr;
  IDrawing* w_sq_drawing = nullptr;
  IDrawing* b_sq_drawing = nullptr;
  bool black = false;
  int m_value = 0;

 public:
  explicit Piece(Piecetype pct, U64 bb);
  virtual ~Piece();
  box* get_drawing(bool is_black);
  Piecetype get_type_and_color();
  int get_value();
  void clear_bit(int pos);
  void set_bit(int pos);
  void make_move(int from, int to);
  void clear_bitboard();
  void create_piece_drawing(Piecetype);
  void set_score(Piecetype);

  U64 get_bitboard();
  bool is_black();
};

#endif /* PIECE_H */
