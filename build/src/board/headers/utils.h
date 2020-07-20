#ifndef UTILS_H
#define UTILS_H
#include <map>
#include <string>
#include <iostream>

using std::map;
using std::string;

enum SquareIndices : int  {
  A1, B1, C1, D1, E1, F1, G1, H1,
  A2, B2, C2, D2, E2, F2, G2, H2,
  A3, B3, C3, D3, E3, F3, G3, H3,
  A4, B4, C4, D4, E4, F4, G4, H4,
  A5, B5, C5, D5, E5, F5, G5, H5,
  A6, B6, C6, D6, E6, F6, G6, H6,
  A7, B7, C7, D7, E7, F7, G7, H7,
  A8, B8, C8, D8, E8, F8, G8, H8,
  Squarebegin = A1, SquareEnd = H8 + 1
};

enum Piecetype : int {
  EMPTY, bP, bR, bN, bB, bQ, bK, wP, wR, wN, wB, wQ, wK
};

namespace utils {
namespace check {
  inline bool is_black_piece(int type) {
    return type >= bP && type <= bK;
  }

  inline bool is_valid_piece(int pieceType) {
    return (pieceType > EMPTY) && (pieceType < 13);
  }

    inline bool is_square(SquareIndices s) {
      return s >= A1 && s <= H8;
  }
}  // namespace check

inline string get_piece_str_name_from_piecetype(Piecetype piece_type) {
  static const map<Piecetype, string> piece_str_name  {
    {bP, "pawn"}, {bR, "rook"}, {bN, "knight"},
      {bB, "bishop"}, {bQ, "queen"}, {bK, "king"},
      {wP, "pawn"}, {wR, "rook"}, {wN, "knight"},
      {wB, "bishop"}, {wQ, "queen"}, {wK, "king"}
  };

  auto search = piece_str_name.find(piece_type);
  // check if the key exists
  if (search == piece_str_name.end()) return "";

  return search->second;
}

inline int get_square_index_from_char_key(const char c) {
  static const map<char, int> piece_map = {
    {'P', wP}, {'R', wR}, {'N', wN}, {'B', wB}, {'Q', wQ}, {'K', wK},
    {'p', bP}, {'r', bR}, {'n', bN}, {'b', bB}, {'q', bQ}, {'k', bK},
  };

  auto search = piece_map.find(c);
  // check if the key exists
  if (search == piece_map.end()) return 0;

  return search->second;
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

namespace constants {
  enum Players {
    player_1 = 0,
    player_2 = 1,
    players_size = 2,
  };
}

}  // namespace utils

#endif /*  */
