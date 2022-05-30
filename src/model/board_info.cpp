#include "headers/board_info.h"

BoardInfo::BoardInfo() {}

void BoardInfo::update_turn(const PlayerInfo& t){
  m_turn = t;
}

void BoardInfo::save_move(const string& move) {
  m_moves[m_turn.get_turn()] += move + " ";
}

void BoardInfo::save_capture(const string& move) {
  m_captures[m_turn.get_turn()] += move + " ";
}

string BoardInfo::get_moves() {
  return m_moves[m_turn.get_turn()];
}

string BoardInfo::get_captures() {
  return m_captures[m_turn.get_turn()];
}
