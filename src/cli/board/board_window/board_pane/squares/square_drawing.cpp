#include "square_drawing.h"

using BM = BoxModifier;
using PtrPieceDrawing = std::unique_ptr<PieceDrawing>;

SquareDrawing::SquareDrawing() {}

Box *SquareDrawing::get_drawing() {
  if (m_has_piece) return &m_pc_drawing->get_drawing();
  return &m_empty_drawing;
}

void SquareDrawing::clear() { m_has_piece = false; }

const char *SquareDrawing::operator[](int row) {
  return get_drawing()->content[row];
}

void SquareDrawing::set_piece_drawing(PtrPieceDrawing &&piece_drawing) {
  m_pc_drawing = std::move(piece_drawing);
  add_side_piece_bg(m_pc_drawing);
  m_has_piece = true;
}

SquareDrawing::PtrPieceDrawing &&SquareDrawing::remove_piece_drawing() {
  if (m_pc_drawing.get() == nullptr) return std::move(m_pc_drawing);

  clear();

  remove_side_piece_bg_mod(m_pc_drawing);
  return std::move(m_pc_drawing);
}

void SquareDrawing::remove_side_piece_bg_mod(
    const PtrPieceDrawing &piece_drawing) {
  BM::remove_mod(BM::BGCOLOR, &piece_drawing->get_drawing());
}

void SquareDrawing::add_side_piece_bg(const PtrPieceDrawing &piece_drawing) {
  m_bg_mod = m_side_bg_color_mod[piece_drawing->get_color()];
  BM::add_bg_color(m_bg_mod, &piece_drawing->get_drawing());
}
