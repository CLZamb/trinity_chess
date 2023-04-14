#ifndef DRAWINGS_H
#define DRAWINGS_H

#include <array>
#include "standard_pieces_drawing_builder.hpp"

class PiecesDrawings {
public:
  PiecesDrawings() {
    const Piecetype PiecesTypes[] = {
      bP, bR, bN, bB, bQ, bK,
      wP, wR, wN, wB, wQ, wK
    };

    for (const Piecetype &pct : PiecesTypes) {
      drawing = m_piece_drawing_builder.draw_piece(pct);
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

  virtual ~PiecesDrawings() {
    for (auto piece : m_pieces)
      delete piece;
  }

  Box* get_drawing(const Piecetype &m_type, bool is_in_black_square) {
    return m_pieces[m_type]->get_drawing(is_in_black_square);
  }

private:
  BoxModifier::Color piece_drawing_mod_fg;  
  BoxModifier::Color piece_drawing_mod_black_square_bg;  
  BoxModifier::Color piece_drawing_mod_white_square_bg;  
  PieceDrawing *drawing; 
  StandardPiecesDrawing m_piece_drawing_builder;
  std::array<PieceDrawing*, utils::constant::ktotal_number_pieces> m_pieces;
};

#endif /* DRAWINGS_H */
