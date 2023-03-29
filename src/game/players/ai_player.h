#ifndef AI_PLAYER_H
#define AI_PLAYER_H

#include <string>
#include "player.h"

using std::string;

class AIPlayer : public Player {
  public:
    AIPlayer ();
    virtual ~AIPlayer ();
    const string &get_player_string_move() override; 
  private:
    const string empty_str = "";
};

#endif /* AI_PLAYER_H */
