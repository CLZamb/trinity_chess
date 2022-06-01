#include "headers/player.h"

Player::Player(Color color) : m_color(color) {}
Player::~Player() {}

bool Player::has_black_pieces() { return m_color == BLACK; }
const string &Player::get_input() {  return m_input; }
