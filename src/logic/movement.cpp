#include "movement.h"
#include "board.h"

Movement::Movement(Board* board) : p_board(board) {}
Movement::~Movement() {}

void Movement::_init(bool initial_turn) {
  ZobristKey::_init();
  m_zkey = ZobristKey(p_board, initial_turn);
}

bool Movement::get_checkmate() { return checkmate; }

void Movement::change_turn() {
  p_board->change_turn();
  m_zkey.change_turn();
}

Piecetype Movement::capture_piece(int end_square) {
  int piece = p_board->get_piece_at(end_square);

  if ((piece == bK)|| (piece == wK)) checkmate = true;

  return static_cast<Piecetype>(piece);
}

void Movement::move_piece(Move& move) {
  SquareIndices from = move.get_from();
  SquareIndices to = move.get_to();
  Piecetype piece = take_piece(from);
  Piecetype captured_piece = capture_piece(to);

  p_board->move_piece_to_square(piece, from, to);
  m_zkey.move_piece(piece, from, to);

  if (captured_piece) {
    assert(captured_piece);
    move.set_capture_piece(captured_piece);
    m_zkey.capture_piece(captured_piece, to);
    p_board->capture_piece(move, to);
  }

  move.set_piece(piece);
  prev_moves.push_back(move.get_move());
  change_turn();
}

Piecetype Movement::take_piece(int startSquare) {
  return p_board->get_piece_at(startSquare);
}

void Movement::move_piece_bits(Move* move) {
  Piecetype piece = move->get_piece();
  unsigned int captured_piece = p_board->get_piece_at(move->get_to());
  SquareIndices from = move->get_from();
  SquareIndices to = move->get_to();

  if (captured_piece) {
    if ((captured_piece == bK)|| (captured_piece == wK))
      checkmate = true;

    p_board->capture_piece_bit(captured_piece, to);
    m_zkey.capture_piece(captured_piece, to);

    assert(captured_piece);
    move->set_capture_piece(captured_piece);
  }

  assert(utils::check::is_valid_piece(piece));
  p_board->move_piece_bits(piece, from, to);
  m_zkey.move_piece(piece, from, to);

  change_turn();
}

void Movement::undo_last_bitboard_move(Move last_move) {
  SquareIndices from = last_move.get_from();
  SquareIndices to = last_move.get_to();
  unsigned int piece = last_move.get_piece();
  unsigned int piece_captured = last_move.get_captured_piece();

  if ((piece_captured == bK)|| (piece_captured == wK)) checkmate = false;

  p_board->undo_move(piece, piece_captured, to, from);
  m_zkey.undo_move(piece, piece_captured, to, from);
  change_turn();
}

void Movement::undo_last_move() {
  if (prev_moves.empty()) {
    std::cout << "can't undo further" << std::endl;
    return;
  }

  int last_move = prev_moves.back();
  prev_moves.pop_back();
  SquareIndices from = Move::GetFrom(last_move);
  SquareIndices to = Move::GetTo(last_move);
  unsigned int piece = Move::GetPiece(last_move);
  unsigned int piece_captured = Move::GetCapture(last_move);

  if ((piece_captured == bK)|| (piece_captured == wK)) checkmate = false;

  p_board->undo_move(piece, piece_captured, to, from);
  p_board->undo_square_move(piece, piece_captured, to, from);
  m_zkey.undo_move(piece, piece_captured, to, from);
  change_turn();
}

bool Movement::is_valid_move(Move pmove) {
  if (!pmove.get_move())
    return false;

  int from = pmove.get_from();
  int to = pmove.get_to();

  Piece* current_piece = p_board->get_piece_at_square(from);
  Player* opponent = p_board->get_opponent();

  if (!current_piece || !opponent)
    return false;

  // check that the pieces being use belongs to the current player turn
  if (p_board->get_active_player()->has_black_pieces() !=
      current_piece->is_black()) {
    std::cout
        << "Piece at that position does not belong to the current player\n";
    return false;
  }

  if (!check_move(current_piece, from, to))
      return false;

  return true;
}

bool Movement::check_move(Piece* piece, int from, int to) {
  int piece_type = piece->get_type_and_color();

  U64 non_attacks =  p_board->get_non_attack_moves(piece_type, from);
  U64 attacks = p_board->get_piece_attacks(piece_type, from);
  U64 occ = ~p_board->get_own_pieces_occ(piece->is_black());

  U64 all_moves = (attacks | non_attacks) & occ;

  U64 pieceLoc = ONE << to;
  return all_moves & pieceLoc;
}
