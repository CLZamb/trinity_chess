#ifndef PIECE_H
#define PIECE_H
#include "boxStruct.h"
#include <iostream>
#include <string>
#include <vector>
#include "../defs.h"

class Piece {
 protected:
  U64 SetMask[64];
  U64 ClearMask[64];
  U64 m_bitboard;
  Piecetype m_type = EMPTY;
  box* p_cur_b_sq_drawing = nullptr;
  box* p_cur_w_sq_drawing = nullptr;
  bool black = false;
  int m_value = 0;

 public:
  explicit Piece(bool is_black, U64 bb);
  virtual ~Piece();
  box* get_drawing_square(bool is_black);
  virtual box* get_drawing_B_square();
  virtual box* get_drawing_W_square();
  virtual Piecetype get_type_and_color();
  virtual std::string get_type();
  virtual int get_value();
  void clear_bit(int pos);
  void set_bit(int pos);
  void make_move(int from, int to);

  U64 get_bitboard();
  bool is_black();
};

#endif /* PIECE_H */
