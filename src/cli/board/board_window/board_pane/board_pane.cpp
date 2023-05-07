#include "board_pane.h"

#include "ui_components/fen_fields.hpp"

BoardPane::BoardPane()
    : Pane(Kboard_pane_size) {
  add_section(m_top_section, 1);
  add_section(m_board_section, 40);
  add_section(m_bottom_section, 3);
  clear();
}

BoardPane::BoardPane(const FenFields &fen)
    : BoardPane() {
  parse_fen(fen);
}

void BoardPane::update_drawing() {
  size_t row_index = 0;
  string row_drawing = "";
  Square cur_col_square{SquareNull};
  // need to be print upside down so that the bottom begins at row 1
  for (int row = 7; row >= 0; --row) {
    // each square has 5 indiviual rows
    for (int k = 0; k < Box::kRowSize; ++k, row_index++) {
      row_drawing = left_border(row, k);

      // add each column from left to right to row drawing
      for (int col = 0; col < 8; col++) {
        cur_col_square = static_cast<Square>((row * 8) + col);
        row_drawing += (*m_squares_drawings[cur_col_square])[k];
      }

      row_drawing += "┃";

      // set row drawing to the corresponding index
      // inside the board pane section
      get_section(m_board_section)
          ->set_drawing_at_index(row_drawing, row_index);
    }
  }
}

void BoardPane::make_move(const Move &mv) {
  const Square from = MoveUtils::get_from(mv);
  const Square to = MoveUtils::get_to(mv);

  m_squares_drawings.move_piece(from, to);
}

void BoardPane::clear() {
  Pane::set_content_at_section(m_top_section,
                               {BoardDrawings::Board::ktop_section});
  Pane::set_content_at_section(m_bottom_section,
                               &BoardDrawings::Board::kbottom_section_drawing);
}

void BoardPane::parse_fen(const FenFields &fen_fields) {
  int square = A1, rank = 7, file = 0, space = 0;
  Piece piece;

  for (char c : fen_fields.piece_placement) {
    piece = utils::get_piecetype_from_char_key(c);
    square = rank * 8 + file;
    if (piece) {
      m_squares_drawings.set_piece_at_square(piece, square);
      file++;

    } else if (is_number(c)) {
      space = (c - '0');
      file += space;
      clear_square_on_range(square, square + space);

    } else if (c == '/') {
      rank--;
      file = 0;
    }

    if (rank < 0) { break; }

    c++;
  }
}

string BoardPane::left_border(const int &row, const int &square_row) {
  return (is_middle_of_square(square_row) ? " " : std::to_string(row + 1)) +
         "┃";
}

bool BoardPane::is_middle_of_square(const int &square_row) {
  return (square_row + 1) % 3;
}

void BoardPane::clear_square_on_range(const int start_pos, const int end_pos) {
  for (int pos = start_pos; pos < end_pos; pos++) {
    m_squares_drawings.clear_square_at_pos(pos);
  }
}

bool BoardPane::is_number(char c) { return c >= '0' && c <= '8'; }
