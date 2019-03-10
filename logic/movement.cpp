#include "movement.h"

Movement::Movement(Board* board, Player** turn)
    : m_board(board), pp_cur_player_turn(turn) {
      ZobristKey::_init();
      m_zkey = ZobristKey(board, (*turn)->has_black_pieces());
    }

Movement::~Movement() {}

bool Movement::get_checkmate() { return checkmate; }
// ZobristKey Movement::getZKey() { return m_zkey; }

int Movement::take_piece(int startSquare) {
  return m_board->get_piece_at(startSquare);
}

void Movement::change_turn() {
  (*pp_cur_player_turn) = (*pp_cur_player_turn)->get_opponent();
  m_zkey.change_turn();
}

int Movement::capture_piece(int end_square) {
  int piece = m_board->get_piece_at(end_square);

  if ((piece == bK)|| (piece == wK)) checkmate = true;

  m_board->capture_piece(piece, end_square);
  return piece;
}

void Movement::move_piece(Move move) {
  unsigned int from = move.get_from();
  unsigned int to = move.get_to();
  unsigned int piece = take_piece(from);
  unsigned int captured_piece = capture_piece(to);

  m_board->move_piece_to_square(piece, from, to);

  if (captured_piece)
    move.set_capture_piece(captured_piece);

  move.set_piece(piece);
  prev_moves.push_back(move.get_uint_move());
  change_turn();
}

void Movement::move_piece_bits(int* move) {
  unsigned int from = Get_from_sq(*move);
  unsigned int to = Get_to_sq(*move);
  unsigned int piece = Get_piece(*move);
  unsigned int captured_piece = m_board->get_piece_at(to);

  if (captured_piece) {
    if ((captured_piece == bK)|| (captured_piece == wK))
      checkmate = true;

    m_board->capture_piece(captured_piece, to);

    *move |= ((captured_piece & 0xf) << 12);
  }

  assert(Valid_piece(piece));
  m_board->move_piece_bits(piece, from, to);
  m_zkey.move_piece(piece, from, to);

  change_turn();
}

void Movement::undo_last_bitboard_move(int last_move) {
  unsigned int from = Get_from_sq(last_move);
  unsigned int to = Get_to_sq(last_move);
  unsigned int piece = Get_piece(last_move);
  unsigned int piece_captured = Get_captured(last_move);

  if ((piece_captured == bK)|| (piece_captured == wK)) checkmate = false;

  m_board->undo_move(piece, piece_captured, to, from);
  m_zkey.move_piece(piece, to, from);

  change_turn();
}

void Movement::undo_last_move() {
  if (prev_moves.empty()) {
    std::cout << "can't undo further" << std::endl;
    return;
  }

  int last_move = prev_moves.back();
  prev_moves.pop_back();
  unsigned int from = Get_from_sq(last_move);
  unsigned int to = Get_to_sq(last_move);
  unsigned int piece = Get_piece(last_move);
  unsigned int piece_captured = Get_captured(last_move);

  if ((piece_captured == bK)|| (piece_captured == wK)) checkmate = false;

  m_board->undo_move(piece, piece_captured, to, from);
  m_board->undo_square_move(piece, piece_captured, to, from);
  change_turn();
}

bool Movement::is_valid_move(Move pmove) {
  if (!pmove.is_valid_move())
    return false;

  int from = pmove.get_from();
  int to = pmove.get_to();

  Piece* current_piece = m_board->get_piece_at_square(from);
  Player* opponent = (*pp_cur_player_turn)->get_opponent();

  if (!current_piece || !opponent)
    return false;

  // check that the pieces being use belongs to the current player turn
  if ((*pp_cur_player_turn)->has_black_pieces() !=
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

  U64 non_attacks =  m_board->get_non_attack_moves(piece_type, from);
  U64 attacks = m_board->get_piece_attacks(piece_type, from);
  U64 occ = ~m_board->get_own_pieces_occ(piece->is_black());

  U64 all_moves = (attacks | non_attacks) & occ;

  // printBitboard(all_moves);
  U64 pieceLoc = ONE << to;
  return all_moves & pieceLoc;
}

Move Movement::MoveGenerator::get_best_move() {
  MoveList m_legalMoves;
  generate_moves(&m_legalMoves);
  int best_move = 0;
  int best_score = INT_MIN;
  int score;

  for (int& mv : m_legalMoves) {
     movement->move_piece_bits(&mv);
     score = -negamax(4, INT_MIN + 1, INT_MAX, -1);
     movement->undo_last_bitboard_move(mv);
     if (score > best_score) {
       best_move = mv;
       best_score = score;
     }
  }

  Move best(best_move);
  if ((!best_move) || (m_legalMoves.empty())) {
    best.set_valid_move(false);
    best.set_str_input("quit");
    return best;
  }

  best.set_str_input("");
  best.set_valid_move(true);
  return best;
}

/**
 negamax algorithm
 function negamax( depth, α, β, color)
   if depth = 0 or node is a terminal node then
   return color × the heuristic value of node

  childNodes := generateMoves(node)
  childNodes := orderMoves(childNodes)
  value := −∞
  foreach child in childNodes do
    value := max(value, −negamax(child, depth − 1, −β, −α, −color))
    α := max(α, value)
    if α ≥ β then
      break (* cut-off *)
  return value
 */

int Movement::MoveGenerator::negamax(int depth, int alpha, int beta,
                                     int color) {
  if (movement->checkmate || depth == 0)
    return color * evaluate_board();

  MoveList m_legalMoves;

  generate_moves(&m_legalMoves);

  if (m_legalMoves.size() == 0)
    return color * evaluate_board();

  const TTEntry* entry = movement->m_table.get_entry(movement->m_zkey);
  if (entry && (entry->get_depth() >= depth)) {
    switch (entry->get_flag()) {
      case TTable::EXACT:
        return entry->get_score();
      case TTable::UPPER_BOUND:
        beta = std::min(beta, entry->get_score());
        break;
      case TTable::LOWER_BOUND:
        alpha = std::max(alpha, entry->get_score());
        break;
    }

    if (alpha >= beta) {
      return entry->get_score();
    }
  }

  int value = INT_MIN;
  int best_move;
  int alphaOrig = alpha;
  for (int& mv : m_legalMoves) {
    movement->move_piece_bits(&mv);
    value = std::max(value, -negamax(depth - 1, -beta, -alpha, -color));
    movement->undo_last_bitboard_move(mv);

    if (value > alpha) {
      alpha = value;
      best_move = mv;
    }

    if (alpha >= beta) {
      TTEntry new_entry(mv, value, depth, TTEntry::LOWER_BOUND);
      movement->m_table.set(movement->m_zkey, new_entry);
      break;
    }
  }

  // Store bestScore in transposition table
  TTEntry::Flag flag;
  if (alpha <= alphaOrig) {
    flag = TTEntry::UPPER_BOUND;
  } else {
    flag = TTEntry::EXACT;
  }

  TTEntry new_tt_entry(best_move, value, depth, flag);
  movement->m_table.set(movement->m_zkey, new_tt_entry);

  return value;
}

void Movement::MoveGenerator::generate_moves(MoveList* legalMoves) {
  bool has_black_pieces = (*movement->pp_cur_player_turn)->has_black_pieces();
  movement->m_board->generate_all_moves(has_black_pieces, legalMoves);
}

int Movement::MoveGenerator::evaluate_board() {
  // TODO(ME) : add bonus and movilty so that it determines the advantange
  return movement->m_board->get_board_score();;
}
