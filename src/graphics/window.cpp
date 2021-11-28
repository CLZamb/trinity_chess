#include "headers/window.h"

Window::Window() {}
Window::~Window() {}

// defatult size 44
void Window::add_pane(Displayable* pane, Pane_pos pos) {
  if (panes.size() >= Max_panes_size)
    return;

  panes.emplace(pos, pane);
}

ostream& operator << (ostream& os, Window &gc) {
  system(CLEAR);

  if (gc.panes.size() == 0) { return os; }

  for (auto& iter : gc.panes) {
    iter.second->draw();
  }

  gc.insert_formatted_output(gc.panes, os, 0);

  return os;
}

void Window::insert_formatted_output(
    map<int, Displayable*, std::less<int>> panes, ostream& os, int index) {

  if (panes.empty())
    return;

  map<int, Displayable*>::iterator smallest =
    std::min_element(panes.begin(), panes.end(),
        [](const auto& a, const auto& b) {
        return a.second->size() < b.second->size(); });

  for (; index < smallest->second->size(); ++index) {
    for (auto& iter : panes) {
      os << (*iter.second)[index];
    }
    os << "\n";
  }

  panes.erase(smallest);

  insert_formatted_output(panes, os, index);
}

