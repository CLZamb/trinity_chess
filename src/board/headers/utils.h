#ifndef UTILS_H
#define UTILS_H

#include <map>
#include <string>
#include <iostream>
#include <limits>
#include "defs.h"
#include "graphics/headers/game_drawings.hpp"

using std::map;
using std::string;

enum Piecetype : unsigned int {
  EMPTY, bP, bR, bN, bB, bQ, bK, wP, wR, wN, wB, wQ, wK
};

enum Color {
  WHITE = 0, BLACK = 1, NONE = 2, SIZE = 2,
};

namespace utils {
namespace check {
  inline bool is_black_piece(Piecetype type) {
    return type >= bP && type <= bK;
  }

  inline bool is_valid_piece(unsigned int pieceType) {
    return (pieceType > EMPTY) && (pieceType < 13);
  }

    inline bool is_square(SquareIndices s) {
      return s >= A1 && s <= H8;
  }
}  // namespace check

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
    {wK, DrawingPieces::king_str_name}
  };

  auto search = piece_str_name.find(piece_type);
  // check if the key exists
  if (search == piece_str_name.end()) return "";

  return search->second;
}

inline string get_color_str_from_color(Color c) {
  return (c == WHITE) ? "white" : "black";
}

inline Piecetype get_square_index_from_char_key(const char c) {
  static const map<char, Piecetype> piece_map = {
    {'P', wP}, {'R', wR}, {'N', wN}, {'B', wB}, {'Q', wQ}, {'K', wK},
    {'p', bP}, {'r', bR}, {'n', bN}, {'b', bB}, {'q', bQ}, {'k', bK},
  };

  auto search = piece_map.find(c);
  // check if the key exists
  if (search == piece_map.end()) return EMPTY;

  return search->second;
}

inline char piecetype_to_char(Piecetype pct) {
  constexpr char NotADigit{'*'};

  static const map<Piecetype, char> encodings = {
      {wP, 'P'}, {wR, 'R'}, {wN, 'N'}, {wB, 'B'}, {wQ, 'Q'}, {wK, 'K'},
      {bP, 'p'}, {bR, 'r'}, {bN, 'n'}, {bB, 'b'}, {bQ, 'q'}, {bK, 'k'},
  };

  auto it = encodings.find(pct);
  return it == encodings.end() ? NotADigit : it->second;
}

inline string square_int_to_str(SquareIndices sq) {
  if (sq < A1 || sq > H8)
    return "-not a valid position-";

  string square_str;
  square_str = 'a' + (sq % 8);
  square_str += '1' + (sq / 8);
  return square_str;
}

inline int square_str_to_int(string sq) {
  char file = sq[0], rank = sq[1];
  int square_int = (file - 'a') + ((rank - '1') * 8);

  if (square_int < A1 || square_int > H8) return 0;
  return square_int;
}

constexpr int piece_types_each_side = 6;
constexpr int size_piece_types = piece_types_each_side * 2 + 1;

namespace constant {
  // const std::array<int, size_piece_types> piece_material_score =
  //   utils::set_piece_values(
  //   {
  //     /* [PAWN]  */100,
  //     /* [ROOK]  */500,
  //     /* [KNIGHT]  */300,
  //     /* [BISHOP]  */300,
  //     /* [QUEEN]  */900,
  //     /* [KING]  */10000
  //   });

  const size_t ktotal_number_squares = 64;
  const int ksquares = 64;
  const int kMaxDepth = 64;
  const int kInfinite = std::numeric_limits<int>::max();
  const size_t ktotal_number_pieces = 13;
}  // namespace constant
}  // namespace utils

#endif /*  */
