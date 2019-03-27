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

struct PlayerMove {
  string m_input = "exit";
  Move m_move;
  bool valid_input = false;
  void set_move(Move mv, string input) {
    m_input = input;
    m_move = mv;
  }
  void set_move(Move m) { m_move = m; }
  void set_ply_input(string s) { m_input = s; }

  Move get_move() { return m_move; }
};

class Player {
private:
  int convert_to_int_pos(char file, char rank);
  void set_next_move(string input);
  vector<string> scan(string, const std::regex);

protected:
  Player* p_opponent = nullptr;
  Move m_move;
  PlayerMove m_pl_move;
  bool is_valid_input;
  bool m_black_pieces;

public:
  Player();
  explicit Player(bool has_black_pieces);
  virtual ~Player();
  virtual PlayerMove get_next_move();
  void set_opponent(Player* opponent);
  bool has_black_pieces();
  bool is_valid_move();
  Player* get_opponent();
};

#endif /* PLAYER_H */
