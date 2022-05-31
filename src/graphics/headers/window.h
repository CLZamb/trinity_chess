#ifndef WINDOW_H
#define WINDOW_H

#include <map>
#include "pane.h"
#include "section.h"
#include "Idisplay.h"
#include "common/headers/common.h"

using std::ostream;
using std::map;

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

    void add_pane(Displayable* pane, Pane_pos pos);
    friend ostream& operator << (ostream &os,  Window &);

 private:
  void insert_formatted_output(map<int, Displayable *> &panes,
                               ostream &os);

  size_t m_pane_max_heigh_size{0};
  map<int, Displayable*> m_panes;
  map<int, Displayable*>::iterator pane_begin_iter;
};

#endif /* WINDOW_H */
