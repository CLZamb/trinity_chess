#ifndef INPUT_H
#define INPUT_H
#include <string>
#include "game/headers/game_turn_observer.h"

using std::string;

class Input : public GameTurnObserver {
 public:
  Input() {}
  virtual ~Input() {}
  virtual const string& get_string_input() = 0;
  virtual int get_integer_input() = 0;

 protected:
  string m_input = "quit";
};

#endif /* INPUT_H */
