#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#pragma once

#include "game/game_typedefs.h"
#include "move.hpp"
#include "regex_utils.h"
#include <regex>
#include <string>
#include <unordered_map>
#include <vector>

namespace StringDrawingName {

namespace Pieces {
static const std::string bishop = "bishop"; 
static const std::string king   = "king"; 
static const std::string knight = "knight"; 
static const std::string pawn   = "pawn"; 
static const std::string queen  = "queen"; 
static const std::string rook   = "rook"; 

inline std::string get_name_from_piecetype(Piece piece_type) {
  const std::unordered_map<Piece, std::string> piece_str_name{
    {bP, pawn},   {bR, rook},   {bN, knight}, {bB, bishop},
    {bQ, queen},  {bK, king},   {wP, pawn},   {wR, rook},
    {wN, knight}, {wB, bishop}, {wQ, queen},  {wK, king}
  };

  auto search = piece_str_name.find(piece_type);

  if (search == piece_str_name.end()) {
    return "not piece";
}

  return search->second;
}

}  // namespace Pieces

namespace Square {
static const std::string square = "square";
} // Square

}  // namespace StringDrawingName

namespace StringUtils {
inline unsigned int square_str_to_int(std::string sq) {
  char file = sq[0], rank = sq[1];
  unsigned int square_int = static_cast<unsigned int>((file - 'a') + ((rank - '1') * 8));

  if (square_int < A1 || square_int > H8) {
    return 0;
  }
  return square_int;
}


static const std::regex format_full_move =
    std::regex("[a-hA-H][1-8]\\s*[a-hA-H][1-8]");
static const std::regex format_single_position =
    std::regex("([a-hA-H]\\s*[1-8])");

inline Move to_move(const std::string &str_move) {
  std::vector<std::string> list_pos;
  Move result{0};

  list_pos = RegexUtils::get_list_of_positions(str_move, format_single_position);

  if (list_pos.size() != 2) {
    return result;
  }

  unsigned int from = square_str_to_int(list_pos[0]);
  unsigned int to = square_str_to_int(list_pos[1]);

  MoveUtils::set_move(result, from, to);
  return result;
}

inline std::string square_to_str(Square sq) {
  if (sq < A1 || sq > H8) {
    return "-not a valid position-";
  }

  std::string square_str;
  unsigned int square = static_cast<unsigned int>(sq);
  square_str = 'a' + (square % 8);
  square_str += static_cast<char>('1' + (sq / 8));
  return square_str;
}

inline std::string move_to_string(Move& m) {
  std::string mv_str;
  Square from = MoveUtils::get_from(m);
  Square to = MoveUtils::get_to(m);

  return square_to_str(from) + " " + square_to_str(to);
}

namespace check {
inline bool is_valid_move_format(const std::string &str_mv) {
  return RegexUtils::match(str_mv, format_full_move);
}
}


inline std::string get_color_str_from_color(Color c) {
  return (c == WHITE) ? "white" : "black";
}


size_t constexpr length(const char* str) {
  return *str ? 1 + length(str + 1) : 0;
}

size_t constexpr utf8_strlen(const char* str) {
  const size_t len = length(str);
  size_t c = 0, i = 0, ix = 0, q = 0;
  for (q=0, i=0, ix=len; i < ix; i++, q++) {
    c = static_cast<unsigned char>(str[i]);
    if      (c > 0 && c <= 127) { i+=0;
    } else if ((c & 0xE0) == 0xC0) { i+=1;
    } else if ((c & 0xF0) == 0xE0) { i+=2;
    } else if ((c & 0xF8) == 0xF0) { i+=3;
    } else {
      return 0;  // invalid utf8
    }
  }
  return q;
}
}  // namespace StringUtils

#endif /* STRING_UTILS_H */
