#include "board_ui.h"
#include "ui/graphics/board/info/board_info_controller.h"

using std::make_shared;

BoardUi::BoardUi(BoardFen& bf, InputType input) : 
  m_board_fen(bf),
  m_board_controller(m_board_view, m_board_fen),
  p_boardview_controller(
    make_shared<BoardController>(m_board_view, m_board_fen)),
  p_board_input(m_board_input_builder.get_new_board_input(input)) {}

BoardUi::~BoardUi() {}

void BoardUi::add_info_pane() {
  m_board_view.add_right_pane(&m_info_pane);
  p_boardview_controller = make_shared<UiBoardInfoController>(
      p_boardview_controller, m_info_pane, m_board_model_info);
}

void BoardUi::update_view() {
  p_boardview_controller->update();
}

void BoardUi::update_turn(const PlayerInfo &t) {
  m_turn = t;
  m_board_model_info.update_turn(t);
  m_info_pane.update_turn(t);
  // m_input.update_turn(t);
}

void BoardUi::print_view() {
  p_boardview_controller->print();
}

void BoardUi::save_move(const Move& mv) {
  m_board_model_info.save_move(mv);
}

void BoardUi::update_board_info(const string &s) {
  m_board_model_info.save_info(s);
}

string BoardUi::get_next_string_move() {
  return p_board_input->get_next_string_move(m_board_view);
}
