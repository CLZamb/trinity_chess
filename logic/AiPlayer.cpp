#include "AiPlayer.h"

AiPlayer::AiPlayer(bool has_black_pieces, Movement* movement_controller) :
  Player(has_black_pieces),
  p_move_generator(new Movement::MoveGenerator(movement_controller))
{
  m_pl_move.m_input = "";
}

AiPlayer::~AiPlayer() {
  delete p_move_generator;
}

PlayerMove AiPlayer::get_next_move() {
  std::cout << "Thinking...\n";
  m_move = p_move_generator->search_best_move();
  m_pl_move.set_move(m_move);
  m_pl_move.set_ply_input(m_move.get_move() ? "" : "quit");
  return m_pl_move;
}
