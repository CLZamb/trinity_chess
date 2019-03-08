#include "movement.h"

Movement::Movement(Board* board, Player** turn)
    : m_board(board), pp_cur_player_turn(turn) {}

Movement::~Movement() {}

void Movement::move_piece(Move move) {
  unsigned int from = move.get_from();
  unsigned int to = move.get_to();

  Piece* piece = take_piece(from);
  Piece* captured_piece = capture_piece(to);

  if (captured_piece)
    move.set_capture_piece(captured_piece->get_type_and_color());

  m_board->make_move(piece->get_type_and_color(), from, to, true);
  move.set_piece(piece->get_type_and_color());
  prev_moves.push_back(move.get_uint_move());

  change_turn();
}

void Movement::try_move_piece(int move) {
  unsigned int from = Get_from_sq(move);
  unsigned int to = Get_to_sq(move);
  unsigned int piece = Get_piece(move);
  unsigned int captured_piece = m_board->get_piece_at(to);

  if (Valid_piece(captured_piece)) {
    if ((captured_piece == bK)|| (captured_piece == wK))
      checkmate = true;

    m_board->capture_piece(captured_piece, to);

    move |= ((captured_piece & 0xf) << 12);
  }

  assert(Valid_piece(piece));
  m_board->make_move(piece, from, to);

  prev_moves.push_back(move);
  change_turn();
}

void Movement::change_turn() {
  (*pp_cur_player_turn) = (*pp_cur_player_turn)->get_opponent();
}

bool Movement::get_checkmate() { return checkmate; }

Piece* Movement::take_piece(int startSquare) {
  Piece* piece = m_board->get_piece_at_pos(startSquare);
  assert(piece);

  return piece;
}

Piece* Movement::capture_piece(int end_square) {
  Piece* piece = m_board->get_piece_at_pos(end_square);
  if (!piece)
    return nullptr;

  int type = piece->get_type_and_color();

  if ((type == bK)|| (type == wK)) checkmate = true;

  m_board->capture_piece(type, end_square);
  return piece;
}

void Movement::undo_last_move(bool real_move /* false */) {
  if (prev_moves.empty()) {
    std::cout << "can't undo further" << std::endl;
    return;
  }

  int last_move = prev_moves.back();
  unsigned int piece_captured = Get_captured(last_move);

  if (piece_captured) {
    if ((piece_captured == bK)|| (piece_captured == wK)) checkmate = false;
  }

  m_board->undo_move(last_move, real_move);

  prev_moves.pop_back();
  change_turn();
}

bool Movement::is_valid_move(Move pmove) {
  if (!pmove.is_valid_move())
    return false;

  int from = pmove.get_from();
  int to = pmove.get_to();

  Piece* current_piece = m_board->get_piece_at_pos(from);
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
  // order_moves(&m_legalMoves);
  int best_move = 0;
  int best_score = INT_MIN;
  int score;

  for (const int& mv : m_legalMoves) {
     movement->try_move_piece(mv);
     score = -negamax(4, INT_MIN + 1, INT_MAX, -1);
     movement->undo_last_move();
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
  // order_moves(&m_legalMoves);

  if (m_legalMoves.size() == 0)
    return color * evaluate_board();

  int value = INT_MIN;

  for (const int& mv : m_legalMoves) {
    movement->try_move_piece(mv);
    value = std::max(value, -negamax(depth - 1, -beta, -alpha, -color));
    movement->undo_last_move();
    alpha = std::max(alpha, value);

    if (alpha >= beta)
      break;
  }

  return value;
}

void Movement::MoveGenerator::generate_moves(MoveList* legalMoves) {
  bool has_black_pieces = (*movement->pp_cur_player_turn)->has_black_pieces();
  movement->m_board->generate_all_moves(has_black_pieces, legalMoves);
}

struct cmp {
  template <typename T> bool operator()(const T &l, const T &r) const {
    if (l.second != r.second)
      return l.second > r.second;

    return l.first > r.first;
  }
};

struct cmpneg {
  template <typename T> bool operator()(const T &l, const T &r) const {
    if (l.second != r.second)
      return l.second < r.second;

    return l.first < r.first;
  }
};

void Movement::MoveGenerator::order_moves(MoveList* legal_moves) {
  int value = 0;
  for (auto i : *legal_moves) {
    movement->try_move_piece(i);
    value = evaluate_board();
    move_map.insert({i, value});
    movement->undo_last_move();
  }

  legal_moves->clear();
  if ((*movement->pp_cur_player_turn)->has_black_pieces()) {
    std::set<std::pair<int, int>, cmp> setOfMoves(move_map.begin(), move_map.end());
    // Iterate over a set using range base for loop
    // It will display the items in sorted order of values
    for (auto const &element : setOfMoves)
      legal_moves->push_back(element.first);
  } else {
    std::set<std::pair<int, int>, cmpneg> setOfMoves(move_map.begin(),
        move_map.end());
    // Iterate over a set using range base for loop
    // It will display the items in sorted order of values
    for (auto const &element : setOfMoves)
      legal_moves->push_back(element.first);
  }

  move_map.clear();
}

int Movement::MoveGenerator::evaluate_board() {
  // TODO(ME) : add bonus and movilty so that it determines the advantange
  return movement->m_board->get_board_score();;
}
