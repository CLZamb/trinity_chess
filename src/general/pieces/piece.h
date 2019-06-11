#ifndef PIECE_H
#define PIECE_H

#include <string>
#include "bitUtilities.hpp"
#include "utils.h"
#include "boxStruct.h"
#include "drawings.hpp"

class Piece {
 public:
  explicit Piece(Piecetype pct, U64 bb);
  virtual ~Piece();
  void clear_bit(SquareIndices pos);
  void set_bit(SquareIndices pos);
  void make_move(SquareIndices from, SquareIndices to);
  void clear_bitboard();
  void create_piece_drawing(Piecetype);
  void set_score(Piecetype);
  int get_value();
  int get_material_score();
  bool is_black();
  box* get_drawing(bool is_black);
  Piecetype get_type_and_color();
  U64 get_bitboard();

 private:
  U64 m_bitboard = BLANK;
  Piecetype m_type = EMPTY;
  PieceDrawing* w_sq_drawing = nullptr;
  PieceDrawing* b_sq_drawing = nullptr;
  bool black = false;
  int m_value = 0;
};

#endif /* PIECE_H */
