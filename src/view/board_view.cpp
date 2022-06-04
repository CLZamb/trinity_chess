#include "headers/board_view.h"

BoardView::BoardView() : View("Board") {
  m_pane.add_section(m_top_section, 1);
  m_pane.add_section(m_board_section, 40);
  m_pane.add_section(m_bottom_section, 3);

  clear();
  setup_board_squares();

  window_view.add_pane(this, Window::Middle_pane);
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
        row_drawing += m_squares[(row * 8) + col].at(k);
      }

      row_drawing += "┃";
      m_pane.get_section(m_board_section)->set_content_at_index(row_drawing,row_counter );
    }
  }
}

void BoardView::setup_board_squares() {
  char squareColor = 'w';
  bool is_black_squared = true;

  static const int col_size = 7;
  static const int row_size = 8;
  int position = 0;
  /* 
   * Rows needs to be ordered upside down
   * because the program prints from top to bottom
   * so that 8 should be printed frist
  */

  for (int row = col_size; row >= 0; --row) {
    for (int col = 0; col < row_size; ++col) {
      /*
       * there are 8*8 (from 0 to 63) squares
       * to get the position 
       * we need to multyply rwo by 8 and add the col
       * i.e the bottom right position would be  
       * 8 * 0 + 7 = 7
       * */
      position = row * 8 + col;
      if (squareColor == 'b') {
        squareColor = 'w';
        m_squares[position].update_drawing(!is_black_squared);
      } else {
        squareColor = 'b';
        m_squares[position].update_drawing(is_black_squared);
      }
    }
    squareColor = squareColor == 'b' ? 'w' : 'b';
  }
}

char BoardView::left_border(const int &row, const int &col) {
  return (col + 1) % 3 ? ' ' :  ('0' + row + 1);
}

void BoardView::parser_fen(const string& fen) {
  SquareIndices square = A1;
  int rank = 7;
  int file = 0;
  Piecetype piece;
  int space = 0;

  for (const char& c : fen) {
    piece = utils::get_square_index_from_char_key(c);
    square = static_cast<SquareIndices>(rank * 8 + file);
    if (piece) {
      set_piece_drawing_at_square_pos(piece, square);
      file++;

    } else if (is_number(c)) {
      space = (c - '0');
      file += space;
      clear_square_on_range(square, square + space);

    } else if (c == '/') {
      rank--;
      file = 0;
    } 

    if (rank < 0) break;
  }
}

bool BoardView::is_number(const char& c) {
  return c >= '0' && c <= '8';
}

void BoardView::clear_square_on_range(const int start_pos, const int end_pos) {
  for (int pos = start_pos; pos < end_pos; pos++) {
    m_squares[pos].clear_square();
  }
}

void BoardView::add_pane_at_window_pos(Displayable *pane, Window::Pane_pos pos) {
  window_view.add_pane(pane, pos);
}

void BoardView::add_view_at_window_pos(View& v, Window::Pane_pos pos) {
  add_pane_at_window_pos(&v, pos);
}

void BoardView::set_piece_drawing_at_square_pos(Piecetype type, SquareIndices position) {
  m_squares[position].update_drawing(m_pieces_drawings.get_drawing(type, m_squares[position].is_black_square()));
}
