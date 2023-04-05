#include "human_player.h"

HumanPlayer::HumanPlayer(BoardInput& p, SquareIndices sq) : m_input(p) {
  set_initial_pos(sq);
}

HumanPlayer::~HumanPlayer() {}

const string &HumanPlayer::get_player_string_move() {
  m_string_player_input = m_input.get_next_string_move();;
  return m_string_player_input;
}
