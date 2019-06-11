#include "AiPlayer.h"

AiPlayer::AiPlayer(bool has_black_pieces, Search* search) :
  Player(has_black_pieces),
  p_search(search)
{
  m_pl_move.set_ply_input("");
}

AiPlayer::~AiPlayer() {
  if (p_search)
    delete p_search;
}

PlayerMove AiPlayer::get_next_move() {
  std::cout << "Thinking...\n";
  m_move = p_search->search_best_move();
  m_pl_move.set_move(m_move);
  m_pl_move.set_ply_input(convert_to_string_pos(m_move));
  return m_pl_move;
}

string AiPlayer::convert_to_string_pos(Move mv) {
  if (mv.get_move() == 0)
    return "quit";

  int from = mv.get_from();
  int to = mv.get_to();
  return
    utils::constant::sq_int_pos_to_str[from] +
    utils::constant::sq_int_pos_to_str[to];
}
