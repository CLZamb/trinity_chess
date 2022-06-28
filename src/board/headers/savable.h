#ifndef SAVABLE_H
#define SAVABLE_H

#pragma once
#include <array>
#include <string>
#include "game/headers/game_turn.h"
#include "game/headers/move.hpp"

using std::string;
using std::array;

class Savable {
 public:
  virtual string get_moves() = 0;
  virtual string get_captures() = 0;
  virtual string get_info() = 0;

 protected:
  virtual void save_move(const Move &moves) = 0;
  virtual void save_info(const string &captures) = 0;

  static const size_t players_size = GameTurn::kSize;
  array<string, players_size> m_moves;
  array<string, players_size> m_captures;
  string m_info;
};

#endif /* SAVABLE_H */
