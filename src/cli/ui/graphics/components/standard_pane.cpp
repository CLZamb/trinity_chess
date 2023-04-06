#include "standard_pane.h"

using std::make_unique;

StandardPane::StandardPane(size_t size /*= 44 */) {
  m_pane_drawing.reserve(size);
}

StandardPane::~StandardPane() {}

void StandardPane::clear() { fill(""); }

void StandardPane::fill(const string& content) {
  for (auto& i : m_pane_drawing) {
    *i = content;
  }
}

void StandardPane::add_section(shared_ptr<ISectionComponent> section) {
  if (section == nullptr) return;

  for (auto& i : *section) {
    m_pane_drawing.push_back(&i);
  }
}

void StandardPane::add_section(const string &name, const size_t row_size) {
  sections.emplace(name, make_unique<Section>(name, row_size));
  add_section(sections[name]);
}

shared_ptr<Section>& StandardPane::get_section(const string& key) {
  return sections[key];
}

const string& StandardPane::operator[](size_t index) {
  if (!is_valid_pane_index(index)) return m_empty;

  return *m_pane_drawing[index];
}

size_t StandardPane::size() {
  return this->m_pane_drawing.size();
}

bool StandardPane::is_valid_pane_index(const size_t& index) {
  if (index >= m_pane_drawing.size()) return false;
  return true;
}

void StandardPane::set_content_at_section(const string &key, std::initializer_list<string> lst) {
  sections[key]->set_drawing(lst);
}

void StandardPane::set_content_at_section(const string &key, const vector<string>* content) {
  sections[key]->set_drawing(content);
}
