#ifndef BOARD_TYPEDEFS_H
#define BOARD_TYPEDEFS_H

#include <array>

#define ENABLE_INCR_OPERATORS_ON(T)                                \
inline T& operator++(T& d) { return d = T(int(d) + 1); }           \
inline T& operator--(T& d) { return d = T(int(d) - 1); }
// GLOBALS

enum Square : unsigned int {
  A1, B1, C1, D1, E1, F1, G1, H1,
  A2, B2, C2, D2, E2, F2, G2, H2,
  A3, B3, C3, D3, E3, F3, G3, H3,
  A4, B4, C4, D4, E4, F4, G4, H4,
  A5, B5, C5, D5, E5, F5, G5, H5,
  A6, B6, C6, D6, E6, F6, G6, H6,
  A7, B7, C7, D7, E7, F7, G7, H7,
  A8, B8, C8, D8, E8, F8, G8, H8,

  SquareBegin = A1, 
  SquareEnd = H8 + 1,
  SquareNull = SquareEnd + 1,
};

ENABLE_INCR_OPERATORS_ON(Square)

enum Piece : unsigned int {
  NO_PIECE, wP, wR, wN, wB, wQ, wK, bP, bR, bN, bB, bQ, bK,
};

using BoardSquares = std::array<Piece, SquareEnd>;

enum PieceType {
  NO_PIECE_TYPE, PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING,
  PIECE_TYPE_SIZE = KING + 1
};

ENABLE_INCR_OPERATORS_ON(PieceType)

enum CastleSquares : int {
  NO_CASTLE_POS = SquareNull,

  WK_CA_INITIAL_POS = E1,
  BK_CA_INITIAL_POS = E8,

  WK_CA_KING_SIDE_END_POS = G1,  // WKCA
  WK_CA_QUEEN_SIDE_END_POS = C1, // WQCA

  BK_CA_KING_SIDE_END_POS = G8,  // BKCA
  BK_CA_QUEEN_SIDE_END_POS = C8, // BQCA

  ROOK_WHITE_CA_KING_SIDE_FROM_POS = H1, // WKCA
  ROOK_WHITE_CA_KING_SIDE_TO_POS = F1, // WKCA

  ROOK_WHITE_CA_QUEEN_SIDE_FROM_POS = A1, // WQCA
  ROOK_WHITE_CA_QUEEN_SIDE_TO_POS = D1, // WQCA

  ROOK_BLACK_CA_KING_SIDE_FROM_POS = H8, // BKCA
  ROOK_BLACK_CA_KING_SIDE_TO_POS = F8, // BkCA
 
  ROOK_BLACK_CA_QUEEN_SIDE_FROM_POS = A8, // BQCA
  ROOK_BLACK_CA_QUEEN_SIDE_TO_POS = D8, // BQCA
};

enum CastlePermission {
  NO_CASTLING = 0,
  WKCA = 1,
  WQCA = 2,
  BKCA = 4,
  BQCA = 8,
};

#endif /* BOARD_TYPEDEFS_H */
