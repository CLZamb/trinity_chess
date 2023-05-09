#ifndef FILE_CONFIGURATION_H
#define FILE_CONFIGURATION_H
#include <string>
#pragma once

#include <fstream>
#include <nlohmann/json.hpp>

#include "board_info.h"

NLOHMANN_JSON_SERIALIZE_ENUM(InputType, {
    {InputType::Keyboard, "keyboard"},
    {InputType::Text, "text"},
})

NLOHMANN_JSON_SERIALIZE_ENUM(Color, {
    {Color::BLACK, "black"},
    {Color::WHITE, "white"},
})

NLOHMANN_JSON_SERIALIZE_ENUM(SidePaneType, {
    {SidePaneType::None, "none"},
    {SidePaneType::Info, "info"},
    {SidePaneType::Statitics, "statistics"},
})

namespace FileInput {

using json = nlohmann::json;

// inline void to_json(json &j, const BoardConfigInfo &p) {
//   j = json{
//       {       "fen",     p.start_fen},
//       {       "input",   p.input_type},
//       {"initial_side", p.initial_side},
//       {   "left_pane",    p.left_pane},
//       {  "right_pane",   p.right_pane}
//   };
// }

inline void from_json_file(const std::string &file_name, BoardConfigInfo &p) {
  std::ifstream file(file_name);

  // Read the file contents into a string
  std::string str((std::istreambuf_iterator<char>(file)),
                  std::istreambuf_iterator<char>());

  json j = json::parse(str);

  std::string start_fen;
  j.at("fen").get_to(start_fen);
  j.at("input").get_to(p.input_type);
  j.at("initial_side").get_to(p.initial_side);
  j.at("left_pane").get_to(p.left_pane.type);
  j.at("right_pane").get_to(p.right_pane.type);

  p.fen_fields.split_fen_into_its_fields(start_fen);
}
}   // namespace FileInput
//

#endif /* FILE_CONFIGURATION_H  */
