#ifndef PIECES_DRAWINGS_H
#define PIECES_DRAWINGS_H

#include <array>

#include "board/board_window/board_pane/board_drawings.hpp"
#include "board/board_window/board_pane/pieces/piece_drawing.hpp"
#include "board/position/position_utils.h"
#include "ui_components/box_modifier.hpp"

class PiecesDrawings {
 public:
  PiecesDrawings() {
    std::unique_ptr<PieceDrawing> piece_drawing;
    BoxModifier::FGColor drawing_color_mod_fg;
    bool is_black_piece;

    for (const Piece &p : {bP, bR, bN, bB, bQ, bK, wP, wR, wN, wB, wQ, wK}) {
      piece_drawing = draw_piece(p);
      is_black_piece = utils::check::is_black_piece(p);
      drawing_color_mod_fg = fg_side_color(is_black_piece);

      BoxModifier::add_fg_color(drawing_color_mod_fg,
                                &piece_drawing->get_drawing());
      m_pieces[p] = std::move(piece_drawing);
    }
  }

  virtual ~PiecesDrawings() = default;

  std::unique_ptr<IPieceDrawing> new_piece_drawing(const Piece &m_type) { 
    return m_pieces[m_type]->clone();
  }

 private:
  std::map<Piece, PieceType> m_pieces_type{
      {Piece::wP,   PieceType::PAWN},
      {Piece::bP,   PieceType::PAWN},
      {Piece::wR,   PieceType::ROOK},
      {Piece::bR,   PieceType::ROOK},
      {Piece::wN,   PieceType::KNIGHT},
      {Piece::bN,   PieceType::KNIGHT},
      {Piece::wB, PieceType::BISHOP},
      {Piece::bB, PieceType::BISHOP},
      {Piece::wQ,  PieceType::QUEEN},
      {Piece::bQ,  PieceType::QUEEN},
      {Piece::wK,   PieceType::KING},
      {Piece::bK,   PieceType::KING},
  };

  std::unique_ptr<PieceDrawing> draw_piece(Piece piece) {
    PieceType pct = m_pieces_type.at(piece);
    return std::make_unique<PieceDrawing>(BoardDrawings::Pieces::Kpieces.at(pct), piece);
  }

  BoxModifier::FGColor fg_side_color(bool is_black_piece) {
    return is_black_piece ? BoxModifier::BLACK_FG : BoxModifier::WHITE_FG;
  }

  std::array<std::unique_ptr<PieceDrawing>, utils::constant::ktotal_number_pieces> m_pieces;
};

#endif /* PIECES_DRAWINGS_H */
