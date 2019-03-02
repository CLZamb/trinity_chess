#include "movement.h"

Movement::Movement(Board *board, Player **turn)
    : m_board(board), m_currentPlayerTurn(turn) {}

Movement::~Movement() {}

void Movement::movePiece(Move pmove) {
  // Position start = playerMove.getPosFrom();
  // Position end = playerMove.getPosTo();
  unsigned int from = pmove.getFrom();
  unsigned int to = pmove.getTo();

  Piece *capturedPiece = capturePiece(to);
  Piece *piece = takePiece(from);
  if (capturedPiece) {
    pmove.setCapturePiece(capturedPiece->getTypeAndColor());
  }
  m_board->make_move(piece, from, to);
  prevMoves.push_back(pmove);
  changeTurn();
}

void Movement::changeTurn() {
  (*m_currentPlayerTurn) = (*m_currentPlayerTurn)->getOpponent();
}

Piece *Movement::takePiece(int startSquare) {
  Piece *piece = m_board->getPieceAtPos(startSquare);
  assert(piece != nullptr);

  return piece;
}

Piece *Movement::capturePiece(int endSquare) {
  Piece *piece = m_board->getPieceAtPos(endSquare);
  if (!piece)
    return nullptr;

  if (piece->getPieceType() == "king")
    checkmate = true;

  m_board->capture_piece(piece, endSquare);
  return piece;
}

void Movement::undoLastMove() {
  if (prevMoves.empty()) {
    std::cout << "can't undo further" << std::endl;
    return;
  }

  Move lastMove = prevMoves.back();

  unsigned int from = lastMove.getFrom();
  unsigned int to = lastMove.getTo();
  unsigned int pieceCaptured = lastMove.getCapturedPiece();

  Piece *piece = takePiece(to);
  m_board->make_move(piece, to, from);
  if (pieceCaptured) {
    if ((pieceCaptured == bK)|| (pieceCaptured == wK)) checkmate = false;
    m_board->undo_move(pieceCaptured, to);
  }

  prevMoves.pop_back();
  changeTurn();
}

bool Movement::isValidMove(Move pmove) {
  if (!pmove.getValidMove())
    return false;

  int from = pmove.getFrom();
  int to = pmove.getTo();

  Piece *currentPiece = m_board->getPieceAtPos(from);
  Player *opponent = (*m_currentPlayerTurn)->getOpponent();

  if (!currentPiece || !opponent)
    return false;

  // check that the pieces being use belongs to the current player turn
  if ((*m_currentPlayerTurn)->getColorPieces() !=
      currentPiece->getColorPiece()) {
    std::cout
        << "Piece at that position does not belong to the current player\n";

    std::cout << (*m_currentPlayerTurn)->getColorPieces() << std::endl;
    std::cout << currentPiece->getColorPiece() << std::endl;
    return false;
  }

  Piece *destinationPiece = m_board->getPieceAtPos(to);
  if (destinationPiece) {
    if (destinationPiece->getColorPiece() == opponent->getColorPieces())
      currentPiece->setCapturingState(true);
    else
      return false;
  }

  if (!checkMove(currentPiece, from, to))
      return false;

  return true;
}

bool Movement::checkMove(Piece* currentPiece, int from, int to) {
  U64 non_attack_moves = m_board->getNonAttackMoves(currentPiece, SquareIndices(from));
  U64 attacks = m_board->getPieceAttacks(currentPiece, SquareIndices(from));
  U64 occ = ~m_board->getOwnPiecesOcc(currentPiece->getColorPiece());

  U64 all_moves = (attacks | non_attack_moves) & occ;

  U64 pieceLoc = ONE << to;
  return all_moves & pieceLoc;
}

Move Movement::MoveGenerator::getBestMove() {
  MoveList m_legalMoves;
  getPossibleMoves(&m_legalMoves);
  Move bestMove;
  int bestScore = INT_MIN;
  int score;

  for (const Move& mv : m_legalMoves) {
     movement->movePiece(mv);
     score = -negamax(4, INT_MIN + 1, INT_MAX, -1);
     movement->undoLastMove();
     if (score > bestScore) {
       bestMove = mv;
       bestScore = score;
     }
  }

  if (m_legalMoves.empty()) {
    bestMove.m_validMove = false;
    bestMove.m_input = "quit";
    return bestMove;
  }

  bestMove.m_validMove = true;
  bestMove.m_input = "";
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
    return color * evaluateBoard();

  MoveList m_legalMoves;
  getPossibleMoves(&m_legalMoves);

  if (m_legalMoves.size() == 0)
    return color * evaluateBoard();

  int value = INT_MIN;

  for (const Move& mv : m_legalMoves) {
    movement->movePiece(mv);
    value = std::max(value, -negamax(depth - 1, -beta, -alpha, -color));
    movement->undoLastMove();
    alpha = std::max(alpha, value);

    if (alpha >= beta)
      break;
  }

  return value;
}

void Movement::MoveGenerator::getPossibleMoves(MoveList* legalMoves) {
  std::string colorPieces = (*movement->m_currentPlayerTurn)->getColorPieces();
  movement->m_board->generateAllMoves(colorPieces, legalMoves);
}

int Movement::MoveGenerator::evaluateBoard() {
  // TODO(ME) : add bonus and movilty so that it determines the advantange
  return movement->m_board->evalPosition();;
}
