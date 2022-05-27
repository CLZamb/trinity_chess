#ifndef GAMETURNOBSERVER_H
#define GAMETURNOBSERVER_H

#pragma once

#include "game_turn.h"

class GameTurnObserver {
 public:
    virtual ~GameTurnObserver() {}
    virtual void update_turn(GameTurn::players turn) = 0;
 protected:
    // GameTurnObserver() {}
};

#endif /* GAMETURNOBSERVER_H */
