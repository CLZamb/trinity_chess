#ifndef SECTION_H
#define SECTION_H

#include "ISectionComponent.h"

class Section : public ISectionComponent {
 public:
  explicit Section(std::string name, size_t size);
  virtual ~Section() = default;
  const std::string* at(int index);
  void fill(const std::string & content);
  void set_drawing_at_index(std::string line_drawing, const size_t& index);
  void set_drawing(std::initializer_list<std::string> drawing);
  void set_drawing(const std::vector<std::string>* vct_drawing);
  std::string get_name();

 private:
  void check_valid_size(size_t& size);
  bool is_valid_index(const size_t& index);
  std::string m_name;
};

#endif /* SECTION_H */
