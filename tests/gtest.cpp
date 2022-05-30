#include <gmock/gmock.h>
#include "../src/board/headers/board.h"
#include "../src/player/headers/players.h"
#include "../src/game/headers/move_utils.h"

using namespace testing;

class Aboard : public testing::Test {
  public:
    // Board board;
};

TEST_F(Aboard, IsEmptyWhenCreated) {
  // ASSERT_THAT(board.is_checkmate(), Eq(false));
}

// TEST_F(Aboard, CheckLegalMoves) {
//   Players players;
//   players.create_players({Player::Human, Player::Human});
//   Move m = String::to_move("a2a3");
//   ASSERT_THAT(board.is_legal_move(players.get_player_1(), m), Eq(true));
//   m = String::to_move("a2a4");
//   ASSERT_THAT(board.is_legal_move(players.get_player_1(), m), Eq(true));
//   m = String::to_move("h2f3");
//   ASSERT_THAT(board.is_legal_move(players.get_player_1(), m), Eq(false));
// }
//
// TEST_F(Aboard, CheckLegaRooklMoves) {
//   board.parser_fen("r111111r/11111111/8/8/8/8/11111111/R111111R");
//   Players players;
//   players.create_players({Player::Human, Player::Human});
//   Move m = String::to_move("a1a3");
//   ASSERT_THAT(board.is_legal_move(players.get_player_1(), m), Eq(true));
// }
//


