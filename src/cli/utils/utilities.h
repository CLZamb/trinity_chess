#ifndef UTILITIES_H
#define UTILITIES_H

#include <map>
#include <string>
#include <iostream>
#include <limits>
#include "defs.h"

using std::map;
using std::string;

enum Piecetype : unsigned int {
  EMPTY, bP, bR, bN, bB, bQ, bK, wP, wR, wN, wB, wQ, wK
};

enum Color {
  WHITE = 0, BLACK = 1, NONE = 3, SIZE = 2, BOTH = 2,
};

namespace utils {
namespace check {
  inline bool is_black_piece(Piecetype type) {
    return type >= bP && type <= bK;
  }

  inline Color get_color_piece(Piecetype type) {
    if (type >= bP && type <= bK) return BLACK;
    if (type >= wP && type <= wK) return WHITE;
    return NONE;
  }

  inline bool is_valid_piece(unsigned int pieceType) {
    return (pieceType > EMPTY) && (pieceType < 13);
  }

    inline bool is_square(SquareIndices s) {
      return s >= A1 && s <= H8;
  }
}  // namespace check

inline Piecetype get_piecetype_from_char_key(const char c) {
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

#endif /* UTILITIES_H  */
