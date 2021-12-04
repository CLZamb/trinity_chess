#ifndef GAME_TURN_OBSERVABLE_H
#define GAME_TURN_OBSERVABLE_H

#pragma once

#include <list>
#include "game_turn_observer.h"
#include "game_turn.h"

using std::list;

class GameTurnObservable {
 public:
  virtual ~GameTurnObservable();

 protected:
  GameTurnObservable();
  virtual void attach(GameTurnObserver*);
  virtual void detach(GameTurnObserver*);
  virtual void notify() = 0;
  list<GameTurnObserver*> *_observers;
};

#endif /* GAME_TURN_OBSERVABLE_H */
