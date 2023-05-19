#include "section.h"

#include <iostream>
#include <limits>

using std::vector;
using std::string;

Section::Section(string name, size_t size)
    : ISectionComponent(size)
    , m_name(name) {
  check_valid_size(size);
}

void Section::check_valid_size(size_t& size) {
  if (size >= std::numeric_limits<size_t>::max()) {
    std::cerr 
      << "illegal size length: " << size 
      << " on section " << m_name << std::endl;
  }
}

void Section::fill(const string &content) {
  for (auto &i : m_section_drawing) {
    i = content;
  }
}

void Section::set_drawing_at_index(string content, const size_t &index) {
  if (!is_valid_index(index)) {
    return;
  }

  m_section_drawing[index] = std::move(content);
}

bool Section::is_valid_index(const size_t &index) { return index < size(); }

void Section::set_drawing(std::initializer_list<string> lst) {
  if (lst.size() > size()) {
    return;
  }

  size_t index = 0;
  for (auto i : lst) {
    m_section_drawing[index++] = i;
  }
}

void Section::set_drawing(const vector<string> *content) {
  if (content->size() > size()) {
    return;
  }

  size_t index = 0;
  for (auto c : *content) {
    m_section_drawing[index++] = c;
  }
}

string Section::get_name() { return m_name; }
