#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "board/position/position.h"

class AboardTA : public testing::Test {
  public:
    Position board;
};

TEST_F(AboardTA, IsEmptyTestCreated) {
  EXPECT_THAT(true, testing::Eq(true));
}

TEST_F(AboardTA, CheckLegalNMoves) {
  EXPECT_THAT(true, testing::Eq(true));
}
// TEST_F(Aboard, CheckLegaRooklMoves) {
// asfdk
//   ASSERT_THAT(false, Eq(false));
// }

// TEST_F(Aboard, test) 
//   ASSERT_THAT(true, Eq(true));
