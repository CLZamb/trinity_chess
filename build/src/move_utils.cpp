#include "headers/move_utils.h"

namespace MoveUtils {
namespace {
  vector<string> scan(string str, const std::regex reg) {
    vector<string> results;
    std::smatch matches;
    while (std::regex_search(str, matches, reg)) {
      results.push_back(matches.str(1));
      str = matches.suffix().str();
    }
    return results;
  }

  // format of move letters(a to h) and digit from (1 to 8) follow by
  // zero or more space and follow by the same patter of letter and digit
  // ie. a1 a2
  std::regex regex_format_full_move =
    std::regex("[a-hA-H][1-8]\\s*[a-hA-H][1-8]");
  // format of a single move position
  // letters from a-h and digit from 1 to 8
  // ie. a1
  std::regex regex_format_single_move_position
    = std::regex("([a-hA-H]\\s*[1-8])");

  std::smatch move_matches;
  std::vector<string> list_pos;
};  // end anon namespace

  Move str_convert_to_move(const string& str_move) {
    Move result;
    list_pos.clear();

    try {
      list_pos = scan(str_move, regex_format_single_move_position);
    } catch (std::regex_error &e) {
      if (e.code() == std::regex_constants::error_badrepeat)
        std::cerr << "Repeat was not preceded by a valid regular expression.\n";
      else
        std::cerr << "Regex exection .\n";
    }

    if (list_pos.size() != 2) {
      return result;
    }

    int from = utils::square_str_to_int(list_pos[0]);
    int to = utils::square_str_to_int(list_pos[1]);
    result.set_move(from, to);
    return result;
  }


  bool is_valid_str_move_format(const string& str_move) {
    return std::regex_match(str_move, regex_format_full_move);
  }
};  // namespace MoveUtils
