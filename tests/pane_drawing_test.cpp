#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "board/board_window/board_pane/board_drawings.hpp"
#include "board/board_window/board_pane/board_pane.h"
#include "board/check_move/board_check.h"
#include "board/position/position_fen.h"
#include "ui_components/box_modifier.hpp"
#include "ui_components/fen_fields.hpp"

// TESTS FEN
/// check that these checkmates are valid
// https://chessmood.com/blog/checkmate-patterns

class Aboard : public testing::Test {
 public:
  Box m_squares_drawings;
};

void print_box(const Box& b) {
  for (int i = 0; i < Box::kRowSize; ++i) {
    std::cout << b.content[i] << "\n";
  }
}

TEST_F(Aboard, IsDrawingBeingApplied) {
  m_squares_drawings = BoardDrawings::Pieces::Kpieces.at(PieceType::QUEEN);
}
