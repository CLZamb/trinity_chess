#include "AiPlayer.h"

AiPlayer::AiPlayer(bool has_black_pieces, Movement::MoveGenerator* p_generator)
    : Player(has_black_pieces), p_move_generator(p_generator) {
  std::cout << "created a AiPlayer" << std::endl;
  m_move.set_str_input("");
}

AiPlayer::~AiPlayer() {}

Move AiPlayer::get_next_move() {
  std::cout << "Thinking...\n";
  m_move = p_move_generator->get_best_move();
  return m_move;
}
