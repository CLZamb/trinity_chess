#include "headers/game_info.h"

GameInfo::GameInfo() {}

void GameInfo::update_turn(const PlayerInfo &i) {
  m_turn = i;
  update_info(m_turn_string[m_turn.get_turn()]);
};

void GameInfo::update_info(const string& info) { game_info = info; }
string GameInfo::get_info() { return game_info;}

void GameInfo::wrong_format(const string &s) {
  update_info("{ " + s + " }" + Kwrong_format);
}

void GameInfo::illegal_move(const string &s) {
  update_info("{ " + s + " }" + Killegal_move);
}

const string GameInfo::Kwrong_format = " Move is an not in a recognizable format, please try again";
const string GameInfo::Killegal_move = " Move is an ilegal move";
