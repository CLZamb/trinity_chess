#include "position_fen.h"

PositionFen::PositionFen() {}

void PositionFen::split_fen_into_its_component_parts(const std::string &str_fen, FenComponentParts& fcp) {
  std::istringstream ss(str_fen);

  std::getline(ss, fcp.board, ' ');
  std::getline(ss, fcp.side, ' ');
  std::getline(ss, fcp.castle, ' ');
  std::getline(ss, fcp.en_passant, ' ');
  std::getline(ss, fcp.halfmove, ' ');
  std::getline(ss, fcp.fullmove, ' ');
}

void PositionFen::parse_fen(const std::string &str_fen, Position &position) {
  position.clear();

  FenComponentParts fcp_as_strs;
  split_fen_into_its_component_parts(str_fen, fcp_as_strs);

  assert(fcp_as_strs.are_valid_fen_componet_pars());

  Square square = A1;
  int rank = 7, file = 0;
  Piece piece;

  for (char c : fcp_as_strs.board) {
    if (c == '/') {
      rank--;
      file = 0;
      continue;
    }
    if (isdigit(c)) {
      file += (c - '0');
    } else {   // is piece
      piece = utils::get_piecetype_from_char_key(c);
      square = static_cast<Square>(rank * 8 + file);
      position.set_piece_at_square(piece, square);
      file++;
    }
  }

  position.set_side_to_move(fcp_as_strs.side == "w" ? Color::WHITE
                                                    : Color::BLACK);

  for (char c : fcp_as_strs.castle) {
    position.set_castle_permission(c);
  }

  if (fcp_as_strs.en_passant[0] != '-') {
    file = fcp_as_strs.en_passant[0] - 'a';
    rank = fcp_as_strs.en_passant[1] - '1';
    square = static_cast<Square>(rank * 8 + file);
    position.set_en_passant_square(square);
  }

  if (!fcp_as_strs.halfmove.empty()) {
    position.set_halfmoves(std::stoi(fcp_as_strs.halfmove));
  }

  if (!fcp_as_strs.fullmove.empty()) {
    position.set_fullmoves(std::stoi(fcp_as_strs.fullmove));
  }
};

std::string PositionFen::get_fen(Position &position) {
  std::string fen{""};
  Piece piece{EMPTY};
  int space{0};

  for (int rank = 7; rank >= 0; rank--) {
    for (int file = 0; file <= 7; file++) {
      piece =
          position.get_piece_at_square(static_cast<Square>(rank * 8 + file));
      if (piece) {
        add_empty_space(fen, space);
        fen += utils::piecetype_to_char(piece);
      } else {
        space++;
      }
    }

    add_empty_space(fen, space);

    if (rank > 0) {
      fen += "/";
    }
  }

  fen += ' ';
  fen += position.get_side_turn_as_char();
  fen += ' ';
  fen += position.get_castling_rights_as_string();
  fen += ' ';
  fen += position.get_en_passant_square_as_string();
  fen += ' ';
  fen += position.get_halfmoves_as_string();
  fen += ' ';
  fen += position.get_fullmoves_as_string();

  return fen;
}

void PositionFen::add_empty_space(std::string &f, int &space) {
  if (space) {
    f += std::to_string(space);
  }
  space = 0;
}
