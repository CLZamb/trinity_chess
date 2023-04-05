#ifndef VIEW_H
#define VIEW_H

#include <string>
#include "window.h"
#include "standard_pane.h"

using std::string;

class View {
  public:
    View(string name);
    virtual ~View() {}
    void print();

    static string get_name();

  private:
    static string name;

  protected:
    Window _window;
    StandardPane _pane;
};
 
#endif /* VIEW_H */
