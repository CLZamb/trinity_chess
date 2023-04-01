#ifndef ISECTIONCOMPONENT_H
#define ISECTIONCOMPONENT_H

#include <vector>
#include <string>

using std::string;
using std::vector;

class Pane;
class ISectionComponent {
 public:
  explicit ISectionComponent(size_t size);
  virtual ~ISectionComponent();

  vector<string>::iterator begin();
  vector<string>::iterator end();
  void set_parent_pane(Pane* parent);
  size_t size();

 private:
  const size_t m_size;
  Pane* parent_pane = nullptr;

 protected:
  vector<string> m_section_drawing;
};

#endif /* ISECTIONCOMPONENT_H */
