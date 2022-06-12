#ifndef INPUT_H
#define INPUT_H
#include <string>
#include "input_observer.h"

using std::string;

class InputObservable {
  public:
    virtual ~InputObservable() {}
    virtual void update_listener(InputObserver *observer) = 0;
    virtual void notify_input_event() = 0;

  protected:
    InputObserver* p_observer{nullptr};
};

class Input : public InputObservable {
  public:
    virtual void select_menu_option() = 0;
    virtual void get_player_string_move() = 0;
};



#endif /* INPUT_H */
