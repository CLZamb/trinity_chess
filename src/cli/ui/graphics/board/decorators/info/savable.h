#ifndef SAVABLE_H
#define SAVABLE_H

#include "game/players/player_info.hpp"
#include "utils/utilities.h"
#pragma once

#include <array>
#include <string>
#include "utils/move.hpp"

using std::string;
using std::array;

class Savable {
 public:
  virtual string get_moves(Color c) = 0;
  virtual string get_captures(Color c) = 0;
  virtual string get_info() = 0;
  virtual PlayerInfo get_player_info() = 0;

 protected:
  virtual void save_player_info(const PlayerInfo& c) = 0;
  virtual void save_move(const Move &moves) = 0;
  virtual void save_info(const string &captures) = 0;

  static const size_t players_size = Color::SIZE;
  array<string, players_size> m_moves;
  array<string, players_size> m_captures;
  string m_info;
};

#endif /* SAVABLE_H */
