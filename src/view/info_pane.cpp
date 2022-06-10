#include "headers/info_pane.h"

InfoPane::InfoPane() {
  m_pane.add_section(m_top_section, 1);
  m_pane.add_section(m_player_banner_section, Banner::height);
  m_pane.add_section(m_moves_section[BLACK], 10);
  m_pane.add_section(m_captures_section[BLACK], 5);
  m_pane.add_section(m_moves_section[WHITE], 10);
  m_pane.add_section(m_captures_section[WHITE], 5);
  m_pane.add_section(m_board_info_section, 5);
  m_pane.add_section(m_bottom_section, 1);

  clear_all_sections();
}

InfoPane::~InfoPane() {}

void InfoPane::clear_all_sections() {
  clear();
  update_banner(GameTurn::player_1);
  format_block(m_pane.get_section(m_moves_section[BLACK]), "");
  format_block(m_pane.get_section(m_moves_section[WHITE]), "");
  format_block(m_pane.get_section(m_captures_section[BLACK]), "");
  format_block(m_pane.get_section(m_captures_section[WHITE]), "");
  update_game_info("");
}

void InfoPane::clear() {
  m_pane.fill(m_empty_row);
  m_pane.set_content_at_section(m_top_section, {m_top_section_drawing});
  m_pane.set_content_at_section(m_bottom_section, {m_bottom_section_drawing});
}

void InfoPane::draw() {}

void InfoPane::clear_block() {
  m_pane.clear();
}

void InfoPane::format_block(shared_ptr<Section>& block, string content) {
  if (block == nullptr) return;

  if (!has_block_space_for_content(block, content)) return;

  set_content_to_block_recursively(
      block, block->get_name() + ": " + content, 0);
}

bool InfoPane::has_block_space_for_content(
    const shared_ptr<Section>& block, const string& message) {
  return message.size() < kRowMaxLen * (block->size() - 1);
}

void InfoPane::set_content_to_block_recursively(shared_ptr<Section>& block,
    string msg, size_t current_row) {
  if (current_row > block->size()) return;

  if (msg.size() < kRowMaxLen) {
    block->set_content_at_index(format_line(msg), current_row);
    block->set_content_at_index(m_row_divider, block->size() - 1);
    return;
  }

  string row_content = msg.substr(0, kRowMaxLen);
  block->set_content_at_index(format_line(row_content), current_row);

  msg = msg.substr(kRowMaxLen/* to_end */);
  set_content_to_block_recursively(block, msg, ++current_row);
}

string InfoPane::format_line(string line) {
  int num_spaces = kRowMaxLen - line.size();
  return  " ┃ " + line + std::string(num_spaces, ' ') + "┃";
}

void InfoPane::update_turn(const PlayerInfo &info) {
  m_turn_info = info;

  update_banner(m_turn_info.turn);
}

void InfoPane::update_banner(GameTurn::Players p) {
  m_pane.set_content_at_section(m_player_banner_section, p_banners[p]);
}

void InfoPane::update_moves(const string& moves) {
  format_block(m_pane.get_section(m_moves_section[m_turn_info.color]), moves);
}

void InfoPane::update_captures(const string& captures) {
  format_block(m_pane.get_section(m_captures_section[m_turn_info.color]), captures);
}

void InfoPane::update_game_info(const string& info) {
  format_block(m_pane.get_section(m_board_info_section), info);
}
