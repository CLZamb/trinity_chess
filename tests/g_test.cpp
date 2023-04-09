#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "board/board_representation/board.h"
#include "board/check_move/board_check.h"
#include "board/fen/board_fen.h"

using namespace testing;

class Aboard : public testing::Test {
 public:
  Board board;
  BoardCheck board_check{board};
  BoardFen m_board_fen{board, "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"};
};
/// check that these checkmates are valid
// https://chessmood.com/blog/checkmate-patterns
TEST_F(Aboard, IsEmptyWhenCreated) {
  ASSERT_THAT(board_check.is_checkmate(), Eq(false));
}

TEST_F(Aboard, CheckLegalMoves) {
  EXPECT_THAT(true, Eq(true));
}

// TEST_F(Aboard, CheckLegaRooklMoves) {
//   ASSERT_THAT(false, Eq(false));
// }

// TEST_F(Aboard, test) 
//   ASSERT_THAT(true, Eq(true));
