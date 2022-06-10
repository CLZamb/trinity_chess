#ifndef OPTIONS_H
#define OPTIONS_H

#include "player/headers/input.h"
#include <cstddef>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

template <typename T>
struct Option {
  int num = 0;
  string desc = "";
  T opt;
};

template <typename T>
class Options {
 public:
  Options() {}
  Options(std::initializer_list<Option<T>> lst) {
    for (const auto l : lst) {
      options.emplace(l.num, l);
      keys.push_back(l.num);
    }
  }

  virtual ~Options() {}

  void add_options(T item) {
    options.emplace(options.size() - 1, item);
  }

  Option<T>& get_option(const int &key) {
    auto it = options.find(key);
    return it == options.end() ? empty : it->second;
  }

  const unordered_map<int, Option<T>> &get_options() {
    return options;
  }

  bool check_valid_option(int i) {
    return options.find(i) != options.end();
  }

  size_t size() {
    return options.size();
  }

  const vector<int>& get_keys() {
    return keys;
  }

 private:
  static const size_t start_index = 1;
  Option<T> empty;
  unordered_map<int, Option<T>> options;
  vector<int> keys;
};

#endif /* OPTIONS_H */
