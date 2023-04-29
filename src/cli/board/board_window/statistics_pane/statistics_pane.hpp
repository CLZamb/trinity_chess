#ifndef UI_STATISTICS_PANE_H
#define UI_STATISTICS_PANE_H
/*
 *  WIP
 * */

#include "board/board_window/IBoard_side_pane.h"
#include "board/board_window/info_pane/info_drawings.hpp"
#include "ui/components/pane.h"

class StatisticsPane : public IBoardSidePane {
public:
  StatisticsPane() {
    Pane::add_section(m_top_section, 1);
    Pane::add_section(m_engine_name_section, 2);
    Pane::add_section(m_nodes_section, 2);
    Pane::add_section(m_ply_section, 2);
    Pane::add_section("middle", 36);
    clear();
    Pane::format_section(get_section("middle"), "");
    Pane::format_section(get_section(m_engine_name_section), "trinity");
    Pane::format_section(get_section(m_nodes_section), "some number");
    Pane::format_section(get_section(m_ply_section), "some other number");
  }

  virtual ~StatisticsPane() = default;

  void update() override {}
  void make_move(const Move &) override {}

private:
  void clear() {
    Pane::fill(PaneDrawings::Borders::kempty_row);
    Pane::set_content_at_section(m_top_section, {PaneDrawings::Borders::ktop_drawing});
    Pane::set_content_at_section(m_bottom_section, {PaneDrawings::Borders::kbottom_drawing});
  }
  const string m_top_section = "top";
  const string m_engine_name_section = "engine name";
  const string m_nodes_section = "nodes";
  const string m_ply_section = "ply";
  const string m_bottom_section = "bottom";
};


#endif /* UI_BOARD_INFO_CONTROLLER_H */
