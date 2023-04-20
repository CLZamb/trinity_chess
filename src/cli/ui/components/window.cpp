#include "window.h"
#include <ostream>
#include <iostream>

using std::cout;
using std::flush;

Window::Window() {}
Window::~Window() {}

void Window::add_left_pane(IPane* pane) {
  add_pane(pane, Window::Left_pane);
}

void Window::add_middle_pane(IPane* pane) {
  add_pane(pane, Window::Middle_pane);
}

void Window::add_right_pane(IPane* pane) {
  add_pane(pane, Window::Right_pane);
}

void Window::print() {
  // system(CLEAR);
  cout << *this << flush; 
}

void Window::add_pane(IPane *pane, Pane_pos pos) {
  if (pane == nullptr) return;

  if (m_panes.size() >= max_panes_size)
    return;

  if (pane->size() > m_panes_size_max_height) {
    m_panes_size_max_height = pane->size();
  }

  m_panes.emplace(pos, pane);
}

ostream &operator<<(ostream &os, Window &w) {
  w.get_window_drawing(os);
  return os;
}

void Window::get_window_drawing(ostream &os) {
  if (m_panes.size() == 0) {
    os << "Window.h: Error: no pane(s) added to window\n";
    return; 
  }

  for (size_t row = 0; row < m_panes_size_max_height; row++) {
    for (auto &pane : m_panes) {
      os << (*pane.second)[row];
    }
    os << "\n";
  }
}
