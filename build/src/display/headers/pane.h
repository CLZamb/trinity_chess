#ifndef PANE_H
#define PANE_H
#include <vector>
#include <string>
#include <memory>
#include <unordered_map>
#include "../../board/headers/utils.h"
#include "ISectionComponent.h"

using std::string;
using std::vector;
using std::unordered_map;
using std::shared_ptr;

class Pane {
 public:
  Pane();
  explicit Pane(string content);
  virtual ~Pane();
  string* at(size_t);
  std::vector<string>::iterator begin();
  std::vector<string>::iterator end();
  void clear();
  void add_section(shared_ptr<ISectionComponent> section);
  void set_top(string);
  void set_bottom(std::initializer_list<string> lst);
  void set_bottom(string bottom);
  int size();
  string operator[] (int i) const;
  string& operator[] (int i);

 private:
  int get_next_index();
  int rows_left();

  static const size_t size_pane = 44;
  int bottom_index = size_pane;
  int top_index = 0;
  vector<string> pane {size_pane, ""};
  string default_content = "";
};

#endif /* PANE_H */
