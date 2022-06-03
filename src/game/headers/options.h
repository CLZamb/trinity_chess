#ifndef OPTIONS_H
#define OPTIONS_H

#include "player/headers/input.h"
#include "player/headers/player.h"
#include <cstddef>
#include <iostream>
#include <unordered_map>

using std::cin;
using std::cout;
using std::unordered_map;

template <typename T>
struct Option {
  int num;
  string desc;
  T opt;
};

template <typename T>
class Options {
 public:
  Options() {}
  Options(std::initializer_list<Option<T>> lst) {
    for (const auto l : lst) {
      options.emplace(l.num, l);
    }
  }

  virtual ~Options() {}

  void add_options(T item) {
    options.emplace(options.size() - 1, item);
  }

  Option<T>& select_option(Input& input) {
    int key = -1;
    bool valid_option = false;

    cout << "\t\t\t\tchoose one of the options (" 
      << start_index << " - "
      << options.size() << "): ";

    while (!valid_option) {
      key = input.get_integer_input();
      valid_option = check_valid_option(key);

      if (!valid_option) {
        cout << "invalid option try again!" << "\n";
        cin.clear();
        cin.ignore();
      }
    }

    cin.clear();
    cin.ignore();
    return options.find(key)->second;
  }

  unordered_map<int, Option<T>> get_options() {
    return options;
  }

 private:
  static const size_t start_index = 1;

  bool check_valid_option(int i) {
    return options.find(i) != options.end();
  }

  unordered_map<int, Option<T>> options;
};

#endif /* OPTIONS_H */
