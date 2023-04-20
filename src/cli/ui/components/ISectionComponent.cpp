#include "ISectionComponent.h"

ISectionComponent::ISectionComponent(size_t size) : m_size(size), m_section_drawing(size) {}
ISectionComponent::~ISectionComponent() {}

size_t ISectionComponent::size() {
  return m_size;
}

vector<string>::iterator ISectionComponent::begin() {
  return m_section_drawing.begin();
}

vector<string>::iterator ISectionComponent::end() {
  return m_section_drawing.end();
}
