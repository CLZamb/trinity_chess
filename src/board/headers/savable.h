#ifndef SAVABLE_H
#define SAVABLE_H

#pragma once
#include <array>
#include <string>
#include "../../headers/game_turn.h"

using std::string;
using std::array;

class Savable {
 public:
  virtual void save_moves(const string& moves) = 0;
  virtual void save_captures(const string& moves) = 0;
  virtual void save_game_info(const string& info) = 0;

 protected:
  static const int players_size = GameTurn::kSize;
  array<string, players_size> player_moves;
  array<string, players_size> player_captures;
  string game_info;
};

#endif /* SAVABLE_H */
