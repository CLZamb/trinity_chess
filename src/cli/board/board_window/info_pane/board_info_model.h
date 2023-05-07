#ifndef BOARD_INFO_MODEL_H
#define BOARD_INFO_MODEL_H

#include <array>
#include <string>

#include "game/turn/game_turn_observer.h"
#include "utils/string_utils.h"

class BoardModelInfo {
 public:
  BoardModelInfo();
  virtual ~BoardModelInfo();

  void update_side(const Color &p);
  void save_move(const Move &m);
  void save_capture(const Move &m);
  void save_info(const std::string &info);

  std::string get_moves(Color c);
  std::string get_captures(Color c);
  std::string get_info();
  Color get_side_to_move_color();

 private:
  std::string get_piece_str_name_from_piecetype(Piece piece_type) {
    const std::unordered_map<Piece, std::string> piece_str_name{
        {bP, StringDrawingName::Pieces::pawn},
        {bR, StringDrawingName::Pieces::rook},
        {bN, StringDrawingName::Pieces::knight},
        {bB, StringDrawingName::Pieces::bishop},
        {bQ, StringDrawingName::Pieces::queen},
        {bK, StringDrawingName::Pieces::king},
        {wP, StringDrawingName::Pieces::pawn},
        {wR, StringDrawingName::Pieces::rook},
        {wN, StringDrawingName::Pieces::knight},
        {wB, StringDrawingName::Pieces::bishop},
        {wQ, StringDrawingName::Pieces::queen},
        {wK, StringDrawingName::Pieces::king}};

    auto search = piece_str_name.find(piece_type);
    // check if the key exists
    if (search == piece_str_name.end()) {
      return "";
    }

    return search->second;
  }
  std::string get_move_string(const Move &m);
  std::string get_captured_string(const Move &m);

  Color m_side;
  static const size_t players_size = Color::SIZE;
  std::array<std::string, players_size> m_moves;
  std::array<std::string, players_size> m_captures;
  std::string m_info;
};

#endif /* BOARD_INFO_MODEL_H */
