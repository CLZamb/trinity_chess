#include "headers/window.h"

Window::Window() {}
Window::~Window() {}

void Window::add_pane(Displayable *pane, Pane_pos pos) {
  if (m_panes.size() >= Max_panes_size)
    return;

  if (pane->size() > panes_size_max_height) {
    panes_size_max_height = pane->size();
  }

  m_panes.emplace(pos, pane);
}

ostream &operator<<(ostream &os, Window &gc) {
  system(CLEAR);

  if (gc.m_panes.size() == 0) return os; 

  for (auto &iter : gc.m_panes)  
    iter.second->draw(); 

  os << gc.get_formatted_window_drawing();

  return os;
}

string Window::get_formatted_window_drawing() {
  string window_drawing{""}, m_window[panes_size_max_height];

  for (auto &pane : m_panes) {
    for (size_t row = 0; row < pane.second->size(); row++) {
      m_window[row] += (*pane.second)[row];
    }
  }
  
  for (auto& w_row: m_window) {
    window_drawing += move(w_row) + "\n";
  }

  return window_drawing;
}
