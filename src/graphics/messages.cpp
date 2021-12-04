#include "headers/messages.h"

Messages::Messages() :
  Displayable(1),
  m_no_message(this),
  m_start_or_quit(this),
  m_players_options(this),
  m_game_over(this),
  m_choose_color(this),
  p_current_state(&m_no_message) {
    m_drawing.add_section(p_main);
  }
Messages::~Messages() {}

void Messages::set_message(MessageState* state) {
  this->p_current_state = state;
}

void Messages::draw() {
  m_drawing.fill(p_current_state->get_message());
}

MessageState* Messages::get_play_or_quit() {
  return &m_start_or_quit;
}

MessageState* Messages::get_players_options() {
  return &m_players_options;
}

MessageState* Messages::get_game_over() {
  return &m_game_over;
}

MessageState* Messages::get_choose_color() {
  return &m_choose_color;
}

MessageState* Messages::get_no_message() {
  return &m_no_message;
}
