#include "headers/board_with_info.h"

BoardWithInfo::BoardWithInfo(Board* board, Savable* info) : p_board(board), p_info(info) {}
BoardWithInfo::~BoardWithInfo() {}

void BoardWithInfo::make_move(Move m) {
  string from = utils::square_int_to_str(m.get_from());
  string to = utils::square_int_to_str(m.get_to());

  Piece* captured = p_board->get_piece_at_square(m.get_to());

  p_board->make_move(m);
  p_info->save_moves(from + to);

  if (captured) {
    p_info->save_captures(
        utils::get_piece_str_name_from_piecetype(
          captured->get_type_and_color()));
  }
}

void BoardWithInfo::update_turn(GameTurn::players turn) {
  string info;
  info += p_board->get_turn()->get_str_color_pieces();
  info += " to move - (player ";
  info += (turn == GameTurn::player_2) ? "2" : "1";
  info += ")";

  p_info->save_game_info(info);
}
