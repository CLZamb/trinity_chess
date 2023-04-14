#include "board_view.h"
#include "game/players/player_position.h"
#include <memory>

BoardView::BoardView() {}
BoardView::~BoardView() {}

void BoardView::print() { Window::print(); }
void BoardView::update() { p_panes->update(); }

void BoardView::add_board_pane(shared_ptr<BoardPane> board_pane) {
  Window::add_middle_pane(board_pane.get());
  p_panes = board_pane;
}

void BoardView::add_left_pane(shared_ptr<IUiPaneComponent> pane) {
  Window::add_left_pane(pane.get());
  p_panes = pane;
}

void BoardView::add_right_pane(shared_ptr<IUiPaneComponent> pane) {
  Window::add_right_pane(pane.get());
  p_panes = pane;
}

void BoardView::add_input_event_handler(shared_ptr<InputHandler> i) {
  p_input_handler = i;
}

bool BoardView::handle_input(KeyCode::Key e, string& callback) {
  if (!p_input_handler) return true;

  return p_input_handler->handle_event(e, callback);
}

