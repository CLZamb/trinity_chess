#include "headers/info_view.h"

using std::make_unique;
InfoView::InfoView() : View("Info") {
  p_top_section = make_unique<Section>("top", 1);
  p_player_banner = make_unique<Section>("Player banner", Banner::height);
  p_moves[BLACK]= make_unique<Section>("[Black Moves]", 5);
  p_moves[WHITE]= make_unique<Section>("[White Moves]", 5);
  p_captures[BLACK] = make_unique<Section>("[Black Captures]", 10);
  p_captures[WHITE] = make_unique<Section>("[White Captures]", 10);
  p_game_info = make_unique<Section>("[Game info]", 5);
  p_bottom_section = make_unique<Section>("bottom", 1);

  m_drawing.add_section(p_top_section);
  m_drawing.add_section(p_player_banner);
  m_drawing.add_section(p_moves[WHITE]);
  m_drawing.add_section(p_captures[WHITE]);
  m_drawing.add_section(p_moves[BLACK]);
  m_drawing.add_section(p_captures[BLACK]);
  m_drawing.add_section(p_game_info);
  m_drawing.add_section(p_bottom_section);

  clear_all_sections();
}

InfoView::~InfoView() {}

void InfoView::clear_all_sections() {
  clear();
  update_banner(GameTurn::player_1);
  format_block(p_moves[BLACK], "");
  format_block(p_moves[WHITE], "");
  format_block(p_captures[BLACK], "");
  format_block(p_captures[WHITE], "");
  update_game_info("");
}

void InfoView::clear() {
  m_drawing.fill(
      " ┃                                                          ┃");

  p_top_section->set_content({
      " ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓"
      });
  p_bottom_section->set_content({
      " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛"
      });
}

void InfoView::draw() {}

void InfoView::clear_block() {
  m_drawing.clear();
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

string InfoView::format_line(string line) {
  int num_spaces = kRowMaxLen - line.size();
  return  " ┃ " + line + std::string(num_spaces, ' ') + "┃";
}

void InfoView::update_turn(const PlayerInfo &info) {
  m_turn_info = info;

  update_banner(m_turn_info.get_turn());
}

void InfoView::update_banner(GameTurn::players p) {
  p_player_banner->set_content(p_banners[p]);
}

void InfoView::update_moves(const string& moves) {
  format_block(p_moves[m_turn_info.get_color()], moves);
}

void InfoView::update_captures(const string& captures) {
  format_block(p_captures[m_turn_info.get_color()], captures);
}

void InfoView::update_game_info(const string& info) {
  format_block(p_game_info, info);
}
