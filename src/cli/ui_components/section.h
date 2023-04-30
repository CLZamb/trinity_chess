#ifndef SECTION_H
#define SECTION_H

#include "ISectionComponent.h"

class Section : public ISectionComponent {
 public:
  explicit Section(string name, size_t size);
  virtual ~Section();
  const string* at(int index);
  void fill(const string &);
  void set_drawing_at_index(string, const size_t&);
  void set_drawing(std::initializer_list<string>);
  void set_drawing(const vector<string>*);
  string get_name();

 private:
  bool is_valid_index(const size_t& index);
  string m_name;
};

#endif /* SECTION_H */
