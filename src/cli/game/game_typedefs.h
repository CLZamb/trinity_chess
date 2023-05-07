#ifndef GAME_TYPEDEFS_H
#define GAME_TYPEDEFS_H

#include <string>
#include "input/input_types.h"

enum Color {
   WHITE = 0, BLACK = 1, SIZE = 2, NONE = 3,
};

enum PlayerType {
  Cpu = 0,
  Human = 1,
  Total_players_size = 2,
};


#endif /* GAME_TYPEDEFS_H */
