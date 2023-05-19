#include "chess.h"

#include "board/board_window/board_components.hpp"
#include "board/check_move/chess_validator.h"
#include "input/input_components.h"
#include "utils/move.hpp"

namespace MU = MoveUtils;
namespace SU = StringUtils;
namespace IC = InputComponents;
namespace BC = BoardComponents;
using std::make_unique;
using std::string;

Chess::Chess(BoardConfigInfo &b)
    : m_side_to_move(b.initial_side)
    , m_position_fen(b.fen_fields, m_position)
    , m_special_move(m_position)
    , p_validator(std::make_unique<ChessValidator>(m_position)) {
  m_side_to_move.attach(p_validator.get());
  m_side_to_move.attach(&m_position);
  m_side_to_move.notify_side();
}

void Chess::make_move(const Move &mv) {
  m_position.make_move(mv);
  m_special_move.handle_special_move(mv, m_position);
  send_event(mv);
}

Move Chess::convert_string_to_move(const string &m) {
  Move mv = SU::to_move(m);
  Square from = MU::get_from(mv);
  Square to = MU::get_to(mv);

  Piece piece_taken = m_position.get_piece(from);
  Piece piece_captured = m_position.get_piece(to);

  MU::set_piece(mv, piece_taken);
  if (piece_captured) {
    MU::set_capture_piece(mv, piece_captured);
  }

  m_special_move.set_special_move(mv, m_position);
  return mv;
}

bool Chess::is_player_in_check(const Move &m) {
  return p_validator->is_player_in_check(m);
}

bool Chess::is_legal_move(Move &m) { return p_validator->is_legal_move(m); }

bool Chess::is_string_move_format_valid(const std::string &m) {
  return p_validator->is_string_move_format_valid(m);
}

Color Chess::get_cur_color_side() { return m_side_to_move.get_color(); }

void Chess::change_side() { m_side_to_move.change_side(); }

bool Chess::is_checkmate() { return p_validator->is_checkmate(); }
