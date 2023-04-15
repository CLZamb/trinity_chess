#ifndef INFO_VIEW_H
#define INFO_VIEW_H

#include "ui/graphics/board/panes/IUi_board.h"
#include "ui/graphics/board/panes/info/board_info_model.h"
#include "ui/graphics/components/pane.h"
#include "ui/graphics/drawings/info_drawings.hpp"
#include <map>

using std::string;

class InfoPane : public IUiPaneComponent {
public:
  InfoPane(BoardModelInfo& bmi);
  virtual ~InfoPane();
  void update() override;
  void update_turn(const PlayerInfo &info);
  void update_moves(const string &s, Color c);
  void update_captures(const string &s, Color c);
  void update_game_info(const string &i);
  void update_banner(Color c);

private:
  void clear();
  void clear_block();
  void clear_all_sections();
  void set_content_to_block_recursively(shared_ptr<Section> &, string &msg,
                                        size_t &cur_row);
  void format_block(shared_ptr<Section> &, string msg);
  bool has_block_space_for_content(const shared_ptr<Section> &block,
                                   const string &message);
  string format_line(const string &);

  const unsigned int kRowMaxLen = static_cast<unsigned int>(InfoDrawings::Banner::width - 4) /*┃  ┃*/;

  const string m_top_section = "top";
  const string m_player_banner_section = "Player banner";
  const string m_board_info_section = "[Board info]";
  const string m_bottom_section = "bottom";
  const array<string, Color::SIZE> m_moves_section{"[White Moves]",
    "[Black Moves]"};
  const array<string, Color::SIZE> m_captures_section{"[White Captures]",
    "[Black Captures]"};

  array<const vector<string> *, Color::SIZE> p_banners {
    &InfoDrawings::Banner::white,
    &InfoDrawings::Banner::black
  };

  BoardModelInfo& m_info;
};

#endif /* INFO_VIEW_H */