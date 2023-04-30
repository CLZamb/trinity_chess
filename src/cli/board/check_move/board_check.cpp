#include "board_check.h"

#include <memory>

#include "board_check_behaviour.h"

using std::make_unique;

BoardCheck::BoardCheck(Position& p):
  p_behaviour(
    make_unique<CheckBehaviour>(p, m_side)
  ) {}

void BoardCheck::update_turn(const Color &turn) { 
  m_side = turn; 
}

bool BoardCheck::is_checkmate() {
  return p_behaviour->is_checkmate();
}

bool BoardCheck::is_string_move_format_valid(const std::string& s) {
  return p_behaviour->is_string_format_valid(s);
}

bool BoardCheck::is_legal_move(Move& m) {
  return p_behaviour->is_legal_move(m);
}

bool BoardCheck::is_player_in_check(const Move& m) {
  return p_behaviour->is_player_in_check(m);
}

void BoardCheck::set_behaviour(std::unique_ptr<IBoardCheckBehaviour>&& t) {
  p_behaviour = std::move(t);
}

std::unique_ptr<IBoardCheckBehaviour>&& BoardCheck::get_behaviour() {
  return std::move(p_behaviour);
}
