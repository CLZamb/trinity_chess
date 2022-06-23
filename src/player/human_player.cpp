#include "headers/human_player.h"

HumanPlayer::HumanPlayer() {}

const string &HumanPlayer::get_player_string_move() const {
  return m_string_player_input;
}
