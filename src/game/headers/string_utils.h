#ifndef MOVE_UTILS_H
#define MOVE_UTILS_H

#pragma once

#include "game/headers/move.hpp"
#include "regex.h"
#include <regex>
#include <string>
#include <vector>

using std::string;
using std::unordered_map;

namespace string_utils {
inline int square_str_to_int(string sq) {
  char file = sq[0], rank = sq[1];
  int square_int = (file - 'a') + ((rank - '1') * 8);

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

  list_pos = Regex::get_list_of_positions(str_move, format_single_position);

  if (list_pos.size() != 2) {
    return result;
  }

  int from = square_str_to_int(list_pos[0]);
  int to = square_str_to_int(list_pos[1]);

  Move_Utils::set_move(result, from, to);
  return result;
}

inline bool is_valid_move_format(const string &str_mv) {
  return Regex::match(str_mv, format_full_move);
}

inline string squareindex_to_str(SquareIndices sq) {
  if (sq < A1 || sq > H8)
    return "-not a valid position-";

  string square_str;
  square_str = 'a' + (sq % 8);
  square_str += '1' + (sq / 8);
  return square_str;
}

inline string get_piece_str_name_from_piecetype(Piecetype piece_type) {
  static const map<Piecetype, string> piece_str_name{
      {bP, DrawingPieces::pawn_str_name},
      {bR, DrawingPieces::rook_str_name},
      {bN, DrawingPieces::knight_str_name},
      {bB, DrawingPieces::bishop_str_name},
      {bQ, DrawingPieces::queen_str_name},
      {bK, DrawingPieces::king_str_name},
      {wP, DrawingPieces::pawn_str_name},
      {wR, DrawingPieces::rook_str_name},
      {wN, DrawingPieces::knight_str_name},
      {wB, DrawingPieces::bishop_str_name},
      {wQ, DrawingPieces::queen_str_name},
      {wK, DrawingPieces::king_str_name}};

  auto search = piece_str_name.find(piece_type);
  // check if the key exists
  if (search == piece_str_name.end())
    return "";

  return search->second;
}

inline string get_color_str_from_color(Color c) {
  return (c == WHITE) ? "white" : "black";
}

inline string get_permission_str_from_castle_permission(const int &permissions) {
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
