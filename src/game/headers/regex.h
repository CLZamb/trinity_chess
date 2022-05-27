#ifndef  REGEX_H
#define REGEX_H

#include<iostream>
#include<regex>
#include<vector>

using std::vector;
using std::string;

class Regex {
 public:
   static bool match(string str_move, std::regex match) {
     return std::regex_match(str_move, match);
   }

   static std::vector<string> get_list_of_positions(const std::string& str_move, std::regex match) {
    std::vector<string> list_pos;
    try {
      list_pos = scan(str_move, match);
    } catch (std::regex_error &e) {
      if (e.code() == std::regex_constants::error_badrepeat)
        std::cerr << "Repeat was not preceded by a valid regular expression.\n";
      else
        std::cerr << "Regex exection .\n";
    }
    return list_pos;
  }
 private:
   std::smatch move_matches;
   static vector<string> scan(string str, const std::regex reg) {
    vector<string> results;
    std::smatch matches;
    while (std::regex_search(str, matches, reg)) {
      results.push_back(matches.str(1));
      str = matches.suffix().str();
    }
    return results;
  }
};

#endif
