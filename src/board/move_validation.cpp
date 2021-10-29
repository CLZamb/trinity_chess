#include "headers/move_validation.h"

MoveValidator::MoveValidator() {}
MoveValidator::~MoveValidator() {}

bool MoveValidator::is_valid_move(const Move& mv) {
  int p_type = mv.get_piece();
  int from = mv.get_from();
  int to = mv.get_to();

  switch (p_type) {
    case bR:
    case wR:
      std::cout << "is rook " << std::endl;
      return rook(from, to);
    case bN:
    case wN:
      return knight(from, to);
    case bB:
    case wB:
      return bishop(from, to);
    case bK:
    case wK:
      return king(from, to);
    case bQ:
    case wQ:
      return queen(from, to);
    case bP:
    case wP:
      return pawn(from, to);
    default:
      return false;
  }

  return false;
}

bool MoveValidator::rook(int from, int to) {
  if ((to % 8) == from) return true;
  return false;
}

bool MoveValidator::knight(int from, int to) {
  if ((from + 17) == to) return true;
  if ((from - 17) == to) return true;
  if ((from + 15) == to) return true;
  if ((from - 15) == to) return true;
  if ((from + 10) == to) return true;
  if ((from - 10) == to) return true;
  if ((from + 6) == to) return true;
  if ((from - 6) == to) return true;

  return false;
}


bool MoveValidator::bishop(int from, int to) {
    return false;
}

bool MoveValidator::king(int from, int to) {
    return false;
}

bool MoveValidator::queen(int from, int to) {
    return false;
}

bool MoveValidator::pawn(int from, int to) {
    if ((from + 8) == to)
        return true;

    return false;
}
