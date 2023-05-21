#include "board_window.h"

BoardWindow::BoardWindow(BoardConfigInfo &board_config)
    : m_board_pane(board_config) {
  Window::add_pane(m_board_pane.get_view(), Window::MIDDLE_PANE);
  m_board_pane.bind(&BoardWindow::on_board_updated, this);
}

void BoardWindow::on_board_updated(PrintWindowEvent &) { Window::print(); }

void BoardWindow::update() {
  m_board_pane.update();

  for (auto side_pane : p_side_panes) {
    side_pane->update();
  }
}

void BoardWindow::print() {
  update();
  Window::print();
}

std::string BoardWindow::get_move_as_string() {
  return m_board_pane.get_move_as_string();
}

void BoardWindow::make_move(const Move &mv) { m_board_pane.make_move(mv); }

void BoardWindow::add_side_pane(std::shared_ptr<IBoardPaneComponent> side_pane,
                                Window::PanePos pos) {
  if (!side_pane) return;

  Window::add_pane(side_pane->get_view(), pos);
  p_side_panes.push_back(side_pane);
}
