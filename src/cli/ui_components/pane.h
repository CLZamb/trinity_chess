#ifndef PANE_H
#define PANE_H

#include <cstddef>
#include <unordered_map>
#include <memory>
#include "pane_drawings.hpp"
#include "section.h"
#include "IPane.h"

class Pane : public IPane  {
 public:
  explicit Pane(size_t size);
  virtual ~Pane();
  void clear();
  void fill(const std::string& content);
  void add_section(const std::string & section_name, const size_t size);
  void set_content_at_section(const std::string &section_name, std::initializer_list<string> lst);
  void set_content_at_section(const std::string &section_name, const std::vector<string>* content);
  std::shared_ptr<Section>& get_section(const std::string& key);
  string format_line(const std::string &line);
  void set_content_to_block_recursively(std::shared_ptr<Section>& section,
                                        std::string &msg, size_t &current_row);
  void format_section(std::shared_ptr<Section>& block, std::string content);

 private:
  bool has_block_space_for_content(const std::shared_ptr<Section>& block, const std::string& message);
  void add_section(std::shared_ptr<ISectionComponent> section);
  size_t size() override;
  const std::string& operator[] (size_t i) override;

  void fill_pane();
  int get_next_index();
  bool is_valid_pane_index(const size_t& index);

  std::vector<std::string*> m_pane_drawing;
  std::unordered_map<std::string, std::shared_ptr<Section>> sections;
  std::string m_empty{};
  const size_t kRowMaxWidth = PaneDrawings::Borders::width - 4 /*┃  ┃*/;
};

#endif /* PANE_H */
