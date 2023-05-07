#include "pane.h"

using std::make_unique;

Pane::Pane(size_t size /*= 44 */) {
  m_pane_drawing.reserve(size);
}

Pane::~Pane() {}

void Pane::clear() { fill(""); }

void Pane::fill(const string& content) {
  for (auto& i : m_pane_drawing) {
    *i = content;
  }
}

void Pane::add_section(std::shared_ptr<ISectionComponent> section) {
  if (section == nullptr) return;

  for (auto& i : *section) {
    m_pane_drawing.push_back(&i);
  }
}

void Pane::add_section(const string &name, const size_t row_size) {
  sections.emplace(name, make_unique<Section>(name, row_size));
  add_section(sections[name]);
}

std::shared_ptr<Section>& Pane::get_section(const string& key) {
  return sections[key];
}

const string& Pane::operator[](size_t index) {
  if (!is_valid_pane_index(index)) return m_empty;

  return *m_pane_drawing[index];
}

size_t Pane::size() {
  return this->m_pane_drawing.size();
}

bool Pane::is_valid_pane_index(const size_t& index) {
  if (index >= m_pane_drawing.size()) return false;
  return true;
}

void Pane::set_content_at_section(const string &key, std::initializer_list<string> lst) {
  sections[key]->set_drawing(lst);
}

void Pane::set_content_at_section(const string &key, const std::vector<string>* content) {
  sections[key]->set_drawing(content);
}

bool Pane::has_block_space_for_content(
  const std::shared_ptr<Section>& block, const string& message) {
  return message.size() < kRowMaxWidth * (block->size() - 1);
}

string Pane::format_line(const string &line) {
  size_t num_spaces = kRowMaxWidth - line.size();
  return  " ┃ " + line + std::string(num_spaces, ' ') + "┃";
}

void Pane::set_content_to_block_recursively(std::shared_ptr<Section>& section,
                                      string &msg, size_t &current_row) {
  if (current_row > section->size()) return;

  if (msg.size() < kRowMaxWidth) {
    section->set_drawing_at_index(format_line(msg), current_row);
    section->set_drawing_at_index(
      PaneDrawings::Borders::krow_divider, section->size() - 1
    );
    return;
  }

  section->set_drawing_at_index(
    format_line(msg.substr(0, kRowMaxWidth)), current_row
  );

  msg = msg.substr(kRowMaxWidth/* to_end */);
  set_content_to_block_recursively(section, msg, ++current_row);
}

void Pane::format_section(std::shared_ptr<Section>& block, string content) {
  if (block == nullptr) return;

  if (!has_block_space_for_content(block, content)) return;

  string msg = block->get_name() + ": " + content; 
  size_t start_index = 0;
  set_content_to_block_recursively(block, msg, start_index);
}
