#include "ISectionComponent.h"

ISectionComponent::ISectionComponent(size_t size) : m_size(size), m_section_drawing(size) {}
ISectionComponent::~ISectionComponent() {}

size_t ISectionComponent::size() {
  return m_size;
}

std::vector<std::string>::iterator ISectionComponent::begin() {
  return m_section_drawing.begin();
}

std::vector<std::string>::iterator ISectionComponent::end() {
  return m_section_drawing.end();
}
