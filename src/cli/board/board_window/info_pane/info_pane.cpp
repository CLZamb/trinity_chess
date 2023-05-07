#include "info_pane.h"

#include "ui_components/pane_drawings.hpp"

InfoPane::InfoPane(std::shared_ptr<BoardModelInfo> b) : p_info(b) {
  Pane::add_section(m_top_section, 1);
  Pane::add_section(m_player_banner_section, InfoDrawings::Banner::height);
  Pane::add_section(m_moves_section[BLACK], 10);
  Pane::add_section(m_captures_section[BLACK], 5);
  Pane::add_section(m_moves_section[WHITE], 10);
  Pane::add_section(m_captures_section[WHITE], 5);
  Pane::add_section(m_board_info_section, 5);
  Pane::add_section(m_bottom_section, 1);

  clear_all_sections();
}

InfoPane::~InfoPane() {}

void InfoPane::make_move(const Move &mv) {
  p_info->save_move(mv);

  if (MoveUtils::get_captured_piece(mv)) {
    p_info->save_capture(mv);
  }

  Color c = p_info->get_side_to_move_color();
  update_moves(p_info->get_moves(c), c);
  update_captures(p_info->get_captures(c), c);
}

void InfoPane::update() {
  update_game_info(p_info->get_info());
  update_banner(p_info->get_side_to_move_color());
}

void InfoPane::update_turn(const Color &c) {
  p_info->update_side(c);
  p_info->save_info(m_turn_string[c]);
}

void InfoPane::clear_all_sections() {
  Pane::fill(PaneDrawings::Borders::kempty_row);
  Pane::set_content_at_section(m_top_section,
                               {PaneDrawings::Borders::ktop_drawing});
  Pane::set_content_at_section(m_bottom_section,
                               {PaneDrawings::Borders::kbottom_drawing});
  Pane::format_section(get_section(m_moves_section[BLACK]), "");
  Pane::format_section(get_section(m_moves_section[WHITE]), "");
  Pane::format_section(get_section(m_captures_section[BLACK]), "");
  Pane::format_section(get_section(m_captures_section[WHITE]), "");

  update_game_info("");
}

void InfoPane::update_banner(Color c) {
  Pane::set_content_at_section(m_player_banner_section, p_banners[c]);
}

void InfoPane::update_moves(const string &moves, Color c) {
  Pane::format_section(get_section(m_moves_section[c]), moves);
}

void InfoPane::update_captures(const string &captures, Color c) {
  Pane::format_section(get_section(m_captures_section[c]), captures);
}

void InfoPane::update_game_info(const string &info) {
  Pane::get_section(m_board_info_section)
      ->fill(PaneDrawings::Borders::kempty_row);
  Pane::format_section(get_section(m_board_info_section), info);
}
