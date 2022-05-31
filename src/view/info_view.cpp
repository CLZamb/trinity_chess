#include "headers/info_view.h"

InfoView::InfoView() : View("Info") {
  m_pane.add_section(m_top_section, 1);
  m_pane.add_section(m_player_banner_section, Banner::height);
  m_pane.add_section(m_moves_section[BLACK], 10);
  m_pane.add_section(m_captures_section[BLACK], 5);
  m_pane.add_section(m_moves_section[WHITE], 10);
  m_pane.add_section(m_captures_section[WHITE], 5);
  m_pane.add_section(m_game_info_section, 5);
  m_pane.add_section(m_bottom_section, 1);

  clear_all_sections();
}

InfoView::~InfoView() {}

void InfoView::clear_all_sections() {
  clear();
  update_banner(GameTurn::player_1);
  format_block(m_pane.get_section(m_moves_section[BLACK]), "");
  format_block(m_pane.get_section(m_moves_section[WHITE]), "");
  format_block(m_pane.get_section(m_captures_section[BLACK]), "");
  format_block(m_pane.get_section(m_captures_section[WHITE]), "");
  update_game_info("");
}

void InfoView::clear() {
  m_pane.fill(
      " ┃                                                          ┃");

  m_pane.set_content_at_section(m_top_section, {
      " ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓"
      });

  m_pane.set_content_at_section(m_bottom_section, {
      " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛"
      });
}

void InfoView::draw() {}

void InfoView::clear_block() {
  m_pane.clear();
}

void InfoView::format_block(shared_ptr<Section>& block, string content) {
  if (block == nullptr) return;

  if (!has_block_space_for_content(block, content)) return;

  set_content_to_block_recursively(
      block, block->get_name() + ": " + content, 0);
}

bool InfoView::has_block_space_for_content(
    const shared_ptr<Section>& block, const string& message) {
  return message.size() < kRowMaxLen * (block->size() - 1);
}

void InfoView::set_content_to_block_recursively(shared_ptr<Section>& block,
    string msg, size_t current_row) {
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

string InfoView::format_line(string line) {
  int num_spaces = kRowMaxLen - line.size();
  return  " ┃ " + line + std::string(num_spaces, ' ') + "┃";
}

void InfoView::update_turn(const PlayerInfo &info) {
  m_turn_info = info;

  update_banner(m_turn_info.get_turn());
}

void InfoView::update_banner(GameTurn::players p) {
  m_pane.set_content_at_section(m_player_banner_section, p_banners[p]);
}

void InfoView::update_moves(const string& moves) {
  format_block(m_pane.get_section(m_moves_section[m_turn_info.get_color()]), moves);
}

void InfoView::update_captures(const string& captures) {
  format_block(m_pane.get_section(m_captures_section[m_turn_info.get_color()]), captures);
}

void InfoView::update_game_info(const string& info) {
  format_block(m_pane.get_section(m_game_info_section), info);
}
