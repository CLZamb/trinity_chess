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

  m_board->setPieceAtPos(currentPiece, destination);
  m_board->getBoxAtPos(startPos)->removePiece();
  currentPiece->setCapturingState(false);
}

bool Movement::isValidMove(Position from, Position to) {
  if (!m_board->isValidPosition(from) || !m_board->isValidPosition(to))
    return false;

  Piece *currentPiece = m_board->getBoxAtPos(from)->getPiece();
  Box *destinationBox = m_board->getBoxAtPos(to);
  Player *opponent = (*m_currentPlayerTurn)->getOpponent();

  if (!currentPiece || !currentPiece->getOwner() || !opponent)
    return false;

  // check that the pieces being use belongs to the current player turn
  if (*m_currentPlayerTurn != currentPiece->getOwner()) {
    std::cout << "wrong player side\n";
    return false;
  }

  if (destinationBox->hasPiece()) {
    if (destinationBox->getPiece()->getOwner() == opponent)
      currentPiece->setCapturingState(true);
    else
      return false;
  }

  if (!currentPiece->checkMove(from, to))
    return false;

  if (!currentPiece->isKnight())
    if (hasCollision(from, to))
      return false;

  return true;
}

bool Movement::hasCollision(Position from, Position to) {
  int dx = abs(from.getPositionX() - to.getPositionX());
  int dy = abs(from.getPositionY() - to.getPositionY());
  Position temPos = from;
  int sign = 0;

  if (dx == 0 && dy > 0) {
    sign = (from.getPositionY() - to.getPositionY()) > 0 ? -1 : 1;
    for (int i = 1; i < dy; ++i) {
      std::cout << sign;
      std::cout << i << std::endl;
      temPos.setPositionY(from.getPositionY() + (sign * i));
      if (m_board->getBoxAtPos(temPos)->hasPiece())
        return true;
    }
  } else if (dx > 0 && dy == 0) {
    std::cout << "horizontal \n";
  } else if (dx > 0 && dy > 0) {
    std::cout << "diagonal \n";
  }

  return false;
}
