#ifndef MOVE_UTILS_H
#define MOVE_UTILS_H

# pragma once

#include<iostream>
#include<string>
#include<vector>
#include<regex>
#include"move.h"

using std::string;
using std::vector;

namespace MoveUtils {
  Move str_convert_to_move(const string& str_mv);
  bool is_valid_str_move_format(const string& str_mv);
};  // namespace MoveUtils

#endif /* MOVE_UTILS_H */
