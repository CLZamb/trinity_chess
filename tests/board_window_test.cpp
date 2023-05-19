#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "board/board_window/board_window.h"
#include "input/input_components.h"
#include "board/board_window/board_components.hpp"

namespace IC = InputComponents;
namespace BC = BoardComponents;
// TESTS FEN
/// check that these checkmates are valid
// https://chessmood.com/blog/checkmate-patterns

class Aboard : public testing::Test {
 public:
  BoardWindow m_board_window;
};


TEST_F(Aboard, IsTypeIdEqual) {
  BoardConfigInfo m_info;
  m_info.fen_fields = FenFields("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
  m_info.initial_side = Color::WHITE;
  m_info.input_type = InputType::Keyboard;

  auto input = IC::new_input_board(InputType::Keyboard);
  auto board_pane = BC::new_board_pane(m_board_window, m_info, input);
  
  // build_side_pane(board_config.left_pane);
  // build_side_pane(board_config.right_pane);

  m_board_window.add_input(std::move(input));
  m_board_window.update();
  Move m;
  m = MoveUtils::make_move(A2, A3, bP);
  m_board_window.make_move(m);
  m_board_window.print();
}


