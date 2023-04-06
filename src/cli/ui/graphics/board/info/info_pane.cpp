#include "info_pane.h"

InfoPane::InfoPane() {
  add_section(m_top_section, 1);
  add_section(m_player_banner_section, InfoDrawings::Banner::height);
  add_section(m_moves_section[BLACK], 10);
  add_section(m_captures_section[BLACK], 5);
  add_section(m_moves_section[WHITE], 10);
  add_section(m_captures_section[WHITE], 5);
  add_section(m_board_info_section, 5);
  add_section(m_bottom_section, 1);

  clear_all_sections();
}

InfoPane::~InfoPane() {}

void InfoPane::clear_all_sections() {
  clear();
  format_block(get_section(m_moves_section[BLACK]), "");
  format_block(get_section(m_moves_section[WHITE]), "");
  format_block(get_section(m_captures_section[BLACK]), "");
  format_block(get_section(m_captures_section[WHITE]), "");
  update_game_info("");
}

void InfoPane::clear() {
  fill(InfoDrawings::Borders::kempty_row);
  set_content_at_section(m_top_section, {InfoDrawings::Borders::ktop_drawing});
  set_content_at_section(m_bottom_section, {InfoDrawings::Borders::kbottom_drawing});
}

void InfoPane::draw() {}
void InfoPane::clear_block() { clear(); }

void InfoPane::format_block(shared_ptr<Section>& block, string content) {
  if (block == nullptr) return;

  if (!has_block_space_for_content(block, content)) return;

  string msg = block->get_name() + ": " + content; 
  set_content_to_block_recursively(block, msg, 0);
}

bool InfoPane::has_block_space_for_content(
    const shared_ptr<Section>& block, const string& message) {
  return message.size() < kRowMaxLen * (block->size() - 1);
}

void InfoPane::set_content_to_block_recursively(shared_ptr<Section>& section,
    string &msg, size_t current_row) {
  if (current_row > section->size()) return;

  if (msg.size() < kRowMaxLen) {
    section->set_drawing_at_index(format_line(msg), current_row);
    section->set_drawing_at_index(InfoDrawings::Borders::krow_divider, section->size() - 1);
    return;
  }

  string row_content = msg.substr(0, kRowMaxLen);
  section->set_drawing_at_index(format_line(row_content), current_row);

  msg = msg.substr(kRowMaxLen/* to_end */);
  set_content_to_block_recursively(section, msg, ++current_row);
}

string InfoPane::format_line(const string &line) {
  unsigned long num_spaces = kRowMaxLen - line.size();
  return  " ┃ " + line + std::string(num_spaces, ' ') + "┃";
}

void InfoPane::update_turn(const PlayerInfo &info) {
  m_turn_info = info;

  update_banner(m_turn_info.color);
}

void InfoPane::update_banner(Color c) {
  set_content_at_section(m_player_banner_section, p_banners[c]);
}

void InfoPane::update_moves(const string& moves) {
  format_block(get_section(m_moves_section[m_turn_info.color]), moves);
}

void InfoPane::update_captures(const string& captures) {
  format_block(get_section(m_captures_section[m_turn_info.color]), captures);
}

void InfoPane::update_game_info(const string& info) {
  get_section(m_board_info_section)->fill(InfoDrawings::Borders::kempty_row);
  format_block(get_section(m_board_info_section), info);
}
