#ifndef UI_STATISTICS_PANE_H
#define UI_STATISTICS_PANE_H

#include "ui/graphics/board/decorators/board_decorator.hpp"
#include "ui/graphics/components/pane.h"
#include "ui/graphics/drawings/info_drawings.hpp"

class StatisticsPane : public BoardDecorator {
public:
  StatisticsPane(shared_ptr<IUiPaneComponent> p) : BoardDecorator(p) {
    add_section(m_top_section, 1);
    add_section(m_middel_section, 42);
    add_section(m_bottom_section, 1);

    get_section(m_top_section)
        ->set_drawing_at_index(InfoDrawings::Borders::ktop_drawing, 0);

    for (size_t i = 0; i < 42; ++i) {
      get_section(m_middel_section)
        ->set_drawing_at_index(InfoDrawings::Borders::kempty_row, i);
    }

    get_section(m_bottom_section)
        ->set_drawing_at_index(InfoDrawings::Borders::kbottom_drawing, 0);
  }

  virtual ~StatisticsPane() = default;

  void update() override { BoardDecorator::update(); }

private:
  const string m_top_section = "top";
  const string m_bottom_section = "bottom";
  const string m_middel_section = "middle";
};

#endif /* UI_BOARD_INFO_CONTROLLER_H */
