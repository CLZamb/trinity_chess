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

  vector<string*>& get_section();
  void set_parent_pane(Pane* parent);
  int size();

 protected:
  vector<string*> section;

 private:
  Pane* parent_pane = nullptr;
};

#endif /* ISECTIONCOMPONENT_H */
