#ifndef SECTION_H
#define SECTION_H
#include <cstddef>
#include <iostream>
#include <limits>
#include <vector>
#include <string>
#include "ISectionComponent.h"

using std::string;
using std::vector;

class Section : public ISectionComponent {
 public:
  explicit Section(string name, size_t size);
  virtual ~Section();
  const string* at(int index);
  void fill(const string &);
  void set_content_at_index(string, const size_t&);
  void set_content(std::initializer_list<string>);
  void set_content(const vector<string>*);
  string get_name();

 private:
  bool is_valid_index(const size_t& index);
  string m_name;
};

#endif /* SECTION_H */
