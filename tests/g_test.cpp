#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "board/check_move/board_check.h"
#include "board/position/position_fen.h"
#include "ui_components/fen_fields.hpp"

// TESTS FEN
/// check that these checkmates are valid
// https://chessmood.com/blog/checkmate-patterns

class Aboard : public testing::Test {
 public:
  Position m_position;
  PositionFen m_position_fen;
  FenFields m_fen_fields;
};

TEST_F(Aboard, IsfenComponentPartsCorrent) {
  std::string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

  m_fen_fields.split_fen_into_its_fields(fen);

  ASSERT_THAT(m_fen_fields.piece_placement, "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
  ASSERT_THAT(m_fen_fields.side_to_move, "w");
  ASSERT_THAT(m_fen_fields.castling_ability, "KQkq");
  ASSERT_THAT(m_fen_fields.en_passant_target_square, "-");
  ASSERT_THAT(m_fen_fields.halfmove_clock, "0");
  ASSERT_THAT(m_fen_fields.fullmove_counter, "1");
}

TEST_F(Aboard, IsCastlePermissionDataCorrect) {
  std::string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
  m_fen_fields.split_fen_into_its_fields(fen);

  for (char c : m_fen_fields.castling_ability) {
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
  FenFields fen_fields(start_fen);
  m_position_fen.parse_fen(fen_fields, m_position);
  ASSERT_THAT(m_position_fen.get_fen(m_position), start_fen);
  ASSERT_THAT(m_position_fen.get_fen(m_position), start_fen);
}

TEST_F(Aboard, AreValidFields) {
  const std::array<std::string, 7> fen_tests = {
    "4k3/8/8/4pP2/8/8/8/4K2R w - e6 0 1",
    "4k3/8/8/4pP2/8/8/8/4K2R w - e6 0 1",
    "r3k3/ppp5/8/8/8/8/5PPP/4K2R w Kq - 0",
    "k1R5/8/2Q5/8/1q6/2r5/8/K7 b - - 0 1",
    "3kq2r/8/8/8/8/8/8/3K1Q2 w - - 0 1",
    "2Q5/k7/8/2R5/7r/7r/8/K7 b - - 0 1",
    "6k1/5Q2/8/8/8/8/7R/6K1 b - - 0 1",
  };

  for (const std::string& fen_test: fen_tests) {
    m_fen_fields.split_fen_into_its_fields(fen_test);
    ASSERT_THAT(m_fen_fields.are_fen_fields_valid(), testing::Eq(true));
  }

  const std::array<std::string, 7> fen_failed_tests = {
    "xk3/8/8/4pP2/8/8/8/4K2R w - e6 0 1",
    "4k3x8/8/4pP2/8/8/8/4K2R w - e6 0 1",
    "r3k3/ppp5/8/8/8/8/5PPP/4K2R x Kq - 0",
    "k1R5/8/2Q5/8/1q6/2r5/8/K7 b - x 0 1",
    "3kq2r/8/8/8/8/8/8/3K1Q2 w - - x 1",
    "2Q5/k7/8/2R5/7r/7r/8/K7 b - - 0 x",
    "xxxxxxxxxxxxxxxxxxxxxxx x x x x xx",
  };

  for (const std::string& fen_test: fen_failed_tests) {
    ASSERT_DEATH(m_fen_fields.split_fen_into_its_fields(fen_test), "");
  }
}
