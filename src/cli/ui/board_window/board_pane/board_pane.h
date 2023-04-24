#ifndef BOARD_PANE_H
#define BOARD_PANE_H

#include "ui/board_window/IBoard_pane.h"
#include "ui/board_window/board_pane/event_handlers/IBoard_input_event_handler.h"
#include "ui/board_window/board_pane/pieces/pieces_drawings.hpp"
#include "ui/board_window/board_pane/squares/squares_drawing.h"
#include <memory>

class BoardPane : public IBoardPane {
public:
  BoardPane(const string &fen);
  virtual ~BoardPane() {}
  void make_move(const Move &mv) override;
  void update() override;
  void update_select_next_square(const Square &next);
  void update_selected_square(const Square &next);
  void update_deselected_square(const Square &next);
  void deselect_all_previous_selected_squares();

private:
  void update_board_drawing();
  void clear();
  void parse_fen(const string &fen);
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
  PlayerInfo m_player_info;
};

#endif // !BOARD_PANE_H
