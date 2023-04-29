#ifndef OPTION_H
#define OPTION_H

#include <string>

template <typename T> struct Option {
  int num = 0;
  std::string desc = "";
  T opt { std::is_same<T, std::string>::value ?  desc : T() };
};

#endif /* OPTION_H */
