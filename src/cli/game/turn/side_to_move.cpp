#include "side_to_move.h"
#include <iostream>

SideToMove::SideToMove(Color &c) { set_inital_side(c); }

SideToMove::~SideToMove() {}

void SideToMove::change_side() {
  m_side = m_side == Color::WHITE ? Color::BLACK : Color::WHITE;

  notify_side();
}

void SideToMove::notify_side() {
  for (auto observer : *_observers) {
    observer->update_turn(m_side);
}
}

void SideToMove::set_inital_side(const Color &c) { m_side = c; }

Color SideToMove::get_color() { return m_side; }
