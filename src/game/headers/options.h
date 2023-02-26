#ifndef OPTIONS_H
#define OPTIONS_H

#include <cstddef>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <vector>
#include <iterator> // For std::forward_iterator_tag
#include <cstddef>  // For std::ptrdiff_t

using std::map;
using std::string;


template <typename T> struct Option {
  int num = 0;
  string desc = "";
  T opt;
};

template <typename T> 
class Options {
public:
  using iterator = typename map<int, Option<T>>::iterator;

  Options() {}
  Options(std::initializer_list<Option<T>> lst) {
    for (const auto &l : lst) {
      m_options.emplace(l.num, l);
    }
  }

  virtual ~Options() {}

  iterator begin() { return m_options.begin(); }
  iterator end() { return m_options.end(); }

  bool check_valid_option(int i) { 
    return m_options.find(i) != m_options.end(); 
  }

  const Option<T>& at(int key) { return m_options.at(key); }

 private:
  map<int, Option<T>> m_options;
};


#endif /* OPTIONS_H */
