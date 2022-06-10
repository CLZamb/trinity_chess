#ifndef VIEW_H
#define VIEW_H

#include <string>
#include "graphics/headers/window.h"
#include "player/headers/input_observer.h"

using std::string;

class View : public Displayable , public InputObserver {
  public:
    View(string name);
    void print();

    static string get_name();
    void draw() override;
    void handle_input_event(const InputEvent&) override {}

  private:
    static string name;

  protected:
    Window window_view;
};
 
#endif /* VIEW_H */
