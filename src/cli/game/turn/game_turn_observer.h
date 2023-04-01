#ifndef GAMETURN_OBSERVER_H
#define GAMETURN_OBSERVER_H

#pragma once

#include "game_turn.h"
#include "player_info.hpp"

class GameTurnObserver {
 public:
    virtual ~GameTurnObserver() {}
    virtual void update_turn(const PlayerInfo &) = 0;
 protected:
    GameTurnObserver() {}
};

#endif /* GAMETURNOBSERVER_H */
