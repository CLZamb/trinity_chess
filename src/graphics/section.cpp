#include "headers/section.h"

Section::Section(string name, size_t size) :
 ISectionComponent(size), m_name(name) {
  if (size >= std::numeric_limits<size_t>::max())
    std::cerr
      << "illegal size length: " << size
      << " on section " << name << std::endl;
}

Section::~Section() {}

void Section::set_content_at_index(string content, const size_t& index) {
  if (!is_valid_index(index))
    return;

  m_section_drawing[index] = content;
}

bool Section::is_valid_index(const size_t& index) {
  if (index >= size()) return false;
  if (index < 0) return false;
  return true;
}

void Section::set_content(std::initializer_list<string> lst) {
  if (lst.size() > size())
    return;

  int index = 0;
  for (auto i : lst) {
    m_section_drawing[index++] = i;
  }
}

void Section::set_content(const vector<string>* content) {
  if (content->size() > size())
    return;

  int index = 0;
  for (auto i : *content) {
    m_section_drawing[index++] = i;
  }
}

string Section::get_name() {
  return m_name;
}
