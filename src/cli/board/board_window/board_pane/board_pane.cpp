#include "board_pane.h"

#include "ui_components/fen_fields.hpp"

using std::string;
namespace BD = BoardDrawings::Board;

BoardPane::BoardPane()
    : Pane(Kboard_pane_size) {
  add_section(m_top_section, 1);
  add_section(m_board_section, 40);
  add_section(m_bottom_section, 3);
  clear();
}

BoardPane::BoardPane(const FenFields &f)
    : BoardPane() {
  parse_fen(f);
}

void BoardPane::parse_fen(const FenFields &fen_fields) {
  int square = A1, rank = 7, file = 0, space = 0;
  Piece piece;

  for (char c : fen_fields.piece_placement) {
    if (c == '/') {
      rank--;
      file = 0;
      continue;
    }

    square = rank * 8 + file;

    if (isdigit(c)) {
      space = (c - '0');
      file += space;
      clear_square_on_range(square, square + space);
    } else {
      piece = utils::get_piecetype_from_char(c);
      file++;
      m_square_drawings.set_piece_at_square(piece, square);
    }
  }
}

void BoardPane::clear_square_on_range(const int start, const int end) {
  for (int pos = start; pos < end; pos++) {
    m_square_drawings.clear_square_at_pos(pos);
  }
}

void BoardPane::update_drawing() {
  size_t row_idx = 0;
  std::string row_drawing = "";

  // need to be print upside down so that the bottom begins at row 1
  for (int row = 7; row >= 0; --row) {
    // each square has 5 indiviual rows
    for (int k = 0; k < Box::kRowSize; ++k, row_idx++) {
      draw_row(row_drawing, row, k);
      // set row drawing to the corresponding index
      // inside the board pane section
      get_section(m_board_section)->set_drawing_at_index(row_drawing, row_idx);
    }
  }
}

string BoardPane::draw_row(string &drawing, const int &row, const int &k) {
  drawing = left_border(row, k);

  Square col_sq{SquareNull};
  // add each column from left to right to row drawing
  for (int col = 0; col < 8; col++) {
    col_sq = static_cast<Square>((row * 8) + col);
    drawing += (*m_square_drawings[col_sq])[k];
  }

  drawing += "┃";
  return drawing;
}

void BoardPane::make_move(const Move &mv) {
  const Square from = MoveUtils::get_from(mv);
  const Square to = MoveUtils::get_to(mv);

  m_square_drawings.move_piece(from, to);
}

void BoardPane::clear() {
  Pane::set_content_at_section(m_top_section, {BD::ktop_section});
  Pane::set_content_at_section(m_bottom_section, &BD::kbottom_section_drawing);
}

string BoardPane::left_border(const int &row, const int &k) {
  return (is_middle_of_square(k) ? " " : std::to_string(row + 1)) + "┃";
}

bool BoardPane::is_middle_of_square(const int &square_row) {
  return (square_row + 1) % 3;
}
