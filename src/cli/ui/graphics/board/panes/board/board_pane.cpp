#include "board_pane.h"

BoardPane::BoardPane(const string &fen) {
  add_section(m_top_section, 1);
  add_section(m_board_section, 40);
  add_section(m_bottom_section, 3);
  clear();
  parse_fen(fen);
}

void BoardPane::make_move(const Move &mv) {
  const SquareIndices from = Move_Utils::get_from(mv);
  const SquareIndices to = Move_Utils::get_to(mv);
  Piecetype piece = Move_Utils::get_piece(mv);

  m_squares_drawings[from].clear_square();
  set_piece_drawing_at_square_pos(to, piece);
}

bool BoardPane::handle_event(KeyCode::Key e, std::string &s) {
  return m_text_event_handler.handle_event(e, s);
}

void BoardPane::update() { 
  update_board_drawing(); 
}

void BoardPane::update_board_drawing() {
  unsigned long row_counter = 0;
  string row_drawing = "";
  // need to be print upside down so that the bottom begins at row 0
  for (int row = 7; row >= 0; --row) {
    for (int k = 0; k < Box::kRowSize; ++k, row_counter++) {

      row_drawing = left_border(row, k);

      for (int col = 0; col < 8; col++) {
        row_drawing +=
            m_squares_drawings[static_cast<SquareIndices>((row * 8) + col)]
                .at_row(k);
      }

      row_drawing += "┃";

      get_section(m_board_section)->set_drawing_at_index(row_drawing, row_counter);
    }
  }
}

void BoardPane::clear() {
  set_content_at_section(m_top_section, {BoardDrawings::Board::ktop_section});
  set_content_at_section(
    m_bottom_section, &BoardDrawings::Board::kbottom_section_drawing
  );
}

void BoardPane::parse_fen(const string &fen) {
  int square = A1, rank = 7, file = 0, space = 0;
  Piecetype piece;
  const char *c = fen.c_str();

  while (*c != ' ') {
    piece = utils::get_piecetype_from_char_key(*c);
    square = rank * 8 + file;
    if (piece) {
      set_piece_drawing_at_square_pos(
        static_cast<SquareIndices>(square), piece
      );
      file++;

    } else if (is_number(*c)) {
      space = (*c - '0');
      file += space;
      clear_square_on_range(square, square + space);

    } else if (*c == '/') {
      rank--;
      file = 0;
    }

    if (rank < 0)
      break;
    c++;
  }
}

string BoardPane::left_border(const int &row, const int &col) {
  return (is_middle_of_square(col) ? " " : std::to_string(row + 1)) + "┃";
}

bool BoardPane::is_middle_of_square(const int &col) { return (col + 1) % 3; }

void BoardPane::clear_square_on_range(const int start_pos, const int end_pos) {
  for (int pos = start_pos; pos < end_pos; pos++) {
    m_squares_drawings[static_cast<SquareIndices>(pos)].clear_square();
  }
}

void BoardPane::set_piece_drawing_at_square_pos(SquareIndices position,
                                                Piecetype type) {
  bool is_black_square = m_squares_drawings[position].is_black_square();
  const Box *piece_drawing =
      m_pieces_drawings.get_drawing(type, is_black_square);
  m_squares_drawings[position].set_piece_drawing(piece_drawing);
}

bool BoardPane::is_number(char c) { return c >= '0' && c <= '8'; }
