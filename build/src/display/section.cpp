#include "headers/section.h"

Section::Section(string name, size_t size) :
  ISectionComponent(size), m_name(name) {
  if (size >= std::numeric_limits<size_t>::max())
    std::cerr
      <<  "illegal size length: " << size
      << " on section " << name << std::endl;
}

Section::~Section() {
  section.clear();
}

string* Section::at(int index) {
  if (index > section.size())
    throw std::out_of_range("index not found");

  if (section[index] == nullptr)
    throw std::out_of_range("element at index does not exist");

  return section[index];
}

void Section::set_content(string content) {
  if (section.size() == 0) {
    std::cerr << "error size is 0" << std::endl;
    return;
  }

  if (section[0] == nullptr) return;

  *section[0] = content;
}


void Section::set_content(std::initializer_list<string> lst) {
  if (lst.size() > size())
    return;

  if (section[0] == nullptr) return;

  int index = 0;
  for (auto& i : lst) {
    *section[index++] = i;
  }
}

void Section::set_content(const vector<string>* content) {
  if (content->size() > size())
    return;

  if (section[0] == nullptr) return;

  int index = 0;
  for (auto i : *content) {
    *section[index++] = i;
  }
}

string Section::get_name() {
  return m_name;
}
