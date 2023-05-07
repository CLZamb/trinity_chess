#ifndef FEN_FIELDS_H
#define FEN_FIELDS_H

#include <cassert>
#include <sstream>

struct FenFields {
  std::string piece_placement;
  std::string side_to_move;
  std::string castling_ability;
  std::string en_passant_target_square;
  std::string halfmove_clock;
  std::string fullmove_counter;

  FenFields() = default;

  explicit FenFields(const std::string &str_fen) {
    split_fen_into_its_fields(str_fen);
  }

  void split_fen_into_its_fields(const std::string &str_fen) {
    std::istringstream ss(str_fen);

    std::getline(ss, piece_placement, ' ');
    std::getline(ss, side_to_move, ' ');
    std::getline(ss, castling_ability, ' ');
    std::getline(ss, en_passant_target_square, ' ');
    std::getline(ss, halfmove_clock, ' ');
    std::getline(ss, fullmove_counter, ' ');
    assert(are_fen_fields_valid());
  }

  bool are_fen_fields_valid() {
    int piece_count = 0;
    int ranks_sum = 0;
    int slash_count = 0;

    std::string possible_pieces_char_value = "KkQqRrBbNnPp";

    for (char &c : piece_placement) {
      if (c >= '1' && c <= '8') {
        ranks_sum += c - '0';
      } else if (c == '/') {
        slash_count++;
      } else if (is_char_an_invalid_piece_char(c)) {
        return false;
      } else {   // piece
        piece_count++;
        ranks_sum++;
      }
    }

    if (ranks_sum != 64 || piece_count > 32 || slash_count != 7) {
      return false;
    }

    if (side_to_move != "w" && side_to_move != "b") {
      return false;
    }

    // Check that the castling part of the FEN string is valid
    if (castling_ability[0] != '-' &&
        (castling_ability.find_first_not_of("KQkq") != std::string::npos ||
         castling_ability.size() > 4)) {
      return false;
    }

    // Check that the en passant square part of the FEN string is valid
    if (en_passant_target_square != "-" &&
        (en_passant_target_square.size() != 2 ||
         en_passant_target_square[0] < 'a' ||
         en_passant_target_square[0] > 'h' ||
         en_passant_target_square[1] < '1' ||
         en_passant_target_square[1] > '8')) {
      return false;
    }

    if (!isdigit(halfmove_clock[0])) {
      return false;
    }

    if (!isdigit(fullmove_counter[0])) {
      return false;
    }

    return true;
  }

 private:
  bool is_char_an_invalid_piece_char(const char &c) {
    static const std::string possible_pieces_char_value = "KkQqRrBbNnPp";
    return possible_pieces_char_value.find(c) == std::string::npos;
  }
};

#endif /* FEN_FIELDS_H */
