#include "player.h"

Player::Player(std::string c) : m_colorPieces(c) {}
Player::~Player() {
  for (Piece *iter : m_pieces) {
    delete iter;
  }
  m_pieces.clear();
}

std::string Player::getPlayerNextMove() {
  std::string input;
  std::cout << "move piece ie: (a7 a6), to end the game type "
               "\"close, quite or exit\""
            << "\nis player " << this->m_colorPieces << " turn"
            << "\n>> ";
  std::getline(std::cin, input);
  return input;
}

void Player::setPieces(PiecesSetPtr pieces) { this->m_pieces = pieces; }
PiecesSetPtr Player::getPieces() { return m_pieces; }
