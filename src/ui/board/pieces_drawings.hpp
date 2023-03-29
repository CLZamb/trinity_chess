#ifndef DRAWINGS_H
#define DRAWINGS_H

#include <array>
#include "standard_pieces_drawing_builder.hpp"

class PiecesDrawings {
 public:
  PiecesDrawings() {
    const Piecetype NodePositionVector[] = {
      bP, bR, bN, bB, bQ, bK,
      wP, wR, wN, wB, wQ, wK
    };

    for (const Piecetype &pct : NodePositionVector) {
      drawing = m_drawing_builder.build_drawing(pct);
      piece_drawing_mod_fg = utils::check::is_black_piece(pct)
        ? BoxModifier::BLACK_FG
        : BoxModifier::WHITE_FG;

      piece_drawing_mod_black_square_bg = utils::check::is_black_piece(pct)
        ? BoxModifier::BLACK_BG_BLACK_SQUARE
        : BoxModifier::WHITE_BG_BLACK_SQUARE;

      piece_drawing_mod_white_square_bg = utils::check::is_black_piece(pct)
        ? BoxModifier::BLACK_BG_WHITE_SQUARE
        : BoxModifier::WHITE_BG_WHITE_SQUARE;

      drawing->set_fg_color_modifier(piece_drawing_mod_fg);
      drawing->set_bg_color_modifier(piece_drawing_mod_white_square_bg, piece_drawing_mod_black_square_bg);

      m_pieces[pct] = drawing;
    }
  }

  virtual ~PiecesDrawings() {}

  Box* get_drawing(const Piecetype &m_type, bool is_in_black_square) {
    return m_pieces[m_type]->get_drawing(is_in_black_square);
  }

  private:
    BoxModifier::Color piece_drawing_mod_fg;  
    BoxModifier::Color piece_drawing_mod_black_square_bg;  
    BoxModifier::Color piece_drawing_mod_white_square_bg;  
    PieceDrawing *drawing; 
    StandardPiecesDrawingBuilder m_drawing_builder;
    std::array<PieceDrawing*, utils::constant::ktotal_number_pieces> m_pieces;
};

#endif /* DRAWINGS_H */
