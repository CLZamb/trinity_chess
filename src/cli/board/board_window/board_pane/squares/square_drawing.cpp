#include "square_drawing.h"

using BM = BoxModifier;
using PtrPieceDrawing = std::unique_ptr<IPieceDrawing>;

SquareDrawing::SquareDrawing(const SquareDrawingInfo &sdi)
    : m_empty(sdi.empty_square_drawing()) {
  m_side_bg_color_mod[WHITE] = sdi.get_white_piece_bg_mod();
  m_side_bg_color_mod[BLACK] = sdi.get_black_piece_bg_mod();
}

Box *SquareDrawing::get_drawing() {
  if (m_has_piece) return &m_pc_drawing->get_drawing();

  return &m_empty;
}

void SquareDrawing::clear() { m_has_piece = false; }

const char *SquareDrawing::operator[](int row) {
  return get_drawing()->content[row];
}

void SquareDrawing::set_piece_drawing(PtrPieceDrawing &&piece_drawing) {
  m_pc_drawing = std::move(piece_drawing);
  add_bg_color_mod_to_piece();
  m_has_piece = true;
}

PtrPieceDrawing &&SquareDrawing::remove_piece_drawing() {
  if (m_pc_drawing.get() == nullptr) return std::move(m_pc_drawing);

  clear();

  BM::remove_mod(&m_pc_drawing->get_drawing(), BM::BGCOLOR);
  return std::move(m_pc_drawing);
}

void SquareDrawing::add_bg_color_mod_to_piece() {
  m_bg_mod = m_side_bg_color_mod[m_pc_drawing->get_color()];
  BM::add_bg_color(m_bg_mod, &m_pc_drawing->get_drawing());
}

// char &SquareDrawing::operator()(int row, int col) {
//   return get_drawing()->content[row][col];
// }
