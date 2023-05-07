#ifndef ISECTIONCOMPONENT_H
#define ISECTIONCOMPONENT_H

#include <vector>
#include <string>

class ISectionComponent {
 public:
  explicit ISectionComponent(size_t size);
  virtual ~ISectionComponent();

  std::vector<std::string>::iterator begin();
  std::vector<std::string>::iterator end();
  size_t size();

 private:
  const size_t m_size;

 protected:
  std::vector<std::string> m_section_drawing;
};

#endif /* ISECTIONCOMPONENT_H */
