#include "info_view.h"

#include "ui_components/pane_drawings.hpp"

using std::string;

InfoView::InfoView() : Pane(Kboard_pane_size) {
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

InfoView::~InfoView() {}

void InfoView::clear_all_sections() {
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

void InfoView::update_banner(Color c) {
  Pane::set_content_at_section(m_player_banner_section, p_banners[c]);
}

void InfoView::update_moves(const string &moves, Color c) {
  Pane::format_section(get_section(m_moves_section[c]), moves);
}

void InfoView::update_captures(const string &captures, Color c) {
  Pane::format_section(get_section(m_captures_section[c]), captures);
}

void InfoView::update_game_info(const string &info) {
  Pane::get_section(m_board_info_section)
      ->fill(PaneDrawings::Borders::kempty_row);
  Pane::format_section(get_section(m_board_info_section), info);
}
