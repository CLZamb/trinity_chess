#ifndef GAMETURN_OBSERVER_H
#define GAMETURN_OBSERVER_H

#include "game/game_typedefs.h"
#pragma once

class GameTurnObserver {
 public:
    virtual ~GameTurnObserver() = default;
    virtual void update_turn(const Color &) = 0;
};

#endif /* GAMETURNOBSERVER_H */
