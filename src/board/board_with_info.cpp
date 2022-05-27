#include "headers/board_with_info.h"

BoardWithInfo::BoardWithInfo() {
  m_info._init();
}
BoardWithInfo::~BoardWithInfo() {}

void BoardWithInfo::make_move(Move m) {
  save_move(m);
  save_capture(m);
  m_board.make_move(m);
}

void BoardWithInfo::save_move(const Move& m) {
  m_info.save_move(get_str_moves(m));
}

void BoardWithInfo::save_capture(const Move& m) {
  Piece* captured = m_board.get_piece_at_square(m.get_to());
  if (captured) {
    m_info.save_capture(
        utils::get_piece_str_name_from_piecetype(
          captured->get_type_and_color()));
  }
}

string BoardWithInfo::get_str_moves(const Move& m) {
  string from = utils::square_int_to_str(m.get_from());
  string to = utils::square_int_to_str(m.get_to());
  return from + to;
}

void BoardWithInfo::update_turn(GameTurn::players turn) {
  m_info.update_turn(turn);
  m_info.save_game_info(get_turn_info(turn));
}

Displayable* BoardWithInfo::get_board_drawing() {
  return m_board.get_drawing();
}

Displayable* BoardWithInfo::get_info_drawing() {
  return &m_info;
}

string BoardWithInfo::get_turn_info(players turn) {
  bool is_player_1_turn = (turn == GameTurn::player_1);
  string info;

  info += is_player_1_turn ? "white" : "black";
  info += " to move - (player ";
  info += is_player_1_turn ? "1" : "2";
  info += ")";
  return info;
}

void BoardWithInfo::update_game_info(const string& info) {
  m_info.save_game_info(info);
}

bool BoardWithInfo::is_checkmate() {
  return m_board.is_checkmate();
}

bool BoardWithInfo::is_legal_move(std::shared_ptr<Player> turn, Move& m) {
  return m_board.is_legal_move(turn, m);
}

