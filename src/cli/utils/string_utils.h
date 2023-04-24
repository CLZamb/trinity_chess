#ifndef MOVE_UTILS_H
#define MOVE_UTILS_H

#pragma once

#include "game/game_typedefs.h"
#include "move.hpp"
#include "regex_utils.h"
#include <regex>
#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;

namespace StringDrawingName {

namespace Pieces {
static const string bishop = "bishop"; 
static const string king   = "king"; 
static const string knight = "knight"; 
static const string pawn   = "pawn"; 
static const string queen  = "queen"; 
static const string rook   = "rook"; 

inline string get_piece_from_piecetype(Piece piece_type) {

  const unordered_map<Piece, string> piece_str_name{
    {bP, pawn},   {bR, rook},   {bN, knight}, {bB, bishop},
    {bQ, queen},  {bK, king},   {wP, pawn},   {wR, rook},
    {wN, knight}, {wB, bishop}, {wQ, queen},  {wK, king}
  };

  auto search = piece_str_name.find(piece_type);

  if (search == piece_str_name.end())
    return "not piece";

  return search->second;
}

} // Pieces

namespace Square {
static const string white_square = "WhiteSquare";
static const string black_square = "BlackSquare";
} // Square

} // StringDrawingName

namespace string_utils {
inline unsigned int square_str_to_int(string sq) {
  char file = sq[0], rank = sq[1];
  unsigned int square_int = static_cast<unsigned int>((file - 'a') + ((rank - '1') * 8));

  if (square_int < A1 || square_int > H8)
    return 0;
  return square_int;
}

static const std::regex format_full_move =
    std::regex("[a-hA-H][1-8]\\s*[a-hA-H][1-8]");
static const std::regex format_single_position =
    std::regex("([a-hA-H]\\s*[1-8])");

inline Move to_move(const string &str_move) {
  std::vector<string> list_pos;
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

namespace check {
inline bool is_valid_move_format(const string &str_mv) {
  return RegexUtils::match(str_mv, format_full_move);
}
}

inline string squareindex_to_str(Square sq) {
  if (sq < A1 || sq > H8)
    return "-not a valid position-";

  string square_str;
  unsigned int square = static_cast<unsigned int>(sq);
  square_str = 'a' + (square % 8);
  square_str += static_cast<char>('1' + (sq / 8));
  return square_str;
}

inline string get_color_str_from_color(Color c) {
  return (c == WHITE) ? "white" : "black";
}

inline string get_permission_str_from_castle_permission(const unsigned int &permissions) {
  if (permissions == NO_CASTLING) return "-";

  string permissions_str;

  static const unordered_map<CastlePermission, char> m_castle_permision {
      {WQCA, 'Q'}, {WKCA, 'K'}, {BQCA, 'q'}, {BKCA, 'k'},
  };

  for (CastlePermission c : {WQCA, WKCA, BQCA, BKCA, NO_CASTLING}) {
    if (permissions & c) {
      permissions_str += m_castle_permision.at(c);
    }
  }

  return permissions_str;
}
} // namespace string_utils

#endif /* MOVE_UTILS_H */
