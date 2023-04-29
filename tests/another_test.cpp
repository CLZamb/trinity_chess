#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "board/board_representation/position.hpp"

using namespace testing;

class AboardTA : public testing::Test {
  public:
    Position board;
};

TEST_F(AboardTA, IsEmptyTestCreated) {
  EXPECT_THAT(true, Eq(true));
}

TEST_F(AboardTA, CheckLegalNMoves) {
  EXPECT_THAT(true, Eq(true));
}

// TEST_F(Aboard, CheckLegaRooklMoves) {
//   ASSERT_THAT(false, Eq(false));
// }

// TEST_F(Aboard, test) 
//   ASSERT_THAT(true, Eq(true));
