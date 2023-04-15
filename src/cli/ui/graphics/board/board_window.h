#ifndef BOARD_WINDOW_H
#define BOARD_WINDOW_H

#include "ui/graphics/board/panes/IUi_board.h"
#include "ui/graphics/components/board_components.hpp"
#include "ui/graphics/components/window.h"

class BoardWindow : public Window {
public:
  BoardWindow() = default;
  virtual ~BoardWindow() = default;

protected:
  void print() { Window::print(); }

  void update_panes() {
    for (auto pane : panes)
      pane.second->update();
  }

  void add_middle_pane(const string name, shared_ptr<IUiPaneComponent> pane) {
    Window::add_middle_pane(pane.get());
    add_pane_component(name, pane);
  }

  void add_left_pane(const string &name, shared_ptr<IUiPaneComponent> pane) {
    Window::add_left_pane(pane.get());
    add_pane_component(name, pane);
  }

  void add_right_pane(const string &name, shared_ptr<IUiPaneComponent> pane) {
    Window::add_right_pane(pane.get());
    add_pane_component(name, pane);
  }

  void set_board_pane(shared_ptr<IBoardPane> b) { p_board_pane = b; }

  shared_ptr<IBoardPane> get_board_pane() { return p_board_pane; }

  void add_input(shared_ptr<BoardInput> input) { p_input = input; }

  shared_ptr<IUiPaneComponent> get_pane_by_name(const string &name) {
    return panes.at(name);
  }

  KeyCode::Key get_input_event() { return p_input->get_input_event(); }

private:
  void add_pane_component(const string &name, shared_ptr<IUiPaneComponent> p) {
    panes.emplace(name, p);
  }

  shared_ptr<IBoardPane> p_board_pane;
  shared_ptr<BoardInput> p_input;
  std::map<string, shared_ptr<IUiPaneComponent>> panes;
};

#endif /* BOARD_WINDOW_H */
