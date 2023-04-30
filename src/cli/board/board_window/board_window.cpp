#include "board_window.h"

#include "board_components.hpp"
#include "ui/input/input_components.h"

BoardWindow::BoardWindow(const string fen,
                         const InputType &input_type,
                         SideToMove &t)
    : m_side_to_move(t)
    , m_board_pane(fen) {
  input_type == Keyboard ? set_keyboard_input(m_board_pane, m_side_to_move)
                         : set_text_input(m_board_pane);

  Window::add_middle_pane(&m_board_pane);
}

void BoardWindow::make_move(const Move &m) {
  for (auto pane : m_side_panes) {
    pane->make_move(m);
  }

  m_board_pane.make_move(m);
}

void BoardWindow::parse_fen(const string &fen) { m_board_pane.parse_fen(fen); }

void BoardWindow::update() {
  for (auto pane : m_side_panes) {
    pane->update();
  }

  m_board_pane.update();
}

void BoardWindow::print() { Window::print(); }

void BoardWindow::add_info_pane(BoardCheck &b) {
  auto info_pane = BoardComponents::new_info_pane(b);
  add_side_pane(info_pane, Window::Left_pane);
  m_side_to_move.attach(info_pane.get());
}

void BoardWindow::add_statistics_pane() {
  auto stats_pane = BoardComponents::new_statistics_pane();
  add_side_pane(stats_pane, Window::Right_pane);
}

void BoardWindow::set_keyboard_input(BoardPane &b, SideToMove &t) {
  p_input = InputComponents::new_input_keyboard();
  p_input_event_handler = BoardComponents::new_keyboard_handler(b, p_input, t);
}

void BoardWindow::set_text_input(BoardPane &b) {
  p_input = InputComponents::new_input_text(" >> ");
  p_input_event_handler = BoardComponents::new_text_handler(b, p_input);
}

string BoardWindow::get_player_move_as_string() {
  do {
    p_input->listen_for_input_events();

    if (p_input_event_handler->is_player_string_move_ready()) {
      break;
    }

    print();
  } while (true);

  return p_input_event_handler->get_player_move_as_string();
}

void BoardWindow::add_side_pane(std::shared_ptr<IBoardSidePane> p,
                                Window::Pane_pos pos) {
  Window::add_pane(p.get(), pos);
  m_side_panes.push_back(p);
}
