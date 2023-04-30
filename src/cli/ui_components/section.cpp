#include "section.h"
#include <iostream>
#include <limits>

Section::Section(string name, size_t size)
    : ISectionComponent(size), m_name(name) {
  if (size >= std::numeric_limits<size_t>::max())
    std::cerr << "illegal size length: " << size << " on section " << name
              << std::endl;
}

Section::~Section() {}

void Section::fill(const string &content) {
  for (auto &i : m_section_drawing) {
    i = content;
  }
}

void Section::set_drawing_at_index(string content, const size_t &index) {
  if (!is_valid_index(index))
    return;

  m_section_drawing[index] = std::move(content);
}

bool Section::is_valid_index(const size_t &index) { return index < size(); }

void Section::set_drawing(std::initializer_list<string> lst) {
  if (lst.size() > size())
    return;

  unsigned long index = 0;
  for (auto i : lst) {
    m_section_drawing[index++] = i;
  }
}

void Section::set_drawing(const vector<string> *content) {
  if (content->size() > size())
    return;

  unsigned long index = 0;
  for (auto i : *content) {
    m_section_drawing[index++] = i;
  }
}

string Section::get_name() { return m_name; }
