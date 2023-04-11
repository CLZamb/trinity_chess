#ifndef BOARD_PANE_H
#define BOARD_PANE_H

#include "board/fen/fen_model.hpp"
#include "keyboard_board_input_selection.h"
#include "ui/graphics/board/decorators/IUi_board.h"
#include "ui/graphics/board/pieces/pieces_drawings.hpp"
#include "ui/graphics/board/squares_drawing.h"
#include "ui/graphics/components/standard_pane.h"
#include "utils/defs.h"
#include <ios>

class BoardPane : public IUiPaneComponent, public StandardPane , public KeyboardBoardInputSelection {
 public:
  BoardPane(const string& fen) {
    add_section(m_top_section, 1);
    add_section(m_board_section, 40);
    add_section(m_bottom_section, 3);
    clear();
    parse_fen(fen);
  }

  void make_move(const Move& mv) {
    const SquareIndices from = Move_Utils::get_from(mv);
    const SquareIndices to = Move_Utils::get_to(mv);
    Piecetype piece = Move_Utils::get_piece(mv);

    m_squares_drawings[from].clear_square();
    set_piece_drawing_at_square_pos(static_cast<SquareIndices>(to), piece);
  }

  void update() override {
    update_board_drawing();
  }

  void select_next_square(const SquareIndices& sq) override {
    m_squares_drawings.select_next_square(sq);
  }

  void selected_square(const SquareIndices& sq) override {
    m_squares_drawings.selected_square(sq);
  }

  void deselect_square(const SquareIndices& sq) override {
    m_squares_drawings.deselected_square(sq);
  }

 private:
  void update_board_drawing() {
    unsigned long row_counter = 0;
    string row_drawing = "";
    // need to be print upside down so that the bottom begins at row 0
    for (int row = 7; row >= 0; --row) {
      for (int k = 0; k < Box::kRowSize; ++k, row_counter++) {

        row_drawing = left_border(row, k);

        for (int col = 0; col < 8; col++) {
          row_drawing += m_squares_drawings[static_cast<SquareIndices>((row * 8) + col)].at_row(k);
        }

        row_drawing += "┃";

        get_section(m_board_section)->set_drawing_at_index(row_drawing, row_counter);
      }
    }
  }

  void clear() {
    set_content_at_section(m_top_section, {BoardDrawings::Board::ktop_section});
    set_content_at_section(m_bottom_section, &BoardDrawings::Board::kbottom_section_drawing);
  }

  void parse_fen(const string& fen) {
    if (m_fen == fen) return;

    int square = A1, rank = 7, file = 0, space = 0;
    Piecetype piece;
    const char* c = fen.c_str();

    while (*c != ' ') {
      piece = utils::get_piecetype_from_char_key(*c);
      square = rank * 8 + file;
      if (piece) {
        set_piece_drawing_at_square_pos(static_cast<SquareIndices>(square), piece);
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

    m_fen = fen;
  }

  string left_border(const int &row, const int &col) {
    return (is_middle_of_square(col) ? " " : std::to_string(row)) + "┃";
  }

  bool is_middle_of_square(const int& col) {
    return (col + 1) % 3;
  }

  void clear_square_on_range(const int start_pos, const int end_pos) {
    for (int pos = start_pos; pos < end_pos; pos++) {
      m_squares_drawings[static_cast<SquareIndices>(pos)].clear_square();
    }
  }

  void set_piece_drawing_at_square_pos(SquareIndices position, Piecetype type) {
    bool is_black_square = m_squares_drawings[position].is_black_square();
    const Box *piece_drawing = m_pieces_drawings.get_drawing(type, is_black_square);
    m_squares_drawings[position].set_piece_drawing(piece_drawing);
  }

  bool is_number(char c) {
    return c >= '0' && c <= '8';
  }

  const string m_top_section = "top";
  const string m_board_section = "board";
  const string m_bottom_section = "bottom";
  string m_fen{};

  SquaresDrawings m_squares_drawings;
  PiecesDrawings m_pieces_drawings;
};


#endif // !BOARD_PANE_H
