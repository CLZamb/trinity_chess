#include "headers/board.h"

Board::Board(string fen /*"rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR"*/)
    : m_fen(m_squares) {
  parser_fen(fen);
}

Board::~Board() {}
bool Board::is_checkmate() { return checkmate; }

void Board::update_turn(const PlayerInfo &turn) { m_turn_info = turn; }

bool Board::is_legal_move(Move &m) {
  SquareIndices from = Move_Utils::get_from(m);
  Piecetype piece = Move_Utils::get_piece(m);
  Piecetype captured = Move_Utils::get_captured_piece(m);

  if (!m_squares.exist_piece_at_position(from) ||
      !check_piece_belongs_to_current_player(piece))
    return false;

  // if (!is_special_move(m)) return false;
  Piece *p_piece = m_pieces.get_piece(piece);

  if (is_attack_move(captured)) {
    return p_piece->is_legal_attack_move(m, m_board_state);
  }

  return p_piece->is_legal_non_attack_move(m, m_board_state);
}

bool Board::is_attack_move(const Piecetype &captured) {
  if (!captured) return false;
  return utils::check::is_black_piece(captured) != m_turn_info.color;
}

bool Board::check_piece_belongs_to_current_player(const Piecetype &piece) {
  if (!piece) return false;
  return utils::check::is_black_piece(piece) == m_turn_info.color;
}

void Board::make_move(Move mv) {
  m_board_state.move(mv);
  move_piece_to_square(mv);
}

Move Board::string_to_move(const string &m) {
  Move mv = string_utils::to_move(m);
  SquareIndices from = Move_Utils::get_from(mv);
  SquareIndices to = Move_Utils::get_to(mv);

  Piecetype piece = m_squares[from].get_piece();
  Piecetype captured = m_squares[to].get_piece();

  Move_Utils::set_piece(mv, piece);
  Move_Utils::set_capture_piece(mv, captured);
  return mv;
}

void Board::move_piece_to_square(const Move &mv) {
  m_squares[Move_Utils::get_to(mv)].set_piece(m_squares[Move_Utils::get_from(mv)].get_piece());
  m_squares[Move_Utils::get_from(mv)].clear_square();
}

void Board::parser_fen(string fen) {
  clear_board();
  SquareIndices square = A1;
  int rank = 7;
  int file = 0;
  Piecetype piece;

  for (const char &c : fen) {
    piece = utils::get_square_index_from_char_key(c);
    if (piece) {
      square = static_cast<SquareIndices>(rank * 8 + file);
      add_to_board(piece, square);

      file++;

    } else if (is_number(c)) {
      file += (c - '0');

    } else if (c == '/') {
      rank--;
      file = 0;
    }

    if (rank < 0)
      break;
  }
}

void Board::clear_board() {
  m_squares.clear();
  m_board_state.clear();
}

void Board::add_to_board(Piecetype type, SquareIndices position) {
  m_squares[position].set_piece(type);
  m_board_state.set_bit_at_player_pieces(utils::check::is_black_piece(type), position);
}

bool Board::is_number(char c) { return c >= '0' && c <= '8'; }
BoardFen &Board::get_board_fen() { return m_fen; }
