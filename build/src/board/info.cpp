#include "headers/info.h"

Info::Info(Board* b) : p_board(b) {
}

Info::~Info() {
}

void Info::_init(Pane* pane) {
  m_drawing = pane;
  m_drawing->set_top(" ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");

  player_banner
    = make_unique<Section>("Player banner", Banner::player1.size());
  board_score    = make_unique<Section>("[Board Score]", 4);
  black_captures = make_unique<Section>("[Black captures]", 4);
  white_captures = make_unique<Section>("[White Captures]", 4);
  black_moves    = make_unique<Section>("[Black moves]", 11);
  white_moves    = make_unique<Section>("[White Moves]", 11);

  m_drawing->add_section(player_banner);
  m_drawing->add_section(board_score);
  m_drawing->add_section(black_captures);
  m_drawing->add_section(white_captures);
  m_drawing->add_section(black_moves);
  m_drawing->add_section(white_moves);

  m_drawing->set_bottom(" ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
}

void Info::draw_info_board() {
  if (player_banner) {
    if (p_board->get_turn() == p_board->get_player_1()) {
      player_banner->set_content(p_p1_banner);
    } else {
      player_banner->set_content(p_p2_banner);
    }
  }

  string score = std::to_string(p_board->evaluate_board());
  format_block(board_score, score);
  format_block(black_captures, "");
  format_block(white_captures, "");
  format_block(black_moves, "");
  format_block(white_moves, "");
}

void Info::clear_block() {
  m_drawing->clear();
}

void Info::format_block(shared_ptr<Section>& block, string msg) {
  if (block == nullptr) return;

  assert(msg.size() < kLineMaxLen * (block->size() - 1));
  recursive_block(block, block->get_name() + ": " + msg, 0);
}

void Info::recursive_block(shared_ptr<Section>& block, string msg, int current_row) {
  if (current_row > block->size()) return;

  if (msg.size() < kLineMaxLen) {
    *block->at(current_row) = format_line(msg);
    *block->at(block->size() - 1) =
      " ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃";
    return;
  }

  string resized_line = msg.substr(0, kLineMaxLen);
  *block->at(current_row) = format_line(resized_line);

  msg = msg.substr(kLineMaxLen/* to_end */);
  recursive_block(block, msg, ++current_row);
}

string Info::format_line(string line) {
  int num_spaces = kLineMaxLen - line.size();
  return  " ┃ " + line + std::string(num_spaces, ' ') + "┃";
}
