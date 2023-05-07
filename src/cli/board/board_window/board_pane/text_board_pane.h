#ifndef TEXT_BOARD_PANE_H
#define TEXT_BOARD_PANE_H

#include "board/board_window/board_pane/IBoard_pane.h"
#include "input/text/text_input.h"

class TextBoardPane : public IBoardPane {
 public:
  explicit TextBoardPane(const std::unique_ptr<TextInput> &p, const FenFields& fen);
  bool is_player_string_move_ready() override;
  std::string get_player_move_as_string() override;

 private:
  std::string m_string_move{""};
  void handle_string_input(CommandEventText &e);
};

#endif /* TEXT_BOARD_PANE_H */
