
#ifndef BOARD_WINDOW_H
#define BOARD_WINDOW_H

#include <memory>
#include <vector>
#include "board/board_window/board_pane/board_pane.h"
#include "components/window.h"

class BoardWindow : public Window {
 public:
  explicit BoardWindow(BoardConfigInfo &board_config);
  void add_side_pane(std::shared_ptr<IBoardPaneComponent> side_pane ,Window::PanePos pos);
  void print();
  void make_move(const Move& mv);
  std::string get_move_as_string();

 private:
  void update();
  void on_board_updated(PrintWindowEvent&);
  std::vector<std::shared_ptr<IBoardPaneComponent>> p_side_panes;
  BoardPane m_board_pane;
};

#endif /* BOARD_WIDOW_H */
