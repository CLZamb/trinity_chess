#ifndef INPUT_H
#define INPUT_H
#include <string>
#include "game/headers/game_turn_observer.h"
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

class Input : public GameTurnObserver , public InputObservable {
  public:
    virtual void select_menu_option() = 0;
    virtual const string& get_player_string_move() = 0;
  protected:
    string m_input = "quit";
};



#endif /* INPUT_H */
