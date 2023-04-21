#ifndef BOARD_INFO_H
#define BOARD_INFO_H

#include "game/turn/game_turn_observer.h"
#include "utils/string_utils.h"
#include <array>
#include <string>

using std::array;
using std::string;
using StringDrawingName::Pieces::bishop;
using StringDrawingName::Pieces::king;
using StringDrawingName::Pieces::knight;
using StringDrawingName::Pieces::pawn;
using StringDrawingName::Pieces::queen;
using StringDrawingName::Pieces::rook;

class BoardModelInfo : public GameTurnObserver {
public:
  BoardModelInfo();
  virtual ~BoardModelInfo();

  void update_info_turn(const PlayerInfo &e);
  void update_turn(const PlayerInfo &p) override;
  void save_move(const Move &move);
  void save_info(const string &info);

  string get_moves(Color c);
  string get_captures(Color c);
  string get_info();
  PlayerInfo get_player_info();

private:
  string get_piece_str_name_from_piecetype(Piecetype piece_type) {
    const unordered_map<Piecetype, string> piece_str_name{
        {bP, pawn},   {bR, rook},   {bN, knight}, {bB, bishop},
        {bQ, queen},  {bK, king},   {wP, pawn},   {wR, rook},
        {wN, knight}, {wB, bishop}, {wQ, queen},  {wK, king}};

    auto search = piece_str_name.find(piece_type);
    // check if the key exists
    if (search == piece_str_name.end())
      return "";

    return search->second;
  }
  string get_move_string(const Move &m);
  string get_captured_string(const Move &m);

  PlayerInfo m_player_info;
  static const size_t players_size = Color::SIZE;
  array<string, players_size> m_moves;
  array<string, players_size> m_captures;
  string m_info;
};

#endif /* BOARD_INFO_H */
