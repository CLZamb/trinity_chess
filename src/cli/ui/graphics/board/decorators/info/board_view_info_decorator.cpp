#include "board_view_info_decorator.h"

BoardViewInfoDecorator::BoardViewInfoDecorator(unique_ptr<IUIBoard> &&b, BoardView &bv,
                                       BoardModelInfo &i)
    : BoardDecorator(std::move(b)), p_info(i) {
  bv.add_right_pane(&m_info_pane);
}

BoardViewInfoDecorator::~BoardViewInfoDecorator() {}

void BoardViewInfoDecorator::print() { BoardDecorator::print(); }

void BoardViewInfoDecorator::update() {
  m_info_pane.update_game_info(p_info.get_info());
  m_info_pane.update_banner(p_info.get_player_info().color);

  for (Color c : {Color::WHITE, Color::BLACK}) {
    m_info_pane.update_moves(p_info.get_moves(c), c);
    m_info_pane.update_captures(p_info.get_captures(c), c);
  }

  BoardDecorator::update();
}
