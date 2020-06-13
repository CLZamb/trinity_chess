#include "headers/ISectionComponent.h"

ISectionComponent::ISectionComponent(size_t  size) {
  section.resize(size, nullptr);
}

ISectionComponent::~ISectionComponent() {}

void ISectionComponent::set_parent_pane(Pane* parent_pane) {
  if (this->parent_pane)return;
  if (!parent_pane) return;

  this->parent_pane = parent_pane;
}

vector<string*>& ISectionComponent::get_section() {
  return section;
}

int ISectionComponent::size() {
  return section.size();
}
