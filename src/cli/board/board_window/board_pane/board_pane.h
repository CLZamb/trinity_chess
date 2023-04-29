#ifndef BOARD_PANE_H
#define BOARD_PANE_H

#include <memory>

#include "board/board_window/board_pane/pieces/pieces_drawings.hpp"
#include "board/board_window/board_pane/squares/squares_drawing.h"
#include "ui/components/pane.h"

class BoardPane : public Pane {
 public:
  explicit BoardPane(const string &fen);
  virtual ~BoardPane() {}
  void make_move(const Move &mv);
  void update();
  void update_select_next_square(const Square &next);
  void update_selected_square(const Square &next);
  void update_deselected_square(const Square &next);
  void deselect_all_previous_selected_squares();
  void parse_fen(const string &fen);

 private:
  void update_board_drawing();
  void clear();
  void clear_square_on_range(const int start_pos, const int end_pos);
  void set_piece_drawing_at_square_pos(Square position, Piece type);
  bool is_number(char c);
  bool is_middle_of_square(const int &col);
  string left_border(const int &row, const int &col);

  const string m_top_section = "top";
  const string m_board_section = "board";
  const string m_bottom_section = "bottom";

  std::list<Square> selected_positions;
  SquaresDrawings m_squares_drawings;
  PiecesDrawings m_pieces_drawings;
  static const size_t Kboard_pane_size{44};
};

#endif   // !BOARD_PANE_H
