#ifndef OPTIONS_H
#define OPTIONS_H

#include "../../player/headers/player.h"
#include <cstddef>
#include <iostream>
#include <unordered_map>

using std::cin;
using std::cout;
using std::endl;
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

  T& select_option() {
    cout << "\t\tchoose one of the options (" 
      << start_index << " - "
      << options.size() << "): ";

    int input = -1;
    bool valid_option = false;

    while (!valid_option) {
      cin >> input;
      valid_option = check_valid_option(input);

      if (!valid_option) {
        cout << "invalid option try again!" << endl;
        cin.clear();
        cin.ignore();
      }
    }

    cin.clear();
    cin.ignore();
    return options.find(input)->second.opt;
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
