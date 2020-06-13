#ifndef PIECE_H
#define PIECE_H

// #include <string>
// #include "bitUtilities.hpp"
#include "../../../include/common/headers/common.h"
// #include "utils.h"
#include "box.h"
#include "drawing.hpp"
#include "utils.h"

class Piece {
  public:
    explicit Piece(Piecetype pct);
    virtual ~Piece();
  //   void clear_bit(SquareIndices pos);
  //   void set_bit(SquareIndices pos);
  //   void make_move(SquareIndices from, SquareIndices to);
  //   void clear_bitboard();
    void create_piece_drawing(Piecetype);
  //   void set_material_score(Piecetype);
  //   int get_material_score();
    bool is_black();
    box* get_drawing(bool is_black);
  //   Piecetype get_type_and_color();
  //   U64 get_bitboard();
  //
  // private:
    bool black = false;
  //   int m_material_score = 0;
  //   U64 m_bitboard = BLANK;
    Piecetype m_type = EMPTY;
    Drawing* w_sq_drawing = nullptr;
    Drawing* b_sq_drawing = nullptr;
};

#endif /* PIECE_H */
