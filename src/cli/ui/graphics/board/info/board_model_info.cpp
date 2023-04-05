#include "board_model_info.h"
#include "utils/string_utils.h"

BoardModelInfo::BoardModelInfo() {}
BoardModelInfo::~BoardModelInfo() {}

void BoardModelInfo::update_turn(const PlayerInfo& t){
  m_turn = t;
  save_info(m_turn_string[m_turn.color]);
}

void BoardModelInfo::save_move(const Move &mv) {
  m_moves[m_turn.turn] +=  get_move_string(mv) + " ";

  if (Move_Utils::get_captured_piece(mv))
    m_captures[m_turn.turn] += get_captured_string(mv) + " ";
}

string BoardModelInfo::get_move_string(const Move &m) {
  return
    string(1, utils::piecetype_to_char(Move_Utils::get_piece(m))) + "-" +
    string_utils::squareindex_to_str(Move_Utils::get_from(m)) + string_utils::squareindex_to_str(Move_Utils::get_to(m));
}

string BoardModelInfo::get_captured_string(const Move &m) {
  return string_utils::get_piece_str_name_from_piecetype(Move_Utils::get_captured_piece(m));
}

void BoardModelInfo::save_info(const string &info) {
  m_info = info;
}

string BoardModelInfo::get_moves() {
  return m_moves[m_turn.turn];
}

string BoardModelInfo::get_captures() {
  return m_captures[m_turn.turn];
}

string BoardModelInfo::get_info() {
  return m_info;
}
