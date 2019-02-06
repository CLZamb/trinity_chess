#include "movement.h"

Movement::Movement(Board *board, Player **turn)
    : m_board(board), m_currentPlayerTurn(turn) {}

Movement::~Movement() {}

void Movement::movePiece(std::string strMove) {
  Move playerMove(strMove);
  Position start = playerMove.getPosFrom();
  Position end = playerMove.getPosTo();

  Piece *capturedPiece = capturePiece(end);
  Piece *piece = takePiece(start);
  m_board->setPieceAtPos(piece, end);

  prevMoves.push_back(History{piece, capturedPiece, start, end});
  changeTurn();
}

void Movement::changeTurn() {
  (*m_currentPlayerTurn) = (*m_currentPlayerTurn)->getOpponent();
}

Piece *Movement::takePiece(Position startSquare) {
  Piece *piece = m_board->getPieceAtPos(startSquare);
  if (!piece)
    return nullptr;

  m_board->clearSquareAt(startSquare);
  return piece;
}

Piece *Movement::capturePiece(Position endSquare) {
  Piece *piece = m_board->getPieceAtPos(endSquare);
  if (!piece)
    return nullptr;

  if (piece->getPieceType() == "king")
    checkmate = true;

  piece->setCapturedState(true);
  return piece;
}

void Movement::undoLastMove() {
  if (prevMoves.empty()) {
    std::cout << "can't undo further" << std::endl;
    return;
  }

  History temp = prevMoves.back();
  if (temp.capturedPiece) {
    // if (temp.capturedPiece->getPieceType() == "king")
    //   checkmate = false;
    m_board->setPieceAtPos(temp.capturedPiece, temp.end);
    temp.capturedPiece->setCapturedState(false);
  } else {
    m_board->clearSquareAt(temp.end);
  }

  m_board->setPieceAtPos(temp.piece, temp.start);
  prevMoves.pop_back();
  // changeTurn
  changeTurn();
}

bool Movement::isValidMove(std::string strMove) {
  // changeit to validate move
  Move playerMove(strMove);
  if (!playerMove.isValidInput())
    return false;

  Position from = playerMove.getPosFrom();
  Position to = playerMove.getPosTo();

  if (!isValidPosition(from) || !isValidPosition(to))
    return false;

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

  if (!currentPiece->checkMove(from, to))
    return false;

  if (currentPiece->getPieceType() != "knight")
    if (hasCollision(from, to))
      return false;

  return true;
}

bool Movement::hasCollision(Position from, Position to) {
  int fromX = from.getPositionX();
  int fromY = from.getPositionY();

  int toX = to.getPositionX();
  int toY = to.getPositionY();

  int dx = abs(fromX - toX);
  int dy = abs(fromY - toY);

  bool vertical = dx == 0 && dy > 0;
  bool horizontal = dx > 0 && dy == 0;
  bool diagonal = dx > 0 && dy > 0;

  int dirY = (fromY - toY) > 0 ? DOWN : UP;
  int dirX = (fromX - toX) > 0 ? LEFT : RIGHT;

  Position temPos = from;

  // Pending
  if (vertical) {
    for (int i = 1; i < dy; ++i) {
      temPos.setPositionY(fromY + (dirY * i));
      if (m_board->getSquareAtPos(temPos)->hasPiece())
        return true;
    }
  } else if (horizontal) {
    for (int i = 1; i < dx; ++i) {
      temPos.setPositionX(fromX + (dirX * i));
      if (m_board->getSquareAtPos(temPos)->hasPiece())
        return true;
    }
  } else if (diagonal) {
    for (int i = 1; i < dy; ++i) {
      temPos.setPosition(fromX + (dirX * i), fromY + (dirY * i));
      if (m_board->getSquareAtPos(temPos)->hasPiece())
        return true;
    }
  }

  return false;
}

bool Movement::isValidPosition(Position pos) {
  return (pos.getPositionX() >= 0) && (pos.getPositionX() < 8) &&
         (pos.getPositionY() >= 0) && (pos.getPositionY() < 8);
}
/*
 * moveGenerator(board, list)
 *  loop all pieces
 *    -> Slider loop each dir add move
 *      -> addMove list->moves[list->count] = move; list->count++;
 * */

std::string Movement::MoveGenerator::getBestMove() {
  std::vector<std::string> allmoves;
  getPossibleMoves(allmoves);
  std::string *bestMove;
  int bestScore = INT_MIN;
  int score;
  for (std::vector<std::string>::iterator mv = allmoves.begin();
       mv != allmoves.end(); mv++) {
    movement->movePiece(*mv);
    score = -negamax(4, INT_MIN + 1, INT_MAX);
    movement->undoLastMove();
    if (score > bestScore) {
      bestMove = &*mv;
      bestScore = score;
    }
  }

  if (!bestMove)
    return "quit";

  if (allmoves.empty())
    return "quit";

  movement->checkmate = false;

  return *bestMove;
}

void Movement::MoveGenerator::getPossibleMoves(
    std::vector<std::string> &moves) {
  PiecesSetPtr playerPieces = (*movement->m_currentPlayerTurn)->getPieces();

  for (Piece *it : playerPieces) {
    if (!it->isCaptured())
      it->possibleMoves(moves);
  }

  for (std::vector<std::string>::iterator it = moves.begin();
       it != moves.end();) {
    if (!movement->isValidMove(*it))
      moves.erase(it);
    else
      ++it;
  }
}

int Movement::MoveGenerator::evaluateBoard() {
  // TODO(ME) : add bonus and movilty so that it determines the advantange
  int value = 0;

  PiecesSetPtr p1Pieces = (*movement->m_currentPlayerTurn)->getPieces();
  PiecesSetPtr p2Pieces =
      (*movement->m_currentPlayerTurn)->getOpponent()->getPieces();

  for (Piece *it : p1Pieces) {
    if (!it->isCaptured())
      value += it->getValue();
  }

  for (Piece *it : p2Pieces) {
    if (!it->isCaptured())
      value += it->getValue();
  }

  return value;
}

/* Negamax algorithm
  int negaMax( int depth ) {
     if ( depth == 0 ) return evaluate();
     int max = -oo;
     for ( all moves)  {
     score = -negaMax( depth - 1 );
     if( score > max )
     max = score;
     }
     return max;
  }
 * */

int Movement::MoveGenerator::negamax(int depth, int alpha, int beta) {
  if (movement->checkmate || depth == 0)
    return evaluateBoard();

  std::vector<std::string> allmoves;
  getPossibleMoves(allmoves);

  if (allmoves.size() == 0)
    return evaluateBoard();

  for (std::vector<std::string>::iterator it = allmoves.begin();
       it != allmoves.end(); it++) {
    movement->movePiece(*it);
    int val = -negamax(depth - 1, -beta, -alpha);
    movement->undoLastMove();

    if (val >= beta)
      return val;

    if (val > alpha)
      alpha = val;
  }

  return alpha;
}

Movement::Move::Move() {}
Movement::Move::Move(std::string nextMove) { setNextMove(nextMove); }
Movement::Move::~Move() {}

void Movement::Move::setNextMove(std::string playerInput) {
  std::vector<std::string> positions =
      scan(playerInput, std::regex("(\\w\\w)"));

  if (positions.size() == 2) {
    std::string from = positions[0], to = positions[1];
    fromPos.setPosition(from[0], from[1]);
    toPos.setPosition(to[0], to[1]);
    validInput = true;
  } else {
    validInput = false;
  }
}

std::vector<std::string> Movement::Move::scan(std::string str,
                                              const std::regex reg) {
  std::vector<std::string> results;
  std::smatch matches;
  // std::cout << std::boolalpha;
  while (std::regex_search(str, matches, reg)) {
    results.push_back(matches.str(1));
    str = matches.suffix().str();
  }

  return results;
}

Position Movement::Move::getPosFrom() { return fromPos; }
Position Movement::Move::getPosTo() { return toPos; }
bool Movement::Move::isValidInput() { return validInput; }
