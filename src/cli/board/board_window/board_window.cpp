#include "board_window.h"

#include "board_components.hpp"
#include "game/turn/side_to_move.h"
#include "input/input_components.h"
#include "ui_components/window.h"

BoardWindow::BoardWindow() {}

void BoardWindow::set_board_pane(std::unique_ptr<IBoardPane> &&board_pane,
                                 Window::PanePos pane_pos) {
  p_board_pane = std::move(board_pane);
  Window::add_pane(p_board_pane.get(), pane_pos);
}

void BoardWindow::set_input(std::unique_ptr<Input> &&i) {
  p_input = std::move(i);
}

void BoardWindow::make_move(const Move &m) {
  for (const auto &pane : m_side_panes) { pane->make_move(m); }

  p_board_pane->make_move(m);
}

void BoardWindow::parse_fen(const FenFields &fen) { p_board_pane->parse_fen(fen); }

void BoardWindow::update() {
  for (const auto &pane : m_side_panes) { 
    pane->update();
  }

  p_board_pane->update_drawing();
}

void BoardWindow::print() { Window::print(); }

std::string BoardWindow::get_player_move_as_string() {
  do {
    p_input->listen_for_input_events();

    if (p_board_pane->is_player_string_move_ready()) { break; }

    print();
  } while (true);

  return p_board_pane->get_player_move_as_string();
}

void BoardWindow::set_side_pane(std::unique_ptr<IBoardSidePane> &&pane,
                                Window::PanePos pos) {
  Window::add_pane(pane.get(), pos);
  m_side_panes.push_back(std::move(pane));
}
