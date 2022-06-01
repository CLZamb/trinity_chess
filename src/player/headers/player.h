// File: player.h
#ifndef PLAYER_H
#define PLAYER_H
#pragma once

#include <iostream>
#include <regex>
#include <string>
#include "board/headers/utils.h"

using std::string;

class Player {
 public:
   explicit Player(Color);
   virtual ~Player();
   bool has_black_pieces();
   virtual const string &get_input();

 protected:
   string m_input = "quit";
 private:
   Color m_color = Color::NONE;
};

#endif /* PLAYER_H */
