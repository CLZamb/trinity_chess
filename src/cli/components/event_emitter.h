#ifndef EVENT_EMITTER_H
#define EVENT_EMITTER_H

#include <cassert>
#include <functional>
#include <iostream>
#include <unordered_map>
#include <typeindex>

class EventEmitter {
 public:
  template <typename EventType, typename Class>
  using method_callback = void (Class::*)(EventType &);
  using method = std::function<void(void *)>;

  virtual ~EventEmitter() = default;

  template <typename EventType, typename Class>
  void bind(method_callback<EventType, Class> m, Class *c) {
    m_events_handlers[typeid(EventType)].push_back(get_method(m, c));
  }

  template <typename EventType>
  void send_event(EventType &m) {
    if (!has_event_handlers(m)) {
      return;
    }

    for (auto &&event_handler : m_events_handlers.at(typeid(EventType))) {
      event_handler(&m);
    }
  }

  template <typename EventType>
  bool has_event_handlers(EventType &) {
    const std::type_index event_type = typeid(EventType);
    if (m_events_handlers.find(event_type) == m_events_handlers.end()) {
      std::cout << "Event not found: " << event_type.name() << std::endl;
      return false;
    }

    return true;
  }

 private:
  template <typename EventType, typename Class>
  method get_method(method_callback<EventType, Class> m, Class *c) {
    return [c, m](void *evt) { (c->*m)(*reinterpret_cast<EventType *>(evt)); };
  }

  std::unordered_map<std::type_index, std::vector<method>> m_events_handlers;
};

#endif /* EVENT_EMITTER_H */
