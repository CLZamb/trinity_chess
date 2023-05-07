#include "position_fen.h"

#include "ui_components/fen_fields.hpp"

PositionFen::PositionFen(const FenFields &fen, Position &position) {
  parse_fen(fen, position);
}

void PositionFen::parse_fen(const FenFields &fen_fields, Position &position) {
  position.clear();
  Square square = A1;
  int rank = 7, file = 0;
  Piece piece;

  for (char c : fen_fields.piece_placement) {
    if (c == '/') {
      rank--;
      file = 0;
      continue;
    }
    if (isdigit(c)) {
      file += (c - '0');
    } else {   // is piece
      piece = utils::get_piecetype_from_char(c);
      square = static_cast<Square>(rank * 8 + file);
      position.set_piece(piece, square);
      file++;
    }
  }

  position.set_side_to_move(fen_fields.side_to_move == "w" ? Color::WHITE
                                                           : Color::BLACK);

  for (char c : fen_fields.castling_ability) {
    position.set_castle_permission(c);
  }

  if (fen_fields.en_passant_target_square[0] != '-') {
    file = fen_fields.en_passant_target_square[0] - 'a';
    rank = fen_fields.en_passant_target_square[1] - '1';
    square = static_cast<Square>(rank * 8 + file);
    position.set_en_passant_square(square);
  }

  position.set_halfmoves(std::stoi(fen_fields.halfmove_clock));
  position.set_fullmoves(std::stoi(fen_fields.fullmove_counter));
};

Square PositionFen::make_sq(int& rank, int file) {
  return static_cast<Square>((rank * 8) + file);
}

std::string PositionFen::get_fen(Position &pos) {
  std::string fen{""};
  Piece piece{EMPTY};
  int space{0};

  for (int rank = 7; rank >= 0; rank--) {
    for (int file = 0; file <= 7; file++) {
      piece = pos.get_piece(make_sq(rank, file));
      if (piece) {
        add_empty_space(fen, space);
        fen += utils::piecetype_to_char(piece);
      } else {
        space++;
      }
    }

    add_empty_space(fen, space);

    if (rank > 0) { fen += "/"; }
  }

  fen += ' ' + pos.get_side_turn_as_char();
  fen += ' ' + pos.get_castling_rights_as_string();
  fen += ' ' + pos.get_en_passant_square_as_string();
  fen += ' ' + pos.get_halfmoves_as_string();
  fen += ' ' + pos.get_fullmoves_as_string();
  return fen;
}

void PositionFen::add_empty_space(std::string &f, int &space) {
  if (space) { f += std::to_string(space); }
  space = 0;
}
