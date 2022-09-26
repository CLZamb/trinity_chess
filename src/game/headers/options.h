#ifndef OPTIONS_H
#define OPTIONS_H

#include <cstddef>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <vector>

using std::map;
using std::string;

template <typename T> struct Option {
  int num = 0;
  string desc = "";
  T opt;
};

template <typename T> 
class Options : public map<int, Option<T>> {
public:
  Options() {}
  Options(std::initializer_list<Option<T>> lst) {
    for (const auto &l : lst) {
      this->emplace(l.num, l);
    }
  }

  virtual ~Options() {}

  bool check_valid_option(int i) { 
    return this->find(i) != this->end(); 
  }
 private:
};

#endif /* OPTIONS_H */
