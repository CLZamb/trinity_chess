#ifndef MESSAGES_HPP
#define MESSAGES_HPP

#pragma once

#include <iostream>
#include "game_drawings.hpp"
#include "utils/utilities.h"

using std::cout;
using std::endl;
using GameDrawing::white_won;
using GameDrawing::black_won;
using GameDrawing::game_over;

namespace GameMessages
{

inline void print_game_winner(Color c){
  static const std::string 
    winner_drawing = 
      c == Color::WHITE ? 
        white_won.data() : black_won.data();

  cout << winner_drawing << endl;
}

inline void print_game_over() {
  cout << game_over << endl;
}
}

#endif /* MESSAGES_HPP */
