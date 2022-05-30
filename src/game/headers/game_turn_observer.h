#ifndef GAMETURNOBSERVER_H
#define GAMETURNOBSERVER_H

#pragma once

#include "game_turn.h"
#include "model/headers/player_info.h"

class GameTurnObserver {
 public:
    virtual ~GameTurnObserver() {}
    virtual void update_turn(const PlayerInfo &) = 0;
 protected:
    // GameTurnObserver() {}
};

#endif /* GAMETURNOBSERVER_H */
