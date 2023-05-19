#ifndef BOARD_PANE_VIEW_H
#define BOARD_PANE_VIEW_H

#include "board/board_window/board_pane/squares/square_drawings.h"
#include "configuration/board_info.h"
#include "components/pane.h"
#include "utils/move.hpp"

class BoardPaneView : public Pane {
 private:
 public:
  BoardPaneView();
  virtual ~BoardPaneView() = default;

  void make_move(const Move &mv);
  void parse_fen(const FenFields &fen);
  void update_drawing();

  SquareDrawing* get_square(Square i);

  virtual bool is_player_string_move_ready() { return true; };
  virtual std::string get_player_move_as_string() { return m_string_move; };

 private:
  void clear();
  void clear_square_on_range(const int start_pos,
                             const int end_pos);
  bool is_middle_of_square(const int &col);
  std::string draw_row(std::string &row_drawing,
                       const int &board_row,
                       const int &square_row);
  std::string left_border(const int &row, const int &col);

  const std::string m_top_section = "top";
  const std::string m_board_section = "board";
  const std::string m_bottom_section = "bottom";

  static const size_t Kboard_pane_size{44};
  std::string m_string_move{""};
  SquaresDrawings m_square_drawings;
};

#endif /* BOARD_PANE_VIEW_H */
