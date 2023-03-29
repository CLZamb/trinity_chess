#ifndef OPTION_H
#define OPTION_H

#include <string>

using std::string;

template <typename T> struct Option {
  int num = 0;
  string desc = "";
  T opt { std::is_same<T, string>::value ?  desc : T()};
};

#endif /* OPTION_H */
