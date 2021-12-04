#include "headers/message_state.h"

MessageState::MessageState(Messages* msg) : p_messages(msg) {}
MessageState::~MessageState() {}

Play_or_quit::Play_or_quit(Messages* msg) : MessageState(msg) {
  p_message = p_play_or_quit_message;
}

Players_options::Players_options(Messages* msg) : MessageState(msg) {
  p_message = p_options_players;
}

Game_over::Game_over(Messages* msg) : MessageState(msg) {
  p_message = p_game_over;
}

Choose_color::Choose_color(Messages* msg) : MessageState(msg) {
  p_message = p_choose_color_message;
}

No_message::No_message(Messages* msg) : MessageState(msg) {
  p_message = p_no_message;
}
