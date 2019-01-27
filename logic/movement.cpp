#include "movement.h"

Movement::Movement(Board *board, Player **turn)
    : m_board(board), m_currentPlayerTurn(turn) {}

Movement::~Movement() {}

void Movement::movePiece(Position startPos, Position destination) {
  Piece *currentPiece = m_board->getPieceAtPos(startPos);

  if (!currentPiece) {
    std::cout << "there is no piece at position " << startPos.getPositionX()
              << " , " << startPos.getPositionY() << std::endl;
    return;
  }

  Piece *capturedPiece = m_board->getSquareAtPos(destination)->removePiece();
  if (capturedPiece) {
    if (capturedPiece->getPieceType() == "king")
      checkmate = true;

    m_board->saveCapturedPiece(capturedPiece);
  }

  m_board->setPieceAtPos(currentPiece, destination);
  m_board->getSquareAtPos(startPos)->clearSquare();
}

bool Movement::isValidMove(Position from, Position to) {
  if (!m_board->isValidPosition(from) || !m_board->isValidPosition(to))
    return false;

  Piece *currentPiece = m_board->getSquareAtPos(from)->getPiece();
  Square *destinationSquare = m_board->getSquareAtPos(to);
  Player *opponent = (*m_currentPlayerTurn)->getOpponent();

  if (!currentPiece || !currentPiece->getOwner() || !opponent)
    return false;

  // check that the pieces being use belongs to the current player turn
  if (*m_currentPlayerTurn != currentPiece->getOwner()) {
    std::cout << "Piece at that position does not belong the current player\n";
    return false;
  }

  if (destinationSquare->hasPiece()) {
    if (destinationSquare->getPiece()->getOwner() == opponent)
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

  int dirY = (fromY - toY) > 0 ? -1 /*down*/ : 1 /*up*/;
  int dirX = (fromX - toX) > 0 ? -1 /*left*/ : 1 /*right*/;

  Position temPos = from;

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
/*
 * moveGenerator(board, list)
 *  loop all pieces
 *    -> Slider loop each dir add move
 *      -> addMove list->moves[list->count] = move; list->count++;
 * */
void Movement::generateMove() {}
