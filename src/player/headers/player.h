// File: player.h
#ifndef PLAYER_H
#define PLAYER_H
#pragma once

#include <iostream>
#include <regex>
#include <string>
#include "../../board/headers/utils.h"

using std::string;

class Player {
 public:
   explicit Player(Color);
   virtual ~Player();
   void set_opponent(std::shared_ptr<Player> opponent);
   bool has_black_pieces();
   std::shared_ptr<Player> get_opponent();

 private:
   std::shared_ptr<Player> p_opponent = nullptr;
   Color color = Color::NONE;
   string color_str = "None";
   bool is_valid_input = false;
   bool m_black_pieces = false;
   int ply = 1;
};

#endif /* PLAYER_H */
