#ifndef SECTION_H
#define SECTION_H
#include <cstddef>
#include <iostream>
#include <limits>
#include "ISectionComponent.h"

using std::string;
using std::vector;

class Section : public ISectionComponent {
 public:
  explicit Section(string name, size_t size);
  virtual ~Section();
  string* at(int index);
  void set_content(string);
  void set_content(std::initializer_list<string>);
  void set_content(const vector<string>*);
  string get_name();

 private:
  string m_name;
};

#endif /* SECTION_H */
