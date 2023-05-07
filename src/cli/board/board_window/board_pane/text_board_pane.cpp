#include "text_board_pane.h"

TextBoardPane::TextBoardPane(const std::unique_ptr<TextInput> &p, const FenFields& fen) {
  BoardPane::parse_fen(fen);
  p->bind<CommandEventText>(&TextBoardPane::handle_string_input, this);
}

bool TextBoardPane::is_player_string_move_ready() { return true; }

std::string TextBoardPane::get_player_move_as_string() { return m_string_move; }

void TextBoardPane::handle_string_input(CommandEventText &e) {
  m_string_move = e.get_text();
}
