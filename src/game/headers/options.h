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
class Options {
 public:
  Options() {}
  Options(std::initializer_list<T> lst) {
    int index = start_index;
    for (const auto l : lst) {
      options.emplace(index++, l);
    }
  }

  virtual ~Options() {}

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
    return options.find(input)->second;
  }

 private:
  static const size_t start_index = 1;

  bool check_valid_option(int i) {
    return options.find(i) != options.end();
  }

  unordered_map<int, T> options;
};

#endif /* OPTIONS_H */
