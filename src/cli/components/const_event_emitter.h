#ifndef CONST_EVENT_EMITTER_H
#define CONST_EVENT_EMITTER_H

#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
#include <typeindex>

class ConstEventEmitter {
 public:
  template <typename EventType, typename Class>
  using const_method_callback = void (Class::*)(const EventType &);
  using const_method = std::function<void(const void *)>;

  virtual ~ConstEventEmitter() = default;

  template <typename EventType, typename Class>
  void bind(const_method_callback<const EventType, Class> m, Class *c) {
    m_const_event_handlers[typeid(EventType)].push_back(get_const_method(m, c));
  }

  template <typename EventType>
  void send_event(const EventType &m) {
    if (!has_event_handlers(m)) {
      return;
    }

    for (auto &&event : m_const_event_handlers.at(typeid(EventType))) {
      event(&m);
    }
  }

  template <typename EventType>
  bool has_event_handlers(const EventType &) {
    const std::type_index event_type = typeid(EventType);
    if (m_const_event_handlers.find(event_type) == m_const_event_handlers.end()) {
      std::cout << "Event not found: " << event_type.name() << std::endl;
      return false;
    }

    return true;
  }

 private:
  template <typename EventType, typename Class>
  const_method get_const_method(const_method_callback<EventType, Class> m,
                                Class *c) {
    return [c, m](const void *evt) {
      (c->*m)(*reinterpret_cast<const EventType *>(evt));
    };
  }

  std::unordered_map<std::type_index, std::vector<const_method>> m_const_event_handlers;
};

#endif /* CONST_EVENT_EMITTER_H */
