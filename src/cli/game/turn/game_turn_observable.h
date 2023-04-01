#ifndef GAME_TURN_OBSERVABLE_H
#define GAME_TURN_OBSERVABLE_H

#pragma once

#include <list>
#include "game_turn_observer.h"

using std::list;

class GameTurnObservable {
 public:
  virtual ~GameTurnObservable();
  virtual void attach(GameTurnObserver*);
  virtual void detach(GameTurnObserver*);

 protected:
  GameTurnObservable();
  virtual void notify_change_turn() = 0;
  list<GameTurnObserver*> *_observers;
};

#endif /* GAME_TURN_OBSERVABLE_H */
