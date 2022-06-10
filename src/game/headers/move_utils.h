#ifndef MOVE_UTILS_H
#define MOVE_UTILS_H

# pragma once

#include<string>
#include<vector>
#include<regex>
#include"move.h"
#include"regex.h"

using std::string;

namespace string_utils{
  static const std::regex format_full_move = std::regex("[a-hA-H][1-8]\\s*[a-hA-H][1-8]");
  static const std::regex format_single_position = std::regex("([a-hA-H]\\s*[1-8])");

  inline Move to_move(const string& str_move){
    std::vector<string> list_pos;
    Move result;

    list_pos = Regex::get_list_of_positions(str_move, format_single_position);

    if (list_pos.size() != 2) {
      return result;
    }

    int from = utils::square_str_to_int(list_pos[0]);
    int to = utils::square_str_to_int(list_pos[1]);

    result.set_move(from, to);
    return result;
  }

  inline bool is_valid_move_format(const string& str_mv) {
    return Regex::match(str_mv, format_full_move);
  }

}

#endif /* MOVE_UTILS_H */
