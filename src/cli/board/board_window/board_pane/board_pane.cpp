#include "board_pane.h"

BoardPane::BoardPane(const string &fen) : Pane(Kboard_pane_size) {
  add_section(m_top_section, 1);
  add_section(m_board_section, 40);
  add_section(m_bottom_section, 3);
  clear();
  parse_fen(fen);
}

void BoardPane::update_board_drawing() {
  size_t row_counter = 0;
  string row_drawing = "";
  // need to be print upside down so that the bottom begins at row 1
  for (int row = 7; row >= 0; --row) {
    for (int k = 0; k < Box::kRowSize; ++k, row_counter++) {
      row_drawing = left_border(row, k);

      for (int col = 0; col < 8; col++) {
        row_drawing +=
            m_squares_drawings[static_cast<Square>((row * 8) + col)].at_row(k);
      }

      row_drawing += "┃";

      get_section(m_board_section)
          ->set_drawing_at_index(row_drawing, row_counter);
    }
  }
}

void BoardPane::make_move(const Move &mv) {
  const Square from = MoveUtils::get_from(mv);
  const Square to = MoveUtils::get_to(mv);
  Piece piece = MoveUtils::get_piece(mv);

  m_squares_drawings[from].clear_square();
  set_piece_drawing_at_square_pos(to, piece);
}

void BoardPane::update() { update_board_drawing(); }

void BoardPane::clear() {
  Pane::set_content_at_section(m_top_section,
                               {BoardDrawings::Board::ktop_section});
  Pane::set_content_at_section(m_bottom_section,
                               &BoardDrawings::Board::kbottom_section_drawing);
}

void BoardPane::parse_fen(const string &fen) {
  int square = A1, rank = 7, file = 0, space = 0;
  Piece piece;
  const char *c = fen.c_str();

  while (*c != ' ') {
    piece = utils::get_piecetype_from_char_key(*c);
    square = rank * 8 + file;
    if (piece) {
      set_piece_drawing_at_square_pos(static_cast<Square>(square), piece);
      file++;

    } else if (is_number(*c)) {
      space = (*c - '0');
      file += space;
      clear_square_on_range(square, square + space);

    } else if (*c == '/') {
      rank--;
      file = 0;
    }

    if (rank < 0) {
      break;
    }

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
    m_squares_drawings[static_cast<Square>(pos)].clear_square();
  }
}

void BoardPane::set_piece_drawing_at_square_pos(Square position, Piece type) {
  bool is_black_square = m_squares_drawings[position].is_black_square();
  const Box *piece_drawing =
      m_pieces_drawings.get_drawing(type, is_black_square);
  m_squares_drawings[position].set_piece_drawing(piece_drawing);
}

bool BoardPane::is_number(char c) { return c >= '0' && c <= '8'; }

void BoardPane::update_select_next_square(const Square &next) {
  m_squares_drawings.select_next_square(next);
  update_board_drawing();
}

void BoardPane::update_selected_square(const Square &next) {
  m_squares_drawings.selected_square(next);
  selected_positions.push_back(next);
  update_board_drawing();
}

void BoardPane::deselect_all_previous_selected_squares() {
  for (const Square &pos : selected_positions) {
    m_squares_drawings.deselect_square(pos);
  }

  selected_positions.clear();
  update_board_drawing();
}
