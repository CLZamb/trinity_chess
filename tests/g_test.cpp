#include <gmock/gmock.h>
#include "../include/board/board.h"
#include <gtest/gtest.h>

using namespace testing;

class Aboard : public testing::Test {
  public:
    Board board;
};

TEST_F(Aboard, IsEmptyWhenCreated) {
  ASSERT_THAT(board.is_checkmate(), Eq(false));
}

TEST_F(Aboard, CheckLegalMoves) {
  EXPECT_THAT(true, Eq(true));
}

// TEST_F(Aboard, CheckLegaRooklMoves) {
//   ASSERT_THAT(false, Eq(false));
// }

// TEST_F(Aboard, test) 
//   ASSERT_THAT(true, Eq(true));
