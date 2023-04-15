#include "board_view.h"

BoardView::BoardView(const string fen, const BoardConfig &bc) {
  if (bc.get_input_type() == Keyboard) {
    add_keyboard_pane(fen);
    add_input(m_components.new_input(Keyboard));
  } else {
    add_board_pane(fen);
    add_input(m_components.new_input(Text));
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
  string next_string_move{""};
  bool is_completed{false};
  KeyCode::Key e;

  do {
    e = get_input_event();
    is_completed = get_board_pane()->handle_event(e, next_string_move);

    if (!is_completed) print();

  } while (!is_completed);

  return next_string_move;
}

void BoardView::make_move(const Move &mv) {
  get_board_pane()->make_move(mv);
  m_board_model_info.save_move(mv);
}

void BoardView::add_board_pane(const string &fen) {
  auto board_pane = m_components.new_board_pane(fen);
  add_middle_pane("board", board_pane);
  set_board_pane(board_pane);
}

void BoardView::add_keyboard_pane(const string &fen) {
  auto board_pane = m_components.new_board_keyboard_pane(fen);
  add_middle_pane("keyboard board", board_pane);
  set_board_pane(board_pane);
}

void BoardView::add_info_pane(BoardCheck &b) {
  b.set_behaviour(m_components.new_info_check_behaviour(b, m_board_model_info));
  add_right_pane("info", m_components.new_info_pane(m_board_model_info));
}
