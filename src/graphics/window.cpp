#include "headers/window.h"

Window::Window() {}
Window::~Window() {}

void Window::add_pane(Displayable *pane, Pane_pos pos) {
  if (m_panes.size() >= Max_panes_size)
    return;

  if (pane->size() > m_pane_max_heigh_size)
    m_pane_max_heigh_size = pane->size();

  m_panes.emplace(pos, pane);
}

ostream &operator<<(ostream &os, Window &gc) {
  system(CLEAR);

  if (gc.m_panes.size() == 0) {
    return os;
  }

  for (auto &iter : gc.m_panes) {
    iter.second->draw();
  }

  gc.insert_formatted_output(gc.m_panes, os);

  return os;
}

void Window::insert_formatted_output(map<int, Displayable *> &panes, ostream &os) {
  for (size_t row = 0; row < m_pane_max_heigh_size; ++row) {
    for (auto &pane : panes) {
      if (row >= pane.second->size()) continue;

      os << (*pane.second)[row];
    }
    os << "\n";
  }
}
