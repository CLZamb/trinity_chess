#include "AiPlayer.h"

AiPlayer::AiPlayer(bool has_black_pieces, Movement* movement_controller) :
  Player(has_black_pieces),
  p_move_generator(new Movement::MoveGenerator(movement_controller))
{
  m_pl_move.set_ply_input("");
  init_square_strings_names();
}

void AiPlayer::init_square_strings_names() {
  int position = 0;
  char file = '1';
  char rank = 'A';
  for (int row = 7; row >= 0; --row) {
    for (int col = 0; col < 8; ++col) {
      position = row * 8 + col;
      square_str[position] = (rank + col);
      square_str[position] += (file + row);
    }
  }
}

AiPlayer::~AiPlayer() {
  delete p_move_generator;
}

PlayerMove AiPlayer::get_next_move() {
  std::cout << "Thinking...\n";
  m_move = p_move_generator->search_best_move();
  m_pl_move.set_move(m_move);
  m_pl_move.set_ply_input(convert_to_string_pos(m_move));
  return m_pl_move;
}

string AiPlayer::convert_to_string_pos(Move mv) {
  if (mv.get_move() == 0)
    return "quit";

  int from = mv.get_from();
  int to = mv.get_to();
  return square_str[from] + square_str[to];
}
