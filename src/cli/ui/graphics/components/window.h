#ifndef WINDOW_H
#define WINDOW_H

#include "IPane.h"
#include <map>

using std::map;
using std::ostream;

class Window {
 public:

  Window();
  virtual ~Window();
  void add_left_pane(IPane* pane);
  void add_right_pane(IPane* pane);
  void add_middle_pane(IPane* pane);
  void print();

 private:
  enum Pane_pos {
    Left_pane      = 0,
    Middle_pane    = 1,
    Right_pane     = 2,
  };

  void add_pane(IPane *pane, Pane_pos pos);
  void get_formatted_window_drawing(ostream &os);
  friend ostream &operator<<(ostream &os, Window &);

  constexpr static const size_t max_panes_size = 3;
  size_t m_panes_size_max_height{0};
  map<int, IPane *> m_panes;
};

#endif /* WINDOW_H */
