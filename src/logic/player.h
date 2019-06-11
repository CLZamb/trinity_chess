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

class PlayerMove {
 public:
  void set_move(Move m) { m_move = m; }
  void set_move(Move mv, string input) {
    m_input = input;
    m_move = mv;
  }
  void set_ply_input(string s) { m_input = s; }
  void set_valid(bool is_valid) { valid_input = is_valid; }
  string get_input() { return m_input; }
  bool is_valid() { return valid_input; }
  Move get_move() { return m_move; }

 private:
  string m_input = "exit";
  bool valid_input = false;
  Move m_move;
};

class Player {
 public:
  Player();
  explicit Player(bool has_black_pieces);
  virtual ~Player();
  virtual PlayerMove get_next_move();
  void set_opponent(Player* opponent);
  bool has_black_pieces();
  bool is_valid_move();
  Player* get_opponent();
  void save_played_moves(string mv);
  void save_captured_pieces(string cap);
  string get_played_moves();
  string get_captured_pieces();

 protected:
  string played_moves;
  string captured_pieces;
  Player* p_opponent = nullptr;
  Move m_move;
  PlayerMove m_pl_move;
  bool is_valid_input;
  bool m_black_pieces;

 private:
  void set_next_move(string input);
  vector<string> scan(string, const std::regex);
};

#endif /* PLAYER_H */
