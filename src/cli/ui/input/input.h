#ifndef INPUT_H
#define INPUT_H

#include <functional>
#include <string>
#include <unordered_map>

class Input {
 public:
  template <typename EventType, typename Class>
  using method_callback = void (Class::*)(EventType &);

  using method = std::function<void(void *)>;

  virtual ~Input() = default;
  virtual void listen_for_input_events() = 0;

  template <typename EventType, typename Class>
  void bind(method_callback<EventType, Class> m, Class *c) {
    _events[typeid(EventType).name()].push_back(get_method(m, c));
  }

 protected:
  std::unordered_map<std::string, std::vector<method>> _events;

 private:
  template <typename EventType, typename Class>
  method get_method(method_callback<EventType, Class> m, Class *c) {
    return [c, m](void *evt) { (c->*m)(*reinterpret_cast<EventType *>(evt)); };
  }
};

#endif /* INPUT_H */
