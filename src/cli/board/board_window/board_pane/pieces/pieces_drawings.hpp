#ifndef PIECES_DRAWINGS_H
#define PIECES_DRAWINGS_H

#include "board/board_window/board_pane/board_drawings.hpp"
#include "board/board_window/board_pane/pieces/piece_drawing.hpp"

class PiecesDrawings {
 public:
  std::unique_ptr<PieceDrawing> new_piece_drawing(const Piece &m_type) {
    return m_pieces.at(m_type)();
  }

 private:
  const std::unordered_map<Piece, std::function<std::unique_ptr<PieceDrawing>()>> m_pieces{
    {Piece::wP, [&]() { return draw_piece(PieceType::PAWN, wP); }},
    {Piece::bP, [&]() { return draw_piece(PieceType::PAWN, bP); }},
    {Piece::wR, [&]() { return draw_piece(PieceType::ROOK, wR); }},
    {Piece::bR, [&]() { return draw_piece(PieceType::ROOK, bR); }},
    {Piece::wN, [&]() { return draw_piece(PieceType::KNIGHT, wN); }},
    {Piece::bN, [&]() { return draw_piece(PieceType::KNIGHT, bN); }},
    {Piece::wB, [&]() { return draw_piece(PieceType::BISHOP, wB); }},
    {Piece::bB, [&]() { return draw_piece(PieceType::BISHOP, bB); }},
    {Piece::wQ, [&]() { return draw_piece(PieceType::QUEEN, wQ); }},
    {Piece::bQ, [&]() { return draw_piece(PieceType::QUEEN, wQ); }},
    {Piece::wK, [&]() { return draw_piece(PieceType::KING, wK); }},
    {Piece::bK, [&]() { return draw_piece(PieceType::KING, bK); }},
  };

  auto draw_piece(PieceType pct, Piece piece) -> std::unique_ptr<PieceDrawing> {
    auto piece_drawing = new_piece(pct, piece);
    add_fg_color_based_on_piece_color(piece_drawing, piece);
    return piece_drawing;
  }

  auto new_piece(PieceType pct, Piece piece) -> std::unique_ptr<PieceDrawing>{
    using BoardDrawings::Pieces::Kpieces;
    using std::make_unique;
    return make_unique<PieceDrawing>(Kpieces.at(pct), piece);
  }

  void add_fg_color_based_on_piece_color(
      const std::unique_ptr<PieceDrawing> &drawing, Piece pc) {
    BoxModifier::FGColor color_fg_mod = fg_side_color(pc);
    BoxModifier::add_fg_color(color_fg_mod, &drawing->get_drawing());
  }

  BoxModifier::FGColor fg_side_color(Piece pc) {
    return utils::check::is_black_piece(pc) ? BoxModifier::BLACK_FG
                                            : BoxModifier::WHITE_FG;
  }
};

#endif /* PIECES_DRAWINGS_H */
