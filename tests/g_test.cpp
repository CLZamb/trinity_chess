#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "board/check_move/board_check.h"
#include "board/fen/fen_model.hpp"

using namespace testing;

// TESTS FEN
// const string start_fen = "4k3/8/8/4pP2/8/8/8/4K2R w - e6 0 1";
// const string start_fen = "4k3/8/8/4pP2/8/8/8/4K2R w - e6 0 1";
// const string start_fen = "r3k3/ppp5/8/8/8/8/5PPP/4K2R w Kq - 0";
// const string start_fen = "k1R5/8/2Q5/8/1q6/2r5/8/K7 b - - 0 1";
// const string start_fen = "3kq2r/8/8/8/8/8/8/3K1Q2 w - - 0 1";
// const string start_fen = "2Q5/k7/8/2R5/7r/7r/8/K7 b - - 0 1";
// const string start_fen = "6k1/5Q2/8/8/8/8/7R/6K1 b - - 0 1";

class Aboard : public testing::Test {
 public:
  Position m_position;
  BoardCheck board_check{m_position};
  BoardFen m_board_fen;
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
