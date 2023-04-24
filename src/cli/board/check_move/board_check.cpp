#include <memory>
#include "board_check_behaviour.h"
#include "board_check.h"

using std::make_unique;

BoardCheck::BoardCheck(Position& p):
  p_behaviour(
    make_unique<CheckBehaviour>(p, m_turn_info)
  ) {}

void BoardCheck::update_turn(const PlayerInfo &turn) { 
  m_turn_info = turn; 
}

bool BoardCheck::is_checkmate() {
  return p_behaviour->is_checkmate();
}

bool BoardCheck::is_string_format_valid(const string& s) {
  return p_behaviour->is_string_format_valid(s);
}

bool BoardCheck::is_legal_move(Move& m) {
  return p_behaviour->is_legal_move(m);
}

bool BoardCheck::is_in_check(const Move& m) {
  return p_behaviour->is_in_check(m);
}

void BoardCheck::set_behaviour(std::unique_ptr<IBoardCheckBehaviour>&& t) {
  p_behaviour = std::move(t);
}

std::unique_ptr<IBoardCheckBehaviour>&& BoardCheck::get_behaviour() {
  return std::move(p_behaviour);
}
