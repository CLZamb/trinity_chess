#include "headers/board_info.h"

const string BoardInfo::Kwrong_format = 
  "Move is an not in a recognizable format, please try again";
const string BoardInfo::Killegal_move = 
  "Move is an ilegal move";
const string BoardInfo::Kcheck_move = 
  "cannot make that move, player is in check";

BoardInfo::BoardInfo() {}

void BoardInfo::update_turn(const PlayerInfo& t){
  m_turn = t;
  save_info(m_turn_string[m_turn.color]);
}

void BoardInfo::wrong_format(const string &s) {
  save_info("{ " + s + " } " + Kwrong_format);
}

void BoardInfo::illegal_move(const string &s) {
  save_info("{ " + s + " } " + Killegal_move);
}

void BoardInfo::in_check(const string &s) {
  save_info("{ " + s + " } " + Kcheck_move);
}

void BoardInfo::save_move(const Move &mv) {
  m_moves[m_turn.turn] +=  get_move_string(mv) + " ";

  if (Move_Utils::get_captured_piece(mv))
    m_captures[m_turn.turn] += get_captured_string(mv) + " ";
}

string BoardInfo::get_move_string(const Move &m) {
  return
    string(1, utils::piecetype_to_char(Move_Utils::get_piece(m))) + "-" +
    string_utils::squareindex_to_str(Move_Utils::get_from(m)) + string_utils::squareindex_to_str(Move_Utils::get_to(m));
}

string BoardInfo::get_captured_string(const Move &m) {
  return string_utils::get_piece_str_name_from_piecetype(Move_Utils::get_captured_piece(m));
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
