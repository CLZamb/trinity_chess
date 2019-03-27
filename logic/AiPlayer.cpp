#include "AiPlayer.h"

AiPlayer::AiPlayer(bool has_black_pieces, Movement::MoveGenerator* p_generator)
    : Player(has_black_pieces), p_move_generator(p_generator) {
  std::cout << "created a AiPlayer" << std::endl;
  m_pl_move.m_input = "";
}

AiPlayer::~AiPlayer() {}

PlayerMove AiPlayer::get_next_move() {
  std::cout << "Thinking...\n";
  m_move = p_move_generator->get_best_move();
  // p_move_generator->testing_zobrist_1();
  m_pl_move.set_move(m_move);
  m_pl_move.set_ply_input(m_move.get_move() ? "" : "quit");
  return m_pl_move;
}
