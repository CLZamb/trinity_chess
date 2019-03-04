// File: player.h
#ifndef PLAYER_H
#define PLAYER_H
#pragma once
#include "move.h"
#include <iostream>
#include <piece.h>
#include <regex>
#include <string>

using std::string;
using std::vector;

class Player {
private:
  int convert_to_int_pos(char file, char rank);
  void set_next_move(string input);
  vector<string> scan(string, const std::regex);

protected:
  Player* p_opponent = nullptr;
  Move m_move;
  bool is_valid_input;
  bool m_black_pieces;

public:
  Player();
  explicit Player(bool has_black_pieces);
  virtual ~Player();
  virtual Move get_next_move();
  void set_opponent(Player* opponent);
  bool has_black_pieces();
  bool is_valid_move();
  Player* get_opponent();
};

#endif /* PLAYER_H */
