#ifndef SECTION_H
#define SECTION_H

#include "ISectionComponent.h"

class Section : public ISectionComponent {
 public:
  explicit Section(std::string name, size_t size);
  virtual ~Section();
  const std::string* at(int index);
  void fill(const std::string &);
  void set_drawing_at_index(std::string, const size_t&);
  void set_drawing(std::initializer_list<std::string>);
  void set_drawing(const std::vector<std::string>*);
  std::string get_name();

 private:
  bool is_valid_index(const size_t& index);
  std::string m_name;
};

#endif /* SECTION_H */
