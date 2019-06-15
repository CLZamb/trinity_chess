#ifndef UTILS_H
#define UTILS_H
#include "defs.h"
#include <array>
#include <map>
#include <initializer_list>  // std::initializer_list
#include <vector>
#include <string>
#include <assert.h>

using std::map;
using std::vector;
using std::string;

namespace utils {
namespace check {
  inline bool is_square(SquareIndices s) {
    return s >= A1 && s <= H8;
  }

  inline bool is_black_piece(int type) {
    return type >= bP && type <= bK;
  }

  inline bool is_valid_piece(int pieceType) {
    return (pieceType > EMPTY) && (pieceType < 13);
  }
}  // namespace check

constexpr int piece_types_each_side = 6;
constexpr int size_piece_types = piece_types_each_side * 2 + 1;

inline std::array<int, utils::size_piece_types>
set_piece_values(const std::initializer_list<int>& scores) {
  assert(scores.size() == utils::piece_types_each_side);

  std::array<int, utils::size_piece_types> pieces_scores{0};
  // black pieces
  int piece = bP;
  for (const auto score : scores)
    pieces_scores[piece++] = score;

  // white pieces
  piece = wP;
  for (const auto score : scores)
    pieces_scores[piece++] = -score;

  return pieces_scores;
}

inline string square_int_to_str(int sq) {
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

namespace constant {
  const std::array<int, utils::size_piece_types> piece_material_score =
    utils::set_piece_values(
    {
      /* [PAWN]  */100,
      /* [ROOK]  */500,
      /* [KNIGHT]  */300,
      /* [BISHOP]  */300,
      /* [QUEEN]  */900,
      /* [KING]  */10000
    });

  const size_t squares = 64;
  const int ksquares = 64;
  const int kMaxDepth = 64;
}  // namespace constant
}  // namespace utils

#endif /*  */
