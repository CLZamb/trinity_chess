#ifndef MESSAGES_HPP
#define MESSAGES_HPP

#include "game/game_typedefs.h"
#pragma once

#include <iostream>
#include "messages_drawings.hpp"

namespace GameMessages
{

inline void print_game_winner(Color c){
  static const std::string 
    winner_drawing = 
      c == Color::WHITE ? 
        GameDrawing::white_won.data() : GameDrawing::black_won.data();

  std::cout << winner_drawing << std::endl;
}

inline void print_game_over() {
  std::cout << GameDrawing::game_over << std::endl;
}
}  // namespace GameMessages

#endif /* MESSAGES_HPP */
