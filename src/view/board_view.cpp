#include "headers/board_view.h"

BoardView::BoardView() : View("Board") {
  p_top_section = std::make_unique<Section>("top", 1);
  p_main = std::make_unique<Section>("board", 40);
  p_bottom_section = std::make_unique<Section>("bottom", 3);

  p_top_section->set_content_at_index(
       " ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓", 0);
  p_bottom_section->set_content({
       " ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃",
       " ┃    A        B        C        D        E        F        G       H     ┃",
       " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛"});

  m_drawing.add_section(p_top_section);
  m_drawing.add_section(p_main);
  m_drawing.add_section(p_bottom_section);

  add_view_to_window_pos(*this, Window::Left_pane);
  setup_board_squares();
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
      p_main->set_content_at_index(row_drawing, row_counter);
    }
  }
}

void BoardView::setup_board_squares() {
  char squareColor = 'w';
  bool is_black_squared = true;

  int position = 0;
  const int col_size = 7;
  const int row_size = 8;
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

  for (const char& c : fen) {
    piece = utils::get_square_index_from_char_key(c);
    if (piece) {
      square = static_cast<SquareIndices>(rank * 8 + file);
      set_piece_drawing_at_square_pos(piece, square);

      file++;

    } else if (is_number(c)) {
      file += (c - '0');

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
void BoardView::add_view_to_window_pos(View& v, Window::Pane_pos pos) {
  window_view.add_pane(&v, pos);
}

void BoardView::set_piece_drawing_at_square_pos(Piecetype type, SquareIndices position) {
  m_squares[position].update_drawing(m_pieces_drawings.get_drawing(type)->get_drawing(m_squares[position].is_black_square()));
}
