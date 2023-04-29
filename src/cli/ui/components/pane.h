#ifndef PANE_H
#define PANE_H

#include <cstddef>
#include <unordered_map>
#include <memory>
#include "board/board_window/info_pane/info_drawings.hpp"
#include "ui/components/pane_drawings.hpp"
#include "section.h"
#include "IPane.h"
// #include "board/board_window/info_pane/info_drawings.hpp"

using std::shared_ptr;
using std::unordered_map;

class Pane : public IPane  {
 public:
  explicit Pane(size_t size);
  virtual ~Pane();
  void clear();
  void fill(const string& content);
  void add_section(const string & section_name, const size_t size);
  void set_content_at_section(const string &section_name, std::initializer_list<string> lst);
  void set_content_at_section(const string &section_name, const vector<string>* content);
  shared_ptr<Section>& get_section(const string& key);
  string format_line(const string &line);
  void set_content_to_block_recursively(shared_ptr<Section>& section,
                                        string &msg, size_t &current_row);
  void format_section(shared_ptr<Section>& block, string content);

 private:
  bool has_block_space_for_content(const shared_ptr<Section>& block, const string& message);
  void add_section(shared_ptr<ISectionComponent> section);
  size_t size() override;
  const string& operator[] (size_t i) override;

  void fill_pane();
  int get_next_index();
  bool is_valid_pane_index(const size_t& index);

  vector<string*> m_pane_drawing;
  unordered_map<string, shared_ptr<Section>> sections;
  string m_empty{};
  const size_t kRowMaxWidth = PaneDrawings::Borders::width - 4 /*┃  ┃*/;
};

#endif /* PANE_H */
