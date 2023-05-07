#ifndef MOVE_H
#define MOVE_H

#include "board/position/position_typedefs.h"
#include "utils/bit_utilities.h"

/*
  0000 0000 0000 0000 0000 0000 0011 1111 -> From                     >> 0, 0x3F
  0000 0000 0000 0000 0000 1111 1100 0000 -> To                       >> 6, 0x3F
  0000 0000 0000 0000 1111 0000 0000 0000 -> Piece                    >> 12, 0xF
  0000 0000 0000 1111 0000 0000 0000 0000 -> Captured                 >> 16, 0xF
  0000 0000 1111 0000 0000 0000 0000 0000 -> Promoted Piece           >> 20, 0xF
  0000 0001 0000 0000 0000 0000 0000 0000 -> EnPessant                >> 24, 0x1
  0001 1110 0000 0000 0000 0000 0000 0000 -> Castle permission        >> 25, 0xF
 */

typedef unsigned int Move;

namespace MoveUtils {

inline static const Move INVALID_MOVE = 0;

inline static const unsigned int designated_space_in_hex_square = 0x3F;
inline static const unsigned int designated_space_in_hex_piecetype = 0xF;
inline static const unsigned int designated_space_in_hex_flag = 0x1;
inline static const unsigned int designated_space_in_hex_caslte = 0xF;

inline static const int shift_from = 0;
inline static const int shift_to = 6;
inline static const int shift_piece = 12;
inline static const int shift_captured = 16;
inline static const int shift_promoted = 20;
inline static const int shift_en_passant = 24;
inline static const int shift_castle = 25;

constexpr unsigned int get_encoded_value(
    const Move &m,
    const int &bits_shift_to_right,
    const unsigned int &reserved_space_hex_value) {
  return (m >> bits_shift_to_right) & reserved_space_hex_value;
}

constexpr void remove_encoded_value(
    Move &m,
    const int &bits_shift_to_left,
    const unsigned int &reserved_space_hex_value) {
  m &= ~(reserved_space_hex_value << bits_shift_to_left);
}

constexpr void set_encoded_value(Move &m,
                                 const unsigned int &value,
                                 const int &bits_shift_to_left,
                                 const unsigned int &reserved_space_hex_value) {
  remove_encoded_value(m, bits_shift_to_left, reserved_space_hex_value);
  m |= (value & reserved_space_hex_value) << bits_shift_to_left;
}

constexpr Square get_from(const Move &m) {
  return static_cast<Square>(
      get_encoded_value(m, shift_from, designated_space_in_hex_square));
}

constexpr Square get_to(const Move &m) {
  return static_cast<Square>(
      get_encoded_value(m, shift_to, designated_space_in_hex_square));
}

constexpr Piece get_piece(const Move &m) {
  return static_cast<Piece>(
      get_encoded_value(m, shift_piece, designated_space_in_hex_piecetype));
}

constexpr Piece get_captured_piece(const Move &m) {
  return static_cast<Piece>(
      get_encoded_value(m, shift_captured, designated_space_in_hex_piecetype));
}

constexpr Piece get_promoted_piece(const Move &m) {
  return static_cast<Piece>(
      get_encoded_value(m, shift_promoted, designated_space_in_hex_piecetype));
}

constexpr bool is_en_passand(const Move &m) {
  return get_encoded_value(m, shift_en_passant, designated_space_in_hex_flag);
}

constexpr bool can_castle(const Move &m) {
  return get_encoded_value(m, shift_castle, designated_space_in_hex_caslte) !=
         BLANK;
}

constexpr CastlePermission get_castle_permission(const Move &m) {
  return static_cast<CastlePermission>(
      get_encoded_value(m, shift_castle, designated_space_in_hex_caslte));
}

constexpr void set_from(Move &m, const unsigned int &from) {
  set_encoded_value(m, from, shift_from, designated_space_in_hex_square);
}

constexpr void set_to(Move &m, const unsigned int &to) {
  set_encoded_value(m, to, shift_to, designated_space_in_hex_square);
}

constexpr void set_piece(Move &m, const unsigned int &piece) {
  set_encoded_value(m, piece, shift_piece, designated_space_in_hex_piecetype);
}

constexpr void set_capture_piece(Move &m, unsigned int piece) {
  set_encoded_value(m, piece, shift_captured,
                    designated_space_in_hex_piecetype);
}

constexpr void set_promoted_piece(Move &m, unsigned int piece) {
  set_encoded_value(m, piece, shift_promoted,
                    designated_space_in_hex_piecetype);
}

constexpr void set_en_passant(Move &m, bool is_en_passant) {
  set_encoded_value(m, (is_en_passant ? ONE : BLANK), shift_en_passant,
                    designated_space_in_hex_flag);
}

constexpr void set_castle_permission(Move &m, const unsigned int &permission) {
  set_encoded_value(m, permission, shift_castle,
                    designated_space_in_hex_caslte);
}

constexpr Move make_move(unsigned int from,
                         unsigned int to,
                         unsigned int piece_type) {
  return (from & designated_space_in_hex_square) |
         ((to & designated_space_in_hex_square) << shift_to) |
         ((piece_type & designated_space_in_hex_piecetype) << shift_piece);
}

constexpr void set_move(Move &m, unsigned int from, unsigned int to) {
  m = (from & designated_space_in_hex_square) |
      ((to & designated_space_in_hex_square) << shift_to);
}
}   // namespace MoveUtils

constexpr Square operator+(Square s, bitUtility::Direction d) {
  return static_cast<Square>(static_cast<int>(s) + static_cast<int>(d));
}
constexpr Square operator-(Square s, bitUtility::Direction d) {
  return static_cast<Square>(static_cast<int>(s) - static_cast<int>(d));
}
inline Square &operator+=(Square &s, bitUtility::Direction d) {
  return s = s + d;
}
inline Square &operator-=(Square &s, bitUtility::Direction d) {
  return s = s - d;
}


#endif /* MOVE_H */
