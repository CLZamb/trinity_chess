#include "headers/human_player.h"

HumanPlayer::HumanPlayer(PlayerInput& p, SquareIndices sq) : m_input(p) {
  set_initial_pos(sq);
}

HumanPlayer::~HumanPlayer() {}


void HumanPlayer::set_initial_pos(SquareIndices sq) {
  m_player_pos.set_from_position(sq);
  m_player_pos.set_to_position(sq);
}

const string &HumanPlayer::get_player_string_move() {
  m_string_player_input = m_input.get_player_string_move(m_player_pos);
  return m_string_player_input;
}
