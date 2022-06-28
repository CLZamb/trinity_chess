#ifndef WINDOW_H
#define WINDOW_H

#include "Idisplay.h"
#include "common/headers/common.h"
#include "pane.h"
#include "section.h"
#include <map>

using std::map;
using std::ostream;

class Window {
 public:
  enum Pane_pos {
    Left_pane = 0,
    Middle_pane = 1,
    Right_pane = 2,
    Max_panes_size = 3
  };

  Window();
  virtual ~Window();

  void add_pane(Displayable *pane, Pane_pos pos);
  friend ostream &operator<<(ostream &os, Window &);

 private:
  size_t m_panes_size_max_height{0};
  void get_formatted_window_drawing(ostream &os);
  map<int, Displayable *> m_panes;
};

#endif /* WINDOW_H */
