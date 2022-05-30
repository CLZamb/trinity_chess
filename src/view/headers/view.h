#ifndef VIEW_H
#define VIEW_H

#include <string>
#include "graphics/headers/window.h"

using std::string;

class View : public Displayable {
  public:
    View(string name);
    void print();

    static string Get_name();
    void draw() override;

  protected:
    Window window_view;
  private:
    static string name;
};
 
#endif /* VIEW_H */
