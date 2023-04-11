#include "board_ui.h"
#include "ui/graphics/board/decorators/info/board_check_info_decorator.h"
#include "ui/graphics/board/decorators/info/board_view_info_decorator.h"
// #include "board/board_representation/board.h"
// #include "ui/input/board/board_input.h"
#include "ui/input/board/keyboard/keyboard_input_board.h"
#include "ui/input/board/text/text_input_board.h"

using std::make_unique;

BoardUi::BoardUi(const string& fen, InputType input) : 
  m_board_pane(fen),
  m_board_view(m_board_pane),
  p_input(set_new_input(input)) {
}

BoardUi::~BoardUi() {}


// void BoardUi::add_info_pane(BoardCheck& board_check) {
//   wrap_board_view();
//   wrap_board_check(board_check);
// }

void BoardUi::wrap_board_view() {
  // m_board_view.add_right_pane(
  //   make_unique<BoardViewInfoDecorator>(
  //     std::move(m_board_view.get_pane_components()), m_board_model_info
  //   )
  // );
}

void BoardUi::wrap_board_check(BoardCheck& board_check) {
  board_check.set_behaviour(
    make_unique<BoardCheckInfoDecorator>(
      std::move(board_check.get_behaviour()), m_board_model_info
    )
  );
}

void BoardUi::update_view() {
  m_board_view.update();
}

void BoardUi::attach_components_to_game_turn(GameTurn &gt) {
  gt.attach(&m_board_model_info);
  gt.attach(p_input.get());
}

void BoardUi::print_view() {
  m_board_view.print();
}

void BoardUi::make_move(const Move& mv) {
  save_move(mv);
  m_board_pane.make_move(mv);
}

void BoardUi::save_move(const Move& mv) {
  m_board_model_info.save_move(mv);
}

void BoardUi::update_board_info(const string &s) {
  m_board_model_info.save_info(s);
}

std::unique_ptr<BoardInput> BoardUi::set_new_input(InputType input) {
  if (input == InputType::Keyboard)
    return std::make_unique<KeyboardInputBoard>(m_board_pane);

  return std::make_unique<TextInputBoard>();
}

string BoardUi::get_next_string_move() {
  string next_string_move;
  BoardInput::InputEvent e = BoardInput::NO_EVENT;

  do {
    e = p_input->get_next_string_move(next_string_move);

    switch(e) {
      case BoardInput::COMPLETED:
        break;
      case BoardInput::PRINT:
        m_board_pane.update();
        m_board_view.print();
      default:
        break;
    }

  } while(e != BoardInput::InputEvent::COMPLETED);

  return next_string_move;
}

