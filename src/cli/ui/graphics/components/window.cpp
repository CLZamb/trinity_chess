#include "window.h"

Window::Window() {}
Window::~Window() {}

void Window::add_pane(Displayable *pane, Pane_pos pos) {
  if (m_panes.size() >= Max_panes_size)
    return;

  if (pane->size() > m_panes_size_max_height) {
    m_panes_size_max_height = pane->size();
  }

  m_panes.emplace(pos, pane);
}

ostream &operator<<(ostream &os, Window &w) {
  w.get_formatted_window_drawing(os);
  return os;
}

void Window::get_formatted_window_drawing(ostream &os) {
  if (m_panes.size() == 0) return; 

  for (auto &iter : m_panes)  
    iter.second->draw(); 

  for (size_t row = 0; row < m_panes_size_max_height; row++) {
    for (auto &pane : m_panes) {
      os << (*pane.second)[row];
    }
    os << "\n";
  }
}
