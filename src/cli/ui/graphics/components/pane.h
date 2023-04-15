#ifndef PANE_H
#define PANE_H

#include <unordered_map>
#include <memory>
#include "section.h"
#include "IPane.h"

using std::shared_ptr;
using std::unordered_map;

class Pane : public IPane {
 public:
  explicit Pane(size_t size = 44);
  virtual ~Pane();
  void clear();
  void fill(const string& content);
  void add_section(const string & section_name, const size_t size);
  void set_content_at_section(const string &section_name, std::initializer_list<string> lst);
  void set_content_at_section(const string &section_name, const vector<string>* content);
  shared_ptr<Section>& get_section(const string& key);

 private:
  void add_section(shared_ptr<ISectionComponent> section);
  size_t size() override;
  const string& operator[] (size_t i) override;

  void fill_pane();
  int get_next_index();
  bool is_valid_pane_index(const size_t& index);

  vector<string*> m_pane_drawing;
  unordered_map<string, shared_ptr<Section>> sections;
  string m_empty{};
};

#endif /* PANE_H */