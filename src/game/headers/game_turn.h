#ifndef GAME_TURN_H
#define GAME_TURN_H

#pragma once

class GameTurn {
 public:
  enum players : int {
    player_1 = 0,
    player_2 = 1
  };

  virtual ~GameTurn();
  static const int kSize = 2;
};

#endif /* GAME_TURN_H */
