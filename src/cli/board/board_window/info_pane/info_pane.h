#ifndef INFO_VIEW_H
#define INFO_VIEW_H

#include <map>

#include "board/board_window/IBoard_side_pane.h"
#include "board/board_window/info_pane/board_info_model.h"
#include "info_drawings.hpp"

class InfoPane : public IBoardSidePane, public GameTurnObserver {
 public:
  explicit InfoPane(std::shared_ptr<BoardModelInfo> b);
  virtual ~InfoPane();

  void update() override;
  void make_move(const Move &mv) override;
  void update_turn(const Color &info) override;

 private:
  void update_moves(const string &s, Color c);
  void update_captures(const string &s, Color c);
  void update_game_info(const string &i);
  void update_banner(Color c);

  void clear();
  void clear_all_sections();

  const std::string m_top_section = "top";
  const std::string m_player_banner_section = "Player banner";
  const std::string m_board_info_section = "[Board info]";
  const std::string m_bottom_section = "bottom";
  const std::array<std::string, Color::SIZE> m_moves_section{"[White Moves]",
                                                        "[Black Moves]"};
  const std::array<std::string, Color::SIZE> m_captures_section{"[White Captures]",
                                                           "[Black Captures]"};
  std::array<std::string, Color::SIZE> m_turn_string{"Is white turn",
                                                "Is black turn"};

  std::array<const std::vector<std::string> *, Color::SIZE> p_banners{
      &InfoDrawings::Banner::white, &InfoDrawings::Banner::black};

  std::shared_ptr<BoardModelInfo> p_info;
};

#endif /* INFO_VIEW_H */
