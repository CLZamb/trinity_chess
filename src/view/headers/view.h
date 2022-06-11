#ifndef VIEW_H
#define VIEW_H

#include <string>
#include "graphics/headers/window.h"
#include "player/headers/input_observer.h"

using std::string;

class View : public Displayable {
  public:
    View(string name);
    void print();

    static string get_name();
    void draw() override;

  private:
    static string name;

  protected:
    Window window_view;
};
 
#endif /* VIEW_H */
