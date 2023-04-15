#ifndef BOARD_PANE_H
#define BOARD_PANE_H

#include "ui/graphics/board/panes/IUi_board.h"
#include "ui/graphics/board/panes/board/IBoard_pane.h"
#include "ui/graphics/board/pieces/pieces_drawings.hpp"
#include "ui/graphics/board/squares/squares_drawing.h"
#include "ui/input/board/text/text_input_event_handler.h"
#include <memory>

class BoardPane : public IBoardPane {
public:
  BoardPane(const string &fen);
  virtual ~BoardPane() = default;

  void make_move(const Move &mv) override;
  void update() override;
  void update_turn(const PlayerInfo&) override {}
  virtual bool handle_event(KeyCode::Key, std::string& callback) override;

protected:
  void update_board_drawing();
  void clear();
  void parse_fen(const string &fen);
  void clear_square_on_range(const int start_pos, const int end_pos);
  void set_piece_drawing_at_square_pos(SquareIndices position, Piecetype type);
  bool is_number(char c);
  bool is_middle_of_square(const int &col);
  string left_border(const int &row, const int &col);

  const string m_top_section = "top";
  const string m_board_section = "board";
  const string m_bottom_section = "bottom";

  SquaresDrawings m_squares_drawings;
  PiecesDrawings m_pieces_drawings;
  TextInputEventHandler m_text_event_handler;
};

#endif // !BOARD_PANE_H
