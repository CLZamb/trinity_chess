#include "headers/player.h"

Player::Player(Color color) : color(color) {
  m_black_pieces = color;
  color_str = utils::get_color_str_from_color(color);
}

Player::~Player() {}

void Player::set_opponent(std::shared_ptr<Player> opponent) {
  this->p_opponent = opponent;
}

bool Player::has_black_pieces() { return m_black_pieces; }
std::shared_ptr<Player> Player::get_opponent() { return p_opponent; }

