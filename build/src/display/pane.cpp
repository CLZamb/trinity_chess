#include "headers/pane.h"

Pane::Pane(int size) {
  m_pane_drawing.reserve(size);
}

Pane::~Pane() {}

void Pane::clear() {
  fill("");
}

void Pane::fill(const string& content) {
  for (auto& i : m_pane_drawing) {
    *i = content;
  }
}

void Pane::add_section(shared_ptr<ISectionComponent> section) {
  if (section == nullptr) return;

  for (auto& i : *section) {
    m_pane_drawing.push_back(&i);
  }

  section->set_parent_pane(this);
}

const string& Pane::operator[](int index) {
  if (!is_valid_pane_index(index))
    throw std::out_of_range("index not found");

  return *m_pane_drawing[index];
}

int Pane::size() {
  return this->m_pane_drawing.size();
}

bool Pane::is_valid_pane_index(const int& index) {
  if (index >= m_pane_drawing.size()) return false;
  if (index < 0) return false;
  return true;
}
