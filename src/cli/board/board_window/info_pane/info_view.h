#ifndef INFO_VIEW_H
#define INFO_VIEW_H

#include <map>

#include "info_drawings.hpp"
#include "ui_components/pane.h"

class InfoView : public Pane {
 public:
  explicit InfoView();
  virtual ~InfoView();

  void update_moves(const std::string &s, Color c);
  void update_captures(const std::string &s, Color c);
  void update_game_info(const std::string &i);
  void update_banner(Color c);

 private:
  void clear();
  void clear_all_sections();

  const std::string m_top_section = "top";
  const std::string m_player_banner_section = "Player banner";
  const std::string m_board_info_section = "[Board info]";
  const std::string m_bottom_section = "bottom";
  const std::array<std::string, Color::SIZE> m_moves_section{"[White Moves]",
                                                             "[Black Moves]"};
  const std::array<std::string, Color::SIZE> m_captures_section{
      "[White Captures]", "[Black Captures]"};
  std::array<std::string, Color::SIZE> m_turn_string{"Is white turn",
                                                     "Is black turn"};

  std::array<const std::vector<std::string> *, Color::SIZE> p_banners{
      &InfoDrawings::Banner::white, &InfoDrawings::Banner::black};

  static const size_t Kboard_pane_size{44};
};

#endif
