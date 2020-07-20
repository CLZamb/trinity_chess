// File: player.h
#ifndef PLAYER_H
#define PLAYER_H
#pragma once

#include <iostream>
#include <regex>
#include <string>

using std::string;
using std::vector;

class Player {
 public:
  enum Color : int{
     black = 0,
     white = 1,
  };

  enum Type {
     Cpu = 0,
     Human = 1,
  };

    explicit Player(Color);
    virtual ~Player();
    void set_opponent(std::shared_ptr<Player> opponent);
    bool has_black_pieces();
    bool is_valid_move();
    std::shared_ptr<Player> get_opponent();
    void get_input(string&);
    string get_str_color_pieces();
    Color get_int_color_pieces();

 protected:
    std::shared_ptr<Player> p_opponent = nullptr;
    Color color = Color::black;
    string color_str[2] = {"black", "white"};
    bool is_valid_input = false;
    bool m_black_pieces = false;
    int ply = 1;
};

#endif /* PLAYER_H */
