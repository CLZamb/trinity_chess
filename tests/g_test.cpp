#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "board/check_move/board_check.h"
#include "board/position/position_fen.h"

// TESTS FEN
/// check that these checkmates are valid
// https://chessmood.com/blog/checkmate-patterns
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
  PositionFen m_position_fen;
  FenComponentParts m_fcp;
};

TEST_F(Aboard, IsfenComponentPartsCorrent) {
  std::string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

  m_position_fen.split_fen_into_its_component_parts(fen, m_fcp);

  ASSERT_THAT(m_fcp.board, "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
  ASSERT_THAT(m_fcp.side, "w");
  ASSERT_THAT(m_fcp.castle, "KQkq");
  ASSERT_THAT(m_fcp.en_passant, "-");
  ASSERT_THAT(m_fcp.halfmove, "0");
  ASSERT_THAT(m_fcp.fullmove, "1");
}

TEST_F(Aboard, IsCastlePermissionDataCorrect) {
  std::string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
  m_position_fen.split_fen_into_its_component_parts(fen, m_fcp);

  for (char c : m_fcp.castle) {
    m_position.set_castle_permission(c);
  }

  ASSERT_THAT(m_position.get_castling_rights_as_string(), "KQkq");
}

TEST_F(Aboard, IshalfMoveDataCorrect) {
  std::string half_move = "3";
  m_position.set_halfmoves(std::stoi(half_move));

  ASSERT_THAT(m_position.get_halfmoves_as_string(), half_move);
}

TEST_F(Aboard, IsFullMoveDataCorrect) {
  std::string full_move = "3";
  m_position.set_fullmoves(std::stoi(full_move));
  ASSERT_THAT(m_position.get_fullmoves_as_string(), full_move);
}

TEST_F(Aboard, IsEmptyWhenCreated) {
  std::string start_fen = "rnbqkbnr/pppppppp/8/8/P7/8/1PPPPPPP/RNBQKBNR b KQkq a3 0 1";
  m_position_fen.parse_fen(start_fen, m_position);
  ASSERT_THAT(m_position_fen.get_fen(m_position), start_fen);
}

TEST_F(Aboard, IsFenValid) {
  std::array<std::string, 6> test_cases {
    "4k3/8/8/4pP2/8/8/8/4K2R w - e6 0 1",
    "r3k3/ppp5/8/8/8/8/5PPP/4K2R w Kq - 0 0",
    "k1R5/8/2Q5/8/1q6/2r5/8/K7 b - - 0 1",
    "3kq2r/8/8/8/8/8/8/3K1Q2 w - - 0 1",
    "2Q5/k7/8/2R5/7r/7r/8/K7 b - - 0 1",
    "6k1/5Q2/8/8/8/8/7R/6K1 b - - 0 1",
  };

  for (std::string test_case : test_cases) {
    m_position_fen.split_fen_into_its_component_parts(test_case, m_fcp);
    ASSERT_THAT(m_fcp.are_valid_fen_componet_pars(),  true);
  }

  std::array<std::string, 7> test_fail_cases {
    "4k3/8/8/4pP2/8/8/8/4K2R w - e9 0 1",
    "r3k3/ppp5/8/8/8/8/5PPP/4K2R m - e6 0 1",
    "r3k3/p/8/8/8/5PpPP/4K2R w Kq - 0",
    "k1R5/89/2Q5/8/1q6/2r5/8/K7 b - - 0 1",
    "3kq2r/j8/8/8/8/8/8/3K1Q2 w - - 0 1",
    "2Q5/k99/8/2R5/7r/7r/8/K7 b - - 0 1",
    "6k1/5Q2/8/8/8/8/7R/6K1 b - - 0 m",
  };

  for (std::string fail_test_case : test_fail_cases) {
    m_position_fen.split_fen_into_its_component_parts(fail_test_case, m_fcp);
    ASSERT_FALSE(m_fcp.are_valid_fen_componet_pars() == true);
  }
}
