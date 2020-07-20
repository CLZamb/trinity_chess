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
  explicit Pane(int size);
  virtual ~Pane();
  void clear();
  void fill(const string& content);
  void add_section(shared_ptr<ISectionComponent> section);
  void set_content(std::initializer_list<string> lst);
  int size();
  const string& operator[] (int i);

 private:
  void fill_pane();
  int get_next_index();
  bool is_valid_pane_index(const int& index);

  int m_size = 0;
  vector<string*> m_pane_drawing;
};

#endif /* PANE_H */
