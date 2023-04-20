#include "board_view.h"
#include "ui/components/board_components.hpp"

BoardView::BoardView(const string f, const BoardConfig &bc, SideToMove &t)
    : m_turn(t) {
  auto board_pane = BoardComponents::new_board_pane(f);
  m_board_window.add_middle_pane(board_pane);

  InputType type = bc.get_input_type();

  type == Keyboard ? set_keyboard_input(board_pane, m_turn)
                   : set_text_input(board_pane);
}

BoardView::~BoardView() {}

void BoardView::make_move(const Move &m) { 
  m_board_window.make_move(m); 
}

void BoardView::update() { 
  m_board_window.update_panes(); 
}

void BoardView::print() { 
  m_board_window.print(); 
}

void BoardView::add_info_pane(BoardCheck &b) {
  auto info_pane = BoardComponents::new_info_pane(b);
  m_board_window.add_right_pane(info_pane);
  m_turn.attach(info_pane.get());
}

void BoardView::set_keyboard_input(shared_ptr<BoardPane> board_pane, SideToMove& turn) {
  p_input = BoardComponents::new_input_keyboard();
  p_input_event_handler = BoardComponents::new_keyboard_handler(board_pane, p_input, turn);
}

void BoardView::set_text_input(shared_ptr<BoardPane> board_pane) {
  p_input = BoardComponents::new_input_text();
  p_input_event_handler = BoardComponents::new_text_handler(board_pane, p_input);
}

string BoardView::get_next_string_move() {
  do {
    p_input->get_input_event();

    if (!p_input_event_handler->has_events())
      break;

    print();
  } while (true);

  return p_input_event_handler->get_string();
}
