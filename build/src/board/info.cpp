#include "headers/info.h"

Info::Info() : Displayable(44) {}
Info::~Info() {}

void Info::_init() {
  p_top_section = make_unique<Section>("top", 1);
  p_player_banner =
    make_unique<Section>("Player banner", p_banners[m_turn]->size());
  p_board_score = make_unique<Section>("[Board Score]", 4);
  p_player_2_captures = make_unique<Section>("[Black captures]", 4);
  p_player_1_captures = make_unique<Section>("[White Captures]", 4);
  p_player_2_moves = make_unique<Section>("[Black moves]", 9);
  p_player_1_moves = make_unique<Section>("[White Moves]", 9);
  p_game_info = make_unique<Section>("[Game info:]", 5);
  p_bottom_section = make_unique<Section>("bottom", 1);

  m_drawing.add_section(p_top_section);
  m_drawing.add_section(p_player_banner);
  m_drawing.add_section(p_board_score);
  m_drawing.add_section(p_player_1_moves);
  m_drawing.add_section(p_player_1_captures);
  m_drawing.add_section(p_player_2_moves);
  m_drawing.add_section(p_player_2_captures);
  m_drawing.add_section(p_game_info);
  m_drawing.add_section(p_bottom_section);
}

void Info::clear() {
  m_drawing.fill(
      " ┃                                                          ┃");

  p_top_section->set_content({
      " ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓"
      });
  p_bottom_section->set_content({
      " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛"
      });
}

void Info::draw() {
  clear();
  if (p_player_banner) {
    p_player_banner->set_content(p_banners[m_turn]);
  }

  format_block(p_board_score, board_score);
  format_block(p_player_1_moves, player_moves[players::player_1]);
  format_block(p_player_1_captures, player_captures[players::player_1]);
  format_block(p_player_2_moves, player_moves[players::player_2]);
  format_block(p_player_2_captures, player_captures[players::player_2]);
  format_block(p_game_info, game_info);
}

void Info::clear_block() {
  m_drawing.clear();
}

void Info::format_block(shared_ptr<Section>& block, string content) {
  if (block == nullptr) return;

  if (!has_block_space_for_content(block, content)) return;

  set_content_to_block_recursively(
      block, block->get_name() + ": " + content, 0);
}

bool Info::has_block_space_for_content(
    const shared_ptr<Section>& block, const string& message) {
  return message.size() < kRowMaxLen * (block->size() - 1);
}

void Info::set_content_to_block_recursively(shared_ptr<Section>& block,
    string msg, int current_row) {
  if (current_row > block->size()) return;

  if (msg.size() < kRowMaxLen) {
    block->set_content_at_index(format_line(msg), current_row);
    block->set_content_at_index(
        " ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃",
        block->size() - 1);
    return;
  }

  string row_content = msg.substr(0, kRowMaxLen);
  block->set_content_at_index(format_line(row_content), current_row);

  msg = msg.substr(kRowMaxLen/* to_end */);
  set_content_to_block_recursively(block, msg, ++current_row);
}

string Info::format_line(string line) {
  int num_spaces = kRowMaxLen - line.size();
  return  " ┃ " + line + std::string(num_spaces, ' ') + "┃";
}

void Info::save_moves(const string& moves) {
  player_moves[m_turn] += " " + moves;
}

void Info::save_captures(const string& captures) {
  player_captures[m_turn] += " " + captures;
}

void Info::update_turn(players turn) {
  m_turn = turn;
}

void Info::save_game_info(const string& info) {
  game_info = info;
}
