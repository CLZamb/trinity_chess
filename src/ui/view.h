#ifndef VIEW_H
#define VIEW_H

#include <string>
#include "ui/graphics/components/window.h"

using std::string;

class View : public Displayable {
  public:
    View(string name);
    virtual ~View() {}
    void print();

    static string get_name();
    void draw() override;

  private:
    static string name;

  protected:
    Window _window;
};
 
#endif /* VIEW_H */
