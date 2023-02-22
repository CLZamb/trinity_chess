#include "headers/board_view.h"

BoardView::BoardView() : View("Board") {
  m_pane.add_section(m_top_section, 1);
  m_pane.add_section(m_board_section, 40);
  m_pane.add_section(m_bottom_section, 3);
  clear();
  _window.add_pane(this, Window::Middle_pane);
}

void BoardView::clear() {
  m_pane.set_content_at_section(m_top_section, {m_top_section_drawing});
  m_pane.set_content_at_section(m_bottom_section, &m_bottom_section_drawing);
}

BoardView::~BoardView() {}

void BoardView::draw() {
  int row_counter = 0;
  string row_drawing = "";
  // need to be print upside down so that the bottom begins at row 0
  for (int row = 7; row >= 0; --row) {
    for (int k = 0; k < Box::kRowSize; ++k, row_counter++) {
      row_drawing = "";

      row_drawing += left_border(row, k);
      row_drawing += "┃";

      for (int col = 0; col < 8; col++) {
        row_drawing += m_squares_drawings[static_cast<size_t>((row * 8) + col)].at(k);
      }

      row_drawing += "┃";
      m_pane.get_section(m_board_section)->set_content_at_index(row_drawing, row_counter);
    }
  }
}

char BoardView::left_border(const int &row, const int &col) {
  return (col + 1) % 3 ? ' ' :  static_cast<char>(('0' + row + 1));
}

void BoardView::parse_fen(const string& fen) {
  SquareIndices square = A1;
  int rank = 7;
  int file = 0;
  Piecetype piece;
  int space = 0;
  const char* c = fen.c_str();

  while (*c != ' ') {
    piece = utils::get_piecetype_from_char_key(*c);
    square = static_cast<SquareIndices>(rank * 8 + file);
    if (piece) {
      set_piece_drawing_at_square_pos(square, piece);
      file++;

    } else if (is_number(*c)) {
      space = (*c - '0');
      file += space; 
      clear_square_on_range(square, square + space);

    } else if (*c == '/') {
      rank--;
      file = 0;
    } 

    if (rank < 0) break;
    c++;
  }
}

bool BoardView::is_number(char c) {
  return c >= '0' && c <= '8';
}

void BoardView::clear_square_on_range(const int start_pos, const int end_pos) {
  for (int pos = start_pos; pos < end_pos; pos++) {
    m_squares_drawings[pos].clear_square();
  }
}

void BoardView::add_pane_at_window_pos(Displayable *pane, Window::Pane_pos pos) {
  _window.add_pane(pane, pos);
}

void BoardView::add_view_at_window_pos(View& v, Window::Pane_pos pos) {
  add_pane_at_window_pos(&v, pos);
}

void BoardView::set_piece_drawing_at_square_pos(SquareIndices position, Piecetype type) {
  m_squares_drawings[position].set_piece_drawing(m_pieces_drawings.get_drawing(type, m_squares_drawings[position].is_black_square()));
}

void BoardView::select_next_square(const size_t &i)  {
  m_squares_drawings.select_next_square(i);
}

void BoardView::selected_square(const size_t &i) {
  m_squares_drawings.selected_square(i);
}

void BoardView::deselect_square(const size_t &i) {
  m_squares_drawings.desselected_square(i);
}

