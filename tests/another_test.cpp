#include <gmock/gmock.h>
#include "../src/board/headers/board.h"
#include <gtest/gtest.h>
// #include "../src/game/headers/string_utils.h"
// #include "gtest/gtest.h"

using namespace testing;

class AboardTA : public testing::Test {
  public:
    Board board;
};

TEST_F(AboardTA, IsEmptyTestCreated) {
  ASSERT_THAT(board.is_checkmate(), Eq(false));
}

TEST_F(AboardTA, CheckLegalNMoves) {
  EXPECT_THAT(true, Eq(true));
}

// TEST_F(Aboard, CheckLegaRooklMoves) {
//   ASSERT_THAT(false, Eq(false));
// }

// TEST_F(Aboard, test) 
//   ASSERT_THAT(true, Eq(true));
