#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "board/board_window/board_window.h"
#include "input/input_components.h"

// TESTS FEN
/// check that these checkmates are valid
// https://chessmood.com/blog/checkmate-patterns

class Aboard : public testing::Test {
 public:
  BoardWindow m_board_window;
};


TEST_F(Aboard, IsTypeIdEqual) {
  std::unique_ptr<Input> input = InputComponents::new_input_keyboard();

  ASSERT_TRUE(dynamic_cast<KeyboardInput*>(input.get()));
  ASSERT_TRUE(dynamic_cast<TextInput*>(input.get()));
  // ASSERT_TRUE(typeid(input) == typeid(KeyboardInput));
  // ASSERT_TRUE(typeid(input.get()) == typeid(TextInput));
}
