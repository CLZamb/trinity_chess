#include "board_ui.h"
#include "ui/graphics/board/decorators/info/board_check_info_decorator.h"
#include "ui/graphics/board/decorators/statistics/statistics_pane.hpp"
#include "ui/input/board/keyboard/keyboard_input_board.h"

using std::make_shared;
using std::make_unique;

auto BoardUi::new_board_keyboard_pane(const string &fen) {
  return make_shared<BoardKeyboardPane>(fen);
}

auto BoardUi::new_keyboard_event_handler(shared_ptr<IKeyboardBoardInput> b) {
  return make_shared<KeyboardEventHandler>(b);
}

auto BoardUi::set_up_input(InputType type) {
  if (type == InputType::Keyboard) 
    return make_unique<KeyboardInputBoard>();

  return make_unique<KeyboardInputBoard>();
}

auto BoardUi::get_new_keyboard_board_pane(const string &fen) {
  auto k_board_p = new_board_keyboard_pane(fen);
  p_event_handler = new_keyboard_event_handler(k_board_p);

  m_board_view.add_board_pane(k_board_p);
  m_board_view.add_input_event_handler(p_event_handler);
  return k_board_p;
}

BoardUi::BoardUi(const string &fen, BoardConfig &bc) {
  p_board_pane = get_new_keyboard_board_pane(fen);
  p_input = set_up_input(bc.get_input_type());
}

BoardUi::~BoardUi() {}

void BoardUi::add_info_pane(BoardCheck &board_check) {
  wrap_board_check_behaviour(board_check);
  add_side_panes();
}

void BoardUi::add_statistics_pane() {
  auto p_side_pane =
      make_shared<InfoPane>(p_board_pane, m_board_model_info);

  m_board_view.add_left_pane(p_side_pane);
}

void BoardUi::add_side_panes() {
  bool info = true, statistics = true;
  shared_ptr<IUiPaneComponent> side_panes = p_board_pane;

  if (info) 
    side_panes = add_info_pane(side_panes);

  if (statistics)
    side_panes = add_statistics_pane(side_panes);
}

shared_ptr<IUiPaneComponent> BoardUi::add_info_pane(shared_ptr<IUiPaneComponent> side_pane) {
  side_pane = make_shared<InfoPane>(side_pane, m_board_model_info);
  m_board_view.add_right_pane(side_pane);
  return side_pane;
}

shared_ptr<IUiPaneComponent> BoardUi::add_statistics_pane(shared_ptr<IUiPaneComponent> side_pane) {
  side_pane = make_shared<StatisticsPane>(side_pane);
  m_board_view.add_left_pane(side_pane);
  return side_pane; 
}

void BoardUi::wrap_board_check_behaviour(BoardCheck &board_check) {
  board_check.set_behaviour(make_unique<BoardCheckInfoDecorator>(
      std::move(board_check.get_behaviour()), m_board_model_info));
}

void BoardUi::update_view() { m_board_view.update(); }

void BoardUi::attach_ui_elements(SideToMove &stm) {
  stm.attach(&m_board_model_info);
  stm.attach(p_event_handler.get());
}

void BoardUi::print_view() { m_board_view.print(); }

void BoardUi::make_move(const Move &mv) {
  m_board_model_info.save_move(mv);
  // m_board_view.make_move(mv);
  p_board_pane->make_move(mv);
}

void BoardUi::update_board_info(const string &s) {
  m_board_model_info.save_info(s);
}

string BoardUi::get_next_string_move() {
  string next_string_move{""};
  bool is_completed{false};
  KeyCode::Key e;

  do {
    e = p_input->get_input_event();
    is_completed = m_board_view.handle_input(e, next_string_move);
    p_board_pane->update();
    m_board_view.print();

  } while (!is_completed);

  return next_string_move;
}

