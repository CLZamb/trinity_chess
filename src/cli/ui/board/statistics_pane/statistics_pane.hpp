#ifndef UI_STATISTICS_PANE_H
#define UI_STATISTICS_PANE_H

// #include "ui/board/panes/board_decorator.hpp"
#include "ui/board/IBoard_pane_component.h"
#include "ui/components/pane.h"

class StatisticsPane : public IBoardPaneComponent {
public:
  StatisticsPane() {
    add_section(m_top_section, 1);
    add_section(m_middel_section, 42);
    add_section(m_bottom_section, 1);

    // get_section(m_top_section)
    //     ->set_drawing_at_index(InfoDrawings::Borders::ktop_drawing, 0);
    //
    // for (size_t i = 0; i < 42; ++i) {
    //   get_section(m_middel_section)
    //     ->set_drawing_at_index(InfoDrawings::Borders::kempty_row, i);
    // }
    //
    // get_section(m_bottom_section)
    //     ->set_drawing_at_index(InfoDrawings::Borders::kbottom_drawing, 0);
  }

  virtual ~StatisticsPane() = default;

  void update() override {}

private:
  const string m_top_section = "top";
  const string m_bottom_section = "bottom";
  const string m_middel_section = "middle";
};

#endif /* UI_BOARD_INFO_CONTROLLER_H */
