#include "headers/board_info.h"

BoardInfo::BoardInfo() {}

void BoardInfo::update_turn(const PlayerInfo& t){
  m_turn = t;
  save_info(m_turn_string[m_turn.get_color()]);
}

void BoardInfo::wrong_format(const string &s) {
  save_info("{ " + s + " }" + Kwrong_format);
}

void BoardInfo::illegal_move(const string &s) {
  save_info("{ " + s + " }" + Killegal_move);
}

void BoardInfo::save_move(const string &move) {
  m_moves[m_turn.get_turn()] += move + " ";
}

void BoardInfo::save_capture(const string &move) {
  m_captures[m_turn.get_turn()] += move + " ";
}

void BoardInfo::save_info(const string &info) {
  m_info = info;
}

string BoardInfo::get_moves() {
  return m_moves[m_turn.get_turn()];
}

string BoardInfo::get_captures() {
  return m_captures[m_turn.get_turn()];
}

string BoardInfo::get_info() {
  return m_info;
}

const string BoardInfo::Kwrong_format = 
  " Move is an not in a recognizable format, please try again";
const string BoardInfo::Killegal_move = 
  " Move is an ilegal move";
