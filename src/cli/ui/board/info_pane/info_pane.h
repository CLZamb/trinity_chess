#ifndef INFO_VIEW_H
#define INFO_VIEW_H

#include "ui/board/IBoard_pane_component.h"
#include "ui/board/info_pane/board_info_model.h"
#include "info_drawings.hpp"
#include <map>

using std::string;

class InfoPane : public IBoardPaneComponent, public GameTurnObserver {
public:
  InfoPane(shared_ptr<BoardModelInfo> b);
  virtual ~InfoPane();

  void update() override;
  void make_move(const Move &mv) override;
  void update_turn(const PlayerInfo &info) override;

private:
  void update_moves(const string &s, Color c);
  void update_captures(const string &s, Color c);
  void update_game_info(const string &i);
  void update_banner(Color c);

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
  array<string, Color::SIZE> m_turn_string{"Is white turn", "Is black turn"};

  array<const vector<string> *, Color::SIZE> p_banners {
    &InfoDrawings::Banner::white,
    &InfoDrawings::Banner::black
  };

  shared_ptr<BoardModelInfo> p_info;
};

#endif /* INFO_VIEW_H */
