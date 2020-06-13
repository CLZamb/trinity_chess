#include "headers/pane.h"
// #include "headers/

Pane::Pane() {}

Pane::Pane(string content) : default_content(content) {
  std::fill(pane.begin(), pane.end(), content);
}

Pane::~Pane() {}

string* Pane::at(size_t index) {
  if (index > pane.size())
    throw std::out_of_range("index not found");

  return &pane[index];
}

void Pane::clear() {
  std::fill(pane.begin(), pane.end(), default_content);
}

void Pane::add_section(shared_ptr<ISectionComponent> section) {
  if (section == nullptr) return;
  if (section->size() > rows_left())
    return;

  section->set_parent_pane(this);

  for (auto& i : section->get_section()) {
    i = &pane[top_index++];
  }
}

void Pane::set_top(string top_drawing) {
  pane[0] = top_drawing;

  top_index++;
}

void Pane::set_bottom(string bottom_drawing) {
  if (pane.size() <= 0)
    return;

  pane[pane.size() - 1] = bottom_drawing;

  bottom_index -= 1;
}

void Pane::set_bottom(std::initializer_list<string> lst) {
  if (pane.size() <= 0)
    return;

  int index = pane.size() - lst.size();

  for (auto i : lst) {
    pane[index++] = i;
  }

  bottom_index -= lst.size();
}

string Pane::operator[](int index) const {
  if (index > pane.size() || index < 0)
    throw std::out_of_range("index not found");

  return pane[index];
}

string& Pane::operator[](int index) {
  if (index > pane.size() || index < 0)
    throw std::out_of_range("index not found");

  return pane[index];
}

int Pane::size() {
  return this->size_pane;
}

int Pane::rows_left()  {
  return bottom_index - top_index;
}
