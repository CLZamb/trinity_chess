#include "half_move_clock.h"

#include "board/position/position_utils.h"

HalfMoveClock::HalfMoveClock() {}
HalfMoveClock::~HalfMoveClock() {}

void HalfMoveClock::set_halfmoves(int halfmoves) { m_halfmoves = halfmoves; }

void HalfMoveClock::set_fullmoves(int fullmoves) { m_fullmoves = fullmoves; }

std::string HalfMoveClock::get_halfmoves_as_string() {
  return std::to_string(m_halfmoves);
}

std::string HalfMoveClock::get_fullmoves_as_string() {
  return std::to_string(m_fullmoves);
}

void HalfMoveClock::update_fullmoves() { m_fullmoves++; }

void HalfMoveClock::update_halfmoves(const Move &m) {
  Piece piece = MoveUtils::get_piece(m);
  Piece captured = MoveUtils::get_captured_piece(m);

  if (utils::check::is_pawn_piece(piece) || captured) {
    m_halfmoves++;
    return;
  }

  m_halfmoves = 0;
}

void HalfMoveClock::clear() {
  m_halfmoves = 0;
  m_halfmoves = 1;
}
