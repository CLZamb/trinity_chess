#include "headers/board_info.h"

BoardInfo::BoardInfo() {}

void BoardInfo::update_turn(const PlayerInfo& t){
  m_turn = t;
  save_info(m_turn_string[m_turn.color]);
}

void BoardInfo::wrong_format(const string &s) {
  save_info("{ " + s + " }" + Kwrong_format);
}

void BoardInfo::illegal_move(const string &s) {
  save_info("{ " + s + " }" + Killegal_move);
}

void BoardInfo::save_move(const Move &mv) {
  m_moves[m_turn.turn] += get_move_string(mv) + " ";

  if (mv.get_captured_piece())
    m_captures[m_turn.turn] += get_captured_string(mv) + " ";
}

string BoardInfo::get_move_string(const Move &m) {
  return utils::square_int_to_str(m.get_from()) + utils::square_int_to_str(m.get_to());
}

string BoardInfo::get_captured_string(const Move &m) {
  return utils::get_piece_str_name_from_piecetype(m.get_captured_piece());
}

void BoardInfo::save_info(const string &info) {
  m_info = info;
}

string BoardInfo::get_moves() {
  return m_moves[m_turn.turn];
}

string BoardInfo::get_captures() {
  return m_captures[m_turn.turn];
}

string BoardInfo::get_info() {
  return m_info;
}

const string BoardInfo::Kwrong_format = 
  " Move is an not in a recognizable format, please try again";
const string BoardInfo::Killegal_move = 
  " Move is an ilegal move";
