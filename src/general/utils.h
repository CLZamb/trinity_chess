#ifndef UTILS_H
#define UTILS_H
#include "defs.h"
#include <array>
#include <map>
#include <initializer_list>  // std::initializer_list
#include <vector>
#include <string>

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

constexpr std::array<int, utils::size_piece_types>
set_piece_values(const std::initializer_list<int>& values) {
  assert(values.size() == utils::piece_types_each_side);

  std::array<int, utils::size_piece_types> pieces_values{0};
  // black pieces
  int index = bP;
  for (const auto value : values)
    pieces_values[index++] = value;

  for (const auto value : values)
    pieces_values[index++] = -value;

  return pieces_values;
}

inline vector<string> square_str() {
  vector<string> square_str{65, "0"};
  int position = 0;
  char rank = 'A', file = '1';
  for (int row = 7; row >= 0; --row) {
    for (int col = 0; col < 8; ++col) {
      position = row * 8 + col;

      square_str[position] = rank + col;
      square_str[position] += file + row;
    }
  }
  return square_str;
}

namespace constant {
  const std::array<int, utils::size_piece_types> piece_score_value =
    utils::set_piece_values({
      // pawn, rook, knight, bishop, queen, king
      100, 500, 300, 300, 900, 10000});

  const vector<string> sq_int_pos_to_str = utils::square_str();
   // const std::array<char*, 65> square_int_pos_to_str =
}  // namespace constant
}  // namespace utils

#endif /*  */
