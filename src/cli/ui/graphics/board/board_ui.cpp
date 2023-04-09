#include "board_ui.h"
#include "ui/graphics/board/board_controller.h"
#include "ui/graphics/board/decorators/info/board_check_info_decorator.hpp"
#include "ui/graphics/board/decorators/info/board_view_info_decorator.h"

using std::make_unique;

BoardUi::BoardUi(const BoardFen& bf, InputType input) : 
  p_board_view(make_unique<BoardController>(m_board_view, bf)),
  p_board_input(m_board_input_builder.get_new_board_input(input)) {}

BoardUi::~BoardUi() {}

void BoardUi::add_info_pane(BoardCheck& board_check) {
  wrap_board_view();
  wrap_board_check(board_check);
}

void BoardUi::wrap_board_view() {
  p_board_view = 
    make_unique<BoardViewInfoDecorator>(
      std::move(p_board_view), m_board_view, m_board_model_info
    );
}

void BoardUi::wrap_board_check(BoardCheck& board_check) {
  board_check.set_behaviour(
    std::make_unique<BoardCheckInfoDecorator>(
      std::move(board_check.get_behaviour()), m_board_model_info
    )
  );
}

void BoardUi::update_view() {
  p_board_view->update();
}

void BoardUi::update_turn(const PlayerInfo &t) {
  m_turn = t;
  m_board_model_info.save_player_info(t);
  m_board_model_info.save_info(m_turn_string[m_turn.color]);
}

void BoardUi::print_view() {
  p_board_view->print();
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
