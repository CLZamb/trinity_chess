#include "special_move_controller.h"

SpecialMoveController::SpecialMoveController() {}
SpecialMoveController::~SpecialMoveController() {}

void SpecialMoveController::set_castle_permission(CastlePermission perm) {
  m_castling.set_castle_permission(perm);
}

const int &SpecialMoveController::get_castle_permission() {
  return m_castling.get_castle_permission();
}

const SquareIndices &SpecialMoveController::get_en_passant_square() {
  return m_en_passant.get_en_passant_position();
}

void SpecialMoveController::set_en_passant_square(SquareIndices sq) {
  m_en_passant.set_en_passant_position(sq);
}

void SpecialMoveController::handle_special_move(const Move& m, Squares& squares) {
  if (m_special_move) {
    m_special_move->handle_special_move(m, squares);
  }
}

bool SpecialMoveController::is_current_move_special_move() {
  return m_special_move != nullptr;
}

void SpecialMoveController::set_special_move_to_move(Move& m, Squares &squares) {
  Piecetype pct = Move_Utils::get_piece(m);
  if (!is_pawn_piece(pct) && !is_king_piece(pct)) return;

  if (m_castling.is_castle_move(m, squares)) {
    m_special_move = &m_castling;
  } else if (m_en_passant.is_en_passant_move(m)) {
    m_special_move = &m_en_passant;
  } else if (m_pawn_promotion.is_pawn_promotion(m)) {
    m_special_move = &m_pawn_promotion;
  } else {
    m_special_move = nullptr;
  }  

  if (m_special_move)
    m_special_move->assign_special_to_move(m);
}

bool SpecialMoveController::is_pawn_piece(const Piecetype pct) {
  return pct == bP || pct == wP;
}

bool SpecialMoveController::is_king_piece(const Piecetype pct) {
  return pct == bK || pct == wK;
}
