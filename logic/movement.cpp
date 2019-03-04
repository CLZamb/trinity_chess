#include "movement.h"

Movement::Movement(Board* board, Player** turn)
    : m_board(board), pp_cur_player_turn(turn) {}

Movement::~Movement() {}

void Movement::move_piece(Move move) {
  // Position start = playerMove.getPosFrom();
  // Position end = playerMove.getPosTo();
  unsigned int from = move.get_from();
  unsigned int to = move.get_to();

  Piece* capturedPiece = capture_piece(to);
  Piece* piece = take_piece(from);
  if (capturedPiece) {
    move.set_capture_piece(capturedPiece->get_type_and_color());
  }
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
  assert(piece != nullptr);

  return piece;
}

Piece* Movement::capture_piece(int endSquare) {
  Piece* piece = m_board->get_piece_at_pos(endSquare);
  if (!piece)
    return nullptr;

  if (piece->get_type() == "king")
    checkmate = true;

  m_board->capture_piece(piece, endSquare);
  return piece;
}

void Movement::undo_last_move() {
  if (prev_moves.empty()) {
    std::cout << "can't undo further" << std::endl;
    return;
  }

  Move last_move = prev_moves.back();

  unsigned int from = last_move.get_from();
  unsigned int to = last_move.get_to();
  unsigned int piece_captured = last_move.get_captured_piece();

  Piece* piece = take_piece(to);
  m_board->make_move(piece, to, from);
  if (piece_captured) {
    if ((piece_captured == bK)|| (piece_captured == wK)) checkmate = false;
    m_board->undo_move(piece_captured, to);
  }

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

bool Movement::check_move(Piece* currentPiece, int from, int to) {
  U64 non_attacks =
    m_board->get_non_attack_moves(currentPiece, from);

  U64 attacks =
    m_board->get_piece_attacks(currentPiece, from);

  U64 occ =
    ~m_board->get_own_pieces_occ(currentPiece->is_black());

  U64 all_moves = (attacks | non_attacks) & occ;

  U64 pieceLoc = ONE << to;
  return all_moves & pieceLoc;
}

Move Movement::MoveGenerator::get_best_move() {
  MoveList m_legalMoves;
  generate_moves(&m_legalMoves);
  Move bestMove;
  int bestScore = INT_MIN;
  int score;

  for (const Move& mv : m_legalMoves) {
     movement->move_piece(mv);
     score = -negamax(4, INT_MIN + 1, INT_MAX, -1);
     movement->undo_last_move();
     if (score > bestScore) {
       bestMove = mv;
       bestScore = score;
     }
  }

  if (m_legalMoves.empty()) {
    bestMove.set_valid_move(false);
    bestMove.set_str_input("quit");
    return bestMove;
  }

  bestMove.set_str_input("");
  bestMove.set_valid_move(true);
  return bestMove;
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

  int value = INT_MIN;

  for (const Move& mv : m_legalMoves) {
    movement->move_piece(mv);
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

int Movement::MoveGenerator::evaluate_board() {
  // TODO(ME) : add bonus and movilty so that it determines the advantange
  return movement->m_board->get_board_score();;
}
