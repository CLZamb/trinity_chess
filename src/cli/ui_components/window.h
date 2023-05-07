#ifndef WINDOW_H
#define WINDOW_H

#include <map>

#include "IPane.h"

// Assume Unix system
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

class Window {
 public:
  Window();
  virtual ~Window();
  void print();

  enum PanePos {
    LEFT_PANE = 0,
    MIDDLE_PANE = 1,
    RIGHT_PANE = 2,
  };

 protected:
  void add_left_pane(IPane *pane);
  void add_right_pane(IPane *pane);
  void add_middle_pane(IPane *pane);
  void add_pane(IPane *pane, PanePos pos);

 private:
  void get_window_drawing(std::ostream &os);
  friend std::ostream &operator<<(std::ostream &os, Window &);

  constexpr static int max_panes_size = 3;
  size_t m_panes_size_max_height{0};
  std::map<int, IPane *> m_panes;
};

#endif /* WINDOW_H */
