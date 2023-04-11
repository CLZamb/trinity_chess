#include "board_view.h"
#include "game/players/player_position.h"

  // p_board_panes(
  //   std::make_unique<BoardPane>(
  //     _pane, b, m_board_section, m_squares_drawings
  //   )

BoardView::BoardView(BoardPane& b) : 
  m_board_pane(b) {
  add_middle_pane(&m_board_pane);
}

void BoardView::print() {
  Window::print();
}

void BoardView::update() {
  m_board_pane.update();
}

BoardView::~BoardView() {}

// string BoardView::get_next_string_move() {
//   bool is_complete = false;
//   string next_string_move;
//
//   do {
//     is_complete = p_board_input->get_next_string_move(next_string_move);
//     m_board_pane.update_board_drawing();
//     print();
//   } while(!is_complete);
//
//   return next_string_move;
// }

// void BoardView::add_pane_component(std::unique_ptr<BoardDecorator> &&pane) {
//   p_board_panes = std::move(pane);
// }
//
// unique_ptr<IUiPaneComponent>&& BoardView::get_pane_components() {
//   return std::move(p_board_panes);
// }
// void BoardView::add_right_pane(unique_ptr<BoardDecorator> &&pane) {
//   // add_right_pane(pane->get_pane());
//   // add_pane_component(std::move(pane));
// }
//
// void BoardView::add_left_pane(unique_ptr<BoardDecorator> &&pane) {
//   // add_left_pane(pane->get_pane());
//   // add_pane_component(std::move(pane));
// }
