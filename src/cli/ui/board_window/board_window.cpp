#include "board_window.h"
#include "ui/components/board_components.hpp"

BoardWindow::BoardWindow(const string fen, const BoardConfig &bc, SideToMove &t)
: m_turn(t) {
  auto board_pane = BoardComponents::new_board_pane(fen);

  InputType type = bc.get_input_type();

  type == Keyboard ? 
    set_keyboard_input(board_pane, m_turn) : 
    set_text_input(board_pane);

  add_middle_pane(board_pane);
}

void BoardWindow::make_move(const Move &m) { 
  for (auto pane : panes)
    pane->make_move(m);
}

void BoardWindow::update() { 
  for (auto pane : panes)
    pane->update();
}

void BoardWindow::print() { 
  Window::print();
}

void BoardWindow::add_info_pane(BoardCheck &b) {
  auto info_pane = BoardComponents::new_info_pane(b);
  m_turn.attach(info_pane.get());
  add_left_pane(info_pane);
}

void BoardWindow::add_statistics_pane() {
  auto stats_pane = BoardComponents::new_statistics_pane();
  add_right_pane(stats_pane);
}

void BoardWindow::set_keyboard_input(shared_ptr<BoardPane> board_pane, SideToMove& turn) {
  p_input_event = BoardComponents::new_input_keyboard();
  p_input_event_handler = BoardComponents::new_keyboard_handler(board_pane, p_input_event, turn);
}

void BoardWindow::set_text_input(shared_ptr<BoardPane> board_pane) {
  p_input_event = BoardComponents::new_input_text();
  p_input_event_handler = BoardComponents::new_text_handler(board_pane, p_input_event);
}

string BoardWindow::get_next_string_move() {

  do {
    p_input_event->listen_for_input_events();

    if (p_input_event_handler->is_string_move_ready())
      break;

    print();
  } while (true);

  return p_input_event_handler->get_string_move();
}

void BoardWindow::add_middle_pane(shared_ptr<IBoardPane> p) {
  Window::add_middle_pane(p.get());
  add_pane(p);
}

void BoardWindow::add_left_pane(shared_ptr<IBoardPane> p) {
  Window::add_left_pane(p.get());
  add_pane(p);
}

void BoardWindow::add_right_pane(shared_ptr<IBoardPane> p) {
  Window::add_right_pane(p.get());
  add_pane(p);
}

void BoardWindow::add_pane(shared_ptr<IBoardPane> p) {
  panes.push_back(p);
}
