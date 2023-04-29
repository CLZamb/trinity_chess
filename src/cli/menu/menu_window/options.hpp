#ifndef OPTIONS_H
#define OPTIONS_H

#include <iostream>
#include <map>
#include "option.h"

template <typename T = std::string> 
class Options {
public:
  using iterator = typename std::map<int, Option<T>>::iterator;

  Options() {}
  Options(std::initializer_list<Option<T>> lst) {
    for (const auto &l : lst) {
      m_options.emplace(l.num, l);
    }
  }

  void add_option(int key, Option<T> option) {
    m_options.emplace(key, option);
  }

  virtual ~Options() {}

  iterator begin() { return m_options.begin(); }
  iterator end() { return m_options.end(); }

  bool check_valid_option(int i) { 
    return m_options.find(i) != m_options.end(); 
  }
  const Option<T>& at(int key) { return m_options.at(key); }

 private:
  std::map<int, Option<T>> m_options;
};


#endif /* OPTIONS_H */
