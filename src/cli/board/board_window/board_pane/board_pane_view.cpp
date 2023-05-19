#include "board_pane_view.h"

#include "components/fen_fields.hpp"

using std::string;
namespace BD = BoardDrawings::Board;

BoardPaneView::BoardPaneView()
    : Pane(Kboard_pane_size) {
  add_section(m_top_section, 1);
  add_section(m_board_section, 40);
  add_section(m_bottom_section, 3);
  clear();
}

SquareDrawing *BoardPaneView::get_square(Square i) {
  return &m_square_drawings[i];
}

void BoardPaneView::parse_fen(const FenFields &fen_fields) {
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

void BoardPaneView::clear_square_on_range(const int start,
                                          const int end) {
  for (int pos = start; pos < end; pos++) { m_square_drawings.clear_square_at_pos(pos); }
}

void BoardPaneView::update_drawing() {
  size_t row_idx = 0;
  std::string row_drawing = "";
  /*
   * Rows needs to be ordered upside down
   * because the program prints from top to bottom
   * so that the 8th row should be printed frist
   */
  for (int row = 7; row >= 0; --row) {
    // each square has 5 indiviual rows
    for (int k = 0; k < Box::kRowSize; ++k, row_idx++) {
      draw_row(row_drawing, row, k);
      get_section(m_board_section)->set_drawing_at_index(row_drawing, row_idx);
    }
  }
}

string BoardPaneView::draw_row(string &drawing,
                               const int &row,
                               const int &k) {
  drawing = left_border(row, k);

  Square col_sq{SquareNull};
  /*
   * there are 8*8 (from 0 to 63) squares,
   * to get a position
   * we need to multyply row by 8 and add the col
   * i.e the bottom right position would be
   *  0 * 8 + 7 = 7
   */
  for (int col = 0; col < 8; col++) {
    col_sq = static_cast<Square>((row * 8) + col);
    // row_drawing += m_squares_drawings[static_cast<size_t>()].at(k);
    drawing += m_square_drawings[col_sq][k];
  }

  drawing += "┃";
  return drawing;
}

void BoardPaneView::make_move(const Move &mv) {
  const Square from = MoveUtils::get_from(mv);
  const Square to = MoveUtils::get_to(mv);

  m_square_drawings.move_piece(from, to);
}

void BoardPaneView::clear() {
  Pane::set_content_at_section(m_top_section, {BD::ktop_section});
  Pane::set_content_at_section(m_bottom_section, &BD::kbottom_section_drawing);
}

string BoardPaneView::left_border(const int &row, const int &k) {
  return (is_middle_of_square(k) ? " " : std::to_string(row + 1)) + "┃";
}

bool BoardPaneView::is_middle_of_square(const int &square_row) {
  return (square_row + 1) % 3;
}
