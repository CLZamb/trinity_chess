#include "movement.h"
#include "board.h"

Movement::Movement(Board* board, Player** turn)
    : p_board(board), pp_cur_player_turn(turn) {}

Movement::~Movement() {}

void Movement::_init(bool initial_turn) {
  ZobristKey::_init();
  m_zkey = ZobristKey(p_board, initial_turn);
}

bool Movement::get_checkmate() { return checkmate; }

Piecetype Movement::take_piece(int startSquare) {
  return p_board->get_piece_at(startSquare);
}

void Movement::change_turn() {
  *pp_cur_player_turn = (*pp_cur_player_turn)->get_opponent();
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

  assert(check::is_valid_piece(piece));
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

  U64 non_attacks =  p_board->get_non_attack_moves(piece_type, from);
  U64 attacks = p_board->get_piece_attacks(piece_type, from);
  U64 occ = ~p_board->get_own_pieces_occ(piece->is_black());

  U64 all_moves = (attacks | non_attacks) & occ;

  U64 pieceLoc = ONE << to;
  return all_moves & pieceLoc;
}

Movement::MoveGenerator::MoveGenerator(Movement* movement)
  : movement(movement), p_board(movement->p_board) {}

bool Movement::MoveGenerator::time_out() {
  m_elapsed =
    std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - m_start).count();

  if (m_elapsed >= (m_time_allocated)) return true;

  return false;
}

void Movement::MoveGenerator::clear_for_seach() {
  // movement->m_table.clear();
  p_board->clear_search_history();
  p_board->clear_killer_moves();
  p_board->reset_ply();
}

Move Movement::MoveGenerator::search_best_move() {
  m_start = std::chrono::steady_clock::now();
  Move best_move;
  m_stop = false;
  has_black_pieces = (*movement->pp_cur_player_turn)->has_black_pieces();
  side = has_black_pieces ? -1 : 1;
  clear_for_seach();

  int total_depth = 0;
  for (int currDepth = 1;  ; currDepth++) {
    best_move = root_negamax(currDepth);
    m_elapsed =
      std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - m_start).count();

    if (m_stop)
      break;

    if (m_elapsed >= (m_time_allocated/2)) break;
    total_depth = currDepth;
  }

  std::cout << "depth: : " << total_depth  << std::endl;
  auto end = std::chrono::steady_clock::now();

  cout << "Elapsed time in milliseconds : "
    << std::chrono::duration_cast<std::chrono::milliseconds>(end - m_start).count()
    << " ms" << endl;

  return best_move;
}

Move Movement::MoveGenerator::root_negamax(int cur_depth) {
  MoveList m_legalMoves;
  generate_moves(&m_legalMoves);
  best_move = 0;
  score = best_score = INT_MIN;
  counter = 0;
  for (Move& mv : m_legalMoves) {
    pick_next_move(counter++, &m_legalMoves);
    movement->move_piece_bits(&mv);
    score = -negamax(cur_depth, INT_MIN + 1, INT_MAX, side);
    movement->undo_last_bitboard_move(mv);

    if (m_stop || time_out()) {
      m_stop = true;
      break;
    }

    if (score > best_score) {
      best_move = mv.get_move();
      best_score = score;
    }
  }

  Move best(best_move);
  if ((!best_move) || (m_legalMoves.empty()))
    return best;

  return best;
}

int Movement::MoveGenerator::quiescence_search(int alpha, int beta, int color) {
  if (m_stop || time_out()) {
    m_stop = true;
    return color * evaluate_board();
  }

  if (p_board->get_ply() >= MAX_DEPTH)
    return color * evaluate_board();

  int best_value = color * p_board->evaluate_board();
  alpha = std::max(alpha, best_value);

  if (alpha >= beta)
    return alpha;

  MoveList m_legalMoves;

  generate_all_cap_moves(&m_legalMoves);

  if (m_legalMoves.size() == 0)
    return color * evaluate_board();

  int counter = 0;
  for (Move& mv : m_legalMoves) {
    pick_next_move(counter++, &m_legalMoves);
    movement->move_piece_bits(&mv);
    best_value = std::max(best_value, -quiescence_search(-beta, -alpha, -color));
    movement->undo_last_bitboard_move(mv);

    alpha = std::max(alpha, best_value);
    if (alpha >= beta)
      break;
  }

  return alpha;
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
  if (m_stop || time_out()) {
    m_stop = true;
    return color * evaluate_board();
  }

  if (depth == 0)
    return quiescence_search(alpha, beta, color);

  if (movement->checkmate)
    return color * evaluate_board();

  int orig_alpha = alpha;

  int repeated = is_repeated_move(depth, &alpha, &beta);
  if (repeated)
    return repeated;

  MoveList m_legalMoves;

  generate_moves(&m_legalMoves);

  if (m_legalMoves.size() == 0)
    return color * evaluate_board();

  int value = INT_MIN;
  int counter = 0;
  Move* best_move = &m_legalMoves.at(0);
  for (Move& mv : m_legalMoves) {
    pick_next_move(counter++, &m_legalMoves);
    movement->move_piece_bits(&mv);
    value = std::max(value, -negamax(depth - 1, -beta, -alpha, -color));
    movement->undo_last_bitboard_move(mv);

    if (value > alpha) {
      alpha = value;
      best_move = &mv;
      if (!(mv.get_captured_piece()))
        p_board->update_search_history(mv.get_piece(), mv.get_to(), depth);
    }

    if (alpha >= beta) {
      best_move = &mv;
      if (!(mv.get_captured_piece()))
        p_board->update_killers(mv);
      break;
    }
  }

  TTEntry::Flag flag = get_flag(alpha, orig_alpha, beta);
  movement->m_table.set(
      movement->m_zkey, TTEntry(best_move, alpha, depth, flag));

  return alpha;
}

int Movement::MoveGenerator::is_repeated_move(
    const int &depth, int* alpha, int* beta) {
  const TTEntry* entry = movement->m_table.get_entry(movement->m_zkey);
  if ((entry) && (entry->get_depth() >= depth)) {
    switch (entry->get_flag()) {
      case TTEntry::EXACT:
        return entry->get_score();
      case TTEntry::LOWER_BOUND:
        *alpha = std::max(*alpha, entry->get_score());
        break;
      case TTEntry::UPPER_BOUND:
        *beta = std::min(*beta, entry->get_score());
        break;
    }

    if (*alpha >= *beta)
      return entry->get_score();
  }

  return 0;
}

TTEntry::Flag Movement::MoveGenerator::get_flag(
    int alpha, int orig_alpha, int beta) {

  if (alpha <= orig_alpha) {
    return TTEntry::UPPER_BOUND;
  } else if (alpha >= beta) {
    return TTEntry::LOWER_BOUND;
  }

  return TTEntry::EXACT;
}

void Movement::MoveGenerator::pick_next_move(int index, MoveList* moves) {
  int best_so_far = index;
  unsigned int best_score = 0;
  for (unsigned int i = index; i < moves->size(); ++i) {
    if (moves->at(i).get_score() > best_score) {
      best_score = moves->at(i).get_score();
      best_so_far = i;
    }
  }

  iter_swap(moves->begin() + index, moves->begin() + best_so_far);
}

void Movement::MoveGenerator::generate_moves(MoveList* legalMoves) {
  has_black_pieces = (*movement->pp_cur_player_turn)->has_black_pieces();
  p_board->generate_all_moves(has_black_pieces, legalMoves);
}

void Movement::MoveGenerator::generate_all_cap_moves(MoveList* capMoves) {
  has_black_pieces = (*movement->pp_cur_player_turn)->has_black_pieces();
  p_board->generate_all_cap_moves(has_black_pieces, capMoves);
}

int Movement::MoveGenerator::evaluate_board() {
  return p_board->evaluate_board();
}
