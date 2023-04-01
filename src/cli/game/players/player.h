#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using std::string;

class Player {
public:
  virtual ~Player() {}
  virtual const string &get_player_string_move() = 0;
};

#endif /* PLAYER_H */
