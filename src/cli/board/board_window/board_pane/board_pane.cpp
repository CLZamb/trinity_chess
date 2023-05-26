#include "board_pane.h"

#include "board/board_window/board_components.hpp"

namespace BD = BoardDrawings::Board;
using std::string;
using BP = BoardPane;
using PtrIC = std::unique_ptr<InputComponent>;
using KEH = KeyboardEventHandler;
namespace BC = BoardComponents;

BoardPane::BoardPane(const BoardConfigInfo &b_info) {
  m_view.parse_fen(b_info.fen_fields);
  setup_player_input_component(b_info);
  update();
}

void BoardPane::setup_player_input_component(const BoardConfigInfo &b_info) {
  switch (b_info.input_type) {
    case InputType::Keyboard:
      setup_keyboard_input(b_info.initial_side);
      break;
    case InputType::Text:
      setup_text_input();
      break;
    default:
      break;
  }
}

void BoardPane::setup_keyboard_input(Color side) {
  event_handler = BC::new_keyboard_event_handler(side, m_view);
  event_handler->bind(&BoardPane::on_key_pressed, this);
}

void BoardPane::on_key_pressed(EventKeyboard &) {
  update();
  send_event(m_reprint_ui_event);
}

void BoardPane::setup_text_input() {
  event_handler = BC::new_text_event_handler();
  event_handler->bind(&BoardPane::on_text, this);
}

void BoardPane::on_text(EventText &) { update(); }

void BoardPane::make_move(const Move &mv) {
  m_view.make_move(mv);
  event_handler->change_side();
}

std::string BoardPane::get_move_as_string() {
  return event_handler->get_move_as_string();
}

void BoardPane::update() { m_view.update_drawing(); }
