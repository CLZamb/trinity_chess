#ifndef GAME_TURN_OBSERVABLE_H
#define GAME_TURN_OBSERVABLE_H

#include "components/event_emitter.h"
#pragma once

#include <list>
#include "game_turn_observer.h"

class GameTurnObservable : public EventEmitter {
 public:
  virtual ~GameTurnObservable();
  virtual void attach(GameTurnObserver*);
  virtual void detach(GameTurnObserver*);

 protected:
  GameTurnObservable();
  virtual void notify_side() = 0;
  std::list<GameTurnObserver*> *_observers;
  const std::string m_event_name_as_string = typeid(Color).name();
};

#endif /* GAME_TURN_OBSERVABLE_H */
