#ifndef MESSAGES_HPP
#define MESSAGES_HPP
#pragma once

#include <iostream>
#include "game_turn.h"
#include "game_drawings.hpp"

using std::cout;
using std::endl;
using GameDrawing::player_1_won;
using GameDrawing::player_2_won;

namespace GameMessages
{

inline void print_game_winner(GameTurn::Players winner){
  static const string 
    winner_drawing = winner == GameTurn::player_1 ? 
      player_1_won.data() : player_2_won.data();

  cout << winner_drawing << endl;
}

inline void print_game_over() {
  std::cout << GameDrawing::game_over << std::endl;
}

}

#endif /* MESSAGES_HPP */
