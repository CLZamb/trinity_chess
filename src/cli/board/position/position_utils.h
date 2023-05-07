#ifndef BOARD_UTILS_H
#define BOARD_UTILS_H

#include "position_typedefs.h"
#include "game/game_typedefs.h"
#include <unordered_map>
#include <limits>

namespace utils {
namespace check {
  inline bool is_black_piece(Piece type) {
    return type >= bP && type <= bK;
  }

  inline Color get_color_piece(Piece type) {
    if (type >= bP && type <= bK) return BLACK;
    if (type >= wP && type <= wK) return WHITE;
    return NONE;
  }

  inline bool is_king_piece(const Piece& pct) {
    return (pct == wK) || (pct == bK);
  }

  inline bool is_pawn_piece(const Piece& pct) {
    return (pct == bP) || (pct == wP);
  }


  inline bool is_valid_piece(unsigned int pieceType) {
    return (pieceType > EMPTY) && (pieceType < 13);
  }

  inline bool is_square(Square s) {
      return s >= A1 && s <= H8;
  }
}  // namespace check

inline Piece get_piecetype_from_char(const char c) {
  static const std::unordered_map<char, Piece> piece_map = {
    {'P', wP}, {'R', wR}, {'N', wN}, {'B', wB}, {'Q', wQ}, {'K', wK},
    {'p', bP}, {'r', bR}, {'n', bN}, {'b', bB}, {'q', bQ}, {'k', bK},
  };

  auto search = piece_map.find(c);
  // check if the key exists
  if (search == piece_map.end()) return EMPTY;

  return search->second;
}

inline char piecetype_to_char(Piece pct) {
  const char NotADigit{'*'};

  const std::unordered_map<Piece, char> encodings = {
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

  using std::size_t;
  const size_t ktotal_number_squares = 64;
  const int ksquares = 64;
  const int kMaxDepth = 64;
  const int kInfinite = std::numeric_limits<int>::max();
  const size_t ktotal_number_pieces = 13;
}  // namespace constant
}  // namespace utils
#endif /* BOARD_UTILS_H */
