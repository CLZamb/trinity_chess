#ifndef BOARD_WINDOW_H
#define BOARD_WINDOW_H

#include "ui/board/IBoard_pane_component.h"
#include "ui/components/window.h"
#include <memory>

using std::shared_ptr;
using std::string;

class BoardWindow : public Window {
public:
  BoardWindow() {}

  virtual ~BoardWindow() = default;


  void add_middle_pane(shared_ptr<IBoardPaneComponent> p) {
    Window::add_middle_pane(p.get());
    add_pane_component(p);
  }

  void add_left_pane(shared_ptr<IBoardPaneComponent> p) {
    Window::add_left_pane(p.get());
    add_pane_component(p);
  }

  void add_right_pane(shared_ptr<IBoardPaneComponent> p) {
    Window::add_right_pane(p.get());
    add_pane_component(p);
  }

private:
  void add_pane_component(shared_ptr<IBoardPaneComponent> p) {
    panes.push_back(p);
  }

  vector<shared_ptr<IBoardPaneComponent>> panes;
};

#endif /* BOARD_WINDOW_H */
