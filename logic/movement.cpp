#include "movement.h"

Movement::Movement(Board *board, Player **turn)
    : m_board(board), m_currentPlayerTurn(turn) {}

Movement::~Movement() {}

void Movement::movePiece(string strMove) {
  Move playerMove(strMove);
  Position start = playerMove.getPosFrom();
  Position end = playerMove.getPosTo();

  Piece *capturedPiece = capturePiece(end);
  Piece *piece = takePiece(start);
  m_board->setPieceAtPos(piece, end);

  prevMoves.push_back(Move(piece, capturedPiece, start, end));
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

  Move lastMove = prevMoves.back();
  if (lastMove.capturedPiece) {
    m_board->setPieceAtPos(lastMove.capturedPiece, lastMove.to);
    lastMove.capturedPiece->setCapturedState(false);
    if (lastMove.capturedPiece->getPieceType() == "king")
      checkmate = false;
  } else {
    m_board->clearSquareAt(lastMove.to);
  }

  m_board->setPieceAtPos(lastMove.piece, lastMove.from);
  prevMoves.pop_back();
  // changeTurn
  changeTurn();
}

bool Movement::isValidMove(string strMove) {
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
 * (* Initial call for Player A's root node *)
 *  negamax(rootNode, depth, −∞, +∞, 1)
 * */
string Movement::MoveGenerator::getBestMove() {
  vector<string> moves;
  getPossibleMoves(moves);
  sortMoves(moves);
  string *bestMove;
  int bestScore = INT_MIN;
  int score;
  for (vector<string>::iterator mv = moves.begin(); mv != moves.end(); mv++) {
    movement->movePiece(*mv);
    score = -negamax(3, INT_MIN + 1, INT_MAX, -1);
    movement->undoLastMove();
    if (score > bestScore) {
      bestMove = &*mv;
      bestScore = score;
    }
  }

  if (!bestMove)
    return "quit";

  if (moves.empty())
    return "quit";

  return *bestMove;
}
/**
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
 **/
int Movement::MoveGenerator::negamax(int depth, int alpha, int beta,
                                     int color) {
  if (movement->checkmate || depth == 0)
    return color * evaluateBoard();

  vector<string> allmoves;
  getPossibleMoves(allmoves);

  if (allmoves.size() == 0)
    return color * evaluateBoard();

  sortMoves(allmoves);
  int value = INT_MIN;
  for (vector<string>::iterator it = allmoves.begin(); it != allmoves.end();
       it++) {
    movement->movePiece(*it);
    value = std::max(value, -negamax(depth - 1, -beta, -alpha, -color));
    movement->undoLastMove();
    alpha = std::max(alpha, value);

    if (alpha >= beta)
      break;
  }

  return value;
}

void Movement::MoveGenerator::getPossibleMoves(vector<string> &moves) {
  PiecesSetPtr playerPieces = (*movement->m_currentPlayerTurn)->getPieces();

  for (Piece *it : playerPieces) {
    if (!it->isCaptured())
      it->possibleMoves(moves);
  }

  for (vector<string>::iterator it = moves.begin(); it != moves.end();) {
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

void Movement::MoveGenerator::sortMoves(vector<string> &allmoves) {
  int value = 0;
  for (auto i : allmoves) {
    movement->movePiece(i);
    value = evaluateBoard();
    temp.insert({i, value});
    movement->undoLastMove();
  }

  if ((*movement->m_currentPlayerTurn)->getColorPieces() == "black") {
    std::set<std::pair<string, int>, cmpneg> setOfMoves(temp.begin(),
                                                        temp.end());
    allmoves.clear();
    // Iterate over a set using range base for loop
    // It will display the items in sorted order of values
    for (auto const &element : setOfMoves)
      allmoves.push_back(element.first);

  } else {
    std::set<std::pair<string, int>, cmp> setOfMoves(temp.begin(), temp.end());
    allmoves.clear();
    // Iterate over a set using range base for loop
    // It will display the items in sorted order of values
    //
    for (auto const &element : setOfMoves)
      allmoves.push_back(element.first);
  }
  temp.clear();
}

Movement::Move::Move() {}
Movement::Move::Move(string nextMove) { setNextMove(nextMove); }
Movement::Move::Move(Piece *piece, Piece *capturedPiece, Position start,
                     Position end)
    : from(start), to(end), piece(piece), capturedPiece(capturedPiece) {}
Movement::Move::~Move() {}

void Movement::Move::setNextMove(string playerInput) {
  vector<string> positions = scan(playerInput, std::regex("(\\w\\w)"));

  if (positions.size() == 2) {
    string from = positions[0], to = positions[1];
    fromPos.setPosition(from[0], from[1]);
    toPos.setPosition(to[0], to[1]);
    validInput = true;
  } else {
    validInput = false;
  }
}

vector<string> Movement::Move::scan(string str, const std::regex reg) {
  vector<string> results;
  std::smatch matches;
  while (std::regex_search(str, matches, reg)) {
    results.push_back(matches.str(1));
    str = matches.suffix().str();
  }

  return results;
}

Position Movement::Move::getPosFrom() { return fromPos; }
Position Movement::Move::getPosTo() { return toPos; }
bool Movement::Move::isValidInput() { return validInput; }
