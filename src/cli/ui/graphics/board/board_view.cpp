#include "board_view.h"

BoardView::BoardView(const string fen, const BoardConfig &bc) {
  if (bc.get_input_type() == Keyboard) {
    add_keyboard_pane(fen);
  } else {
    add_board_pane(fen);
  }
}

BoardView::~BoardView() {}

void BoardView::update_turn(const PlayerInfo &p) {
  m_turn_info = p;
  m_board_model_info.update_turn(p);
  get_board_pane()->update_turn(p);
}

void BoardView::update() { BoardWindow::update_panes(); }

void BoardView::print() { BoardWindow::print(); }

string BoardView::get_next_string_move() {

  do {
    get_input()->get_input_event();

    if (get_board_pane()->has_events())
      break;

    print();
  } while (1);

  return get_board_pane()->get_string();
}

void BoardView::make_move(const Move &mv) {
  get_board_pane()->make_move(mv);
  m_board_model_info.save_move(mv);
}

void BoardView::add_board_pane(const string &fen) {
  auto text_input = m_components.new_input_text();
  set_input(text_input);

  auto board_pane = m_components.new_board_pane(fen, text_input);
  set_board_pane(board_pane);
  add_middle_pane("keyboard board", board_pane);
}

void BoardView::add_keyboard_pane(const string &fen) {
  auto keyboard_input = m_components.new_input_keyboard();
  set_input(keyboard_input);

  auto board_pane = m_components.new_board_keyboard_pane(fen, keyboard_input);
  set_board_pane(board_pane);
  add_middle_pane("keyboard board", board_pane);
}

void BoardView::add_info_pane(BoardCheck &b) {
  b.set_behaviour(m_components.new_info_check_behaviour(b, m_board_model_info));

  auto info_pane = m_components.new_info_pane(m_board_model_info);
  add_right_pane("info", info_pane);
}

// void BoardView::add_statistics_pane() {
//   auto statistics = m_components.new_statistics_components();
// }
