#ifndef PIECE_H
#define PIECE_H

#include <array>
#include <string>
// #include "bitUtilities.hpp"
#include "../../include/common/headers/common.h"
// #include "utils.h"
#include "../../board/headers/box.h"
#include "pieces_drawings.hpp"
#include "../../board/headers/utils.h"
#include "../../headers/move.h"
#include "../../board/headers/bit_utilities.h"

using namespace bitUtility;


class Piece {
 public:
    virtual ~Piece();
    bool is_black();
    box* get_box_drawing(bool is_black);
    Piecetype get_type_and_color();
    bool is_black_piece(int pct);
    virtual bool is_legal_move(const Move&) = 0;

 protected:
    explicit Piece(const Piecetype&);
    PieceDrawing* create_drawing(const Piecetype& m_type);
    U64 m_attacks[utils::constant::ksquares] = { BLANK };

 private:
    StandardDrawingBuilder drawing_builder;
    Piecetype m_type;
    bool black = false;
    PieceDrawing* p_piece_drawing;
};


class Pieces {
 public:
    Pieces();
    virtual ~Pieces();

  // for (auto p : m_pieces)
  //   delete p;
 private:
  // std::array<Piece*, 13> m_pieces {
  //   nullptr,  // EMPTY 0
  //     // black pieces
  //
  //   new Pawn<BLACK>(),
  //   new Pawn<BLACK>(),
  //   new Pawn<BLACK>(),
  //   new Pawn<BLACK>(),
  //   new Pawn<BLACK>(),
  //   new Pawn<BLACK>(),
  //   // new Piece(bR),
  //   // new Piece(bN),
  //   // new Piece(bB),
  //   // new Piece(bQ),
  //   // new Piece(bK),
  //   // // white pieces
  //   new Pawn<WHITE>(),
  //   new Pawn<WHITE>(),
  //   new Pawn<WHITE>(),
  //   new Pawn<WHITE>(),
  //   new Pawn<WHITE>(),
  //   new Pawn<WHITE>(),
  //   // new Piece(wR),
  //   // new Piece(wN),
  //   // new Piece(wB),
  //   // new Piece(wQ),
  //   // new Piece(wK),  // 12
  // };
};

#endif /* PIECE_H */
