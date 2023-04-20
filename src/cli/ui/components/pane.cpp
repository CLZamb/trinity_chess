#include "pane.h"

using std::make_unique;

Pane::Pane(size_t size /*= 44 */) {
  m_pane_drawing.reserve(size);
}

Pane::~Pane() {}

void Pane::clear() { fill(""); }

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
}

void Pane::add_section(const string &name, const size_t row_size) {
  sections.emplace(name, make_unique<Section>(name, row_size));
  add_section(sections[name]);
}

shared_ptr<Section>& Pane::get_section(const string& key) {
  return sections[key];
}

const string& Pane::operator[](size_t index) {
  if (!is_valid_pane_index(index)) return m_empty;

  return *m_pane_drawing[index];
}

size_t Pane::size() {
  return this->m_pane_drawing.size();
}

bool Pane::is_valid_pane_index(const size_t& index) {
  if (index >= m_pane_drawing.size()) return false;
  return true;
}

void Pane::set_content_at_section(const string &key, std::initializer_list<string> lst) {
  sections[key]->set_drawing(lst);
}

void Pane::set_content_at_section(const string &key, const vector<string>* content) {
  sections[key]->set_drawing(content);
}