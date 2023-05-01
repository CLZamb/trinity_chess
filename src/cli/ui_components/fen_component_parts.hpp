#ifndef FEN_COMPONENT_PARTS_H
#define FEN_COMPONENT_PARTS_H

#include <cassert>
#include <sstream>

struct FenComponentParts {
  std::string board;
  std::string side;
  std::string castle;
  std::string en_passant;
  std::string halfmove;
  std::string fullmove;

  FenComponentParts() {}

  explicit FenComponentParts(const std::string &str_fen) {
    split_fen_into_its_component_parts(str_fen);
  }

  void split_fen_into_its_component_parts(const std::string &str_fen) {
    std::istringstream ss(str_fen);

    std::getline(ss, board, ' ');
    std::getline(ss, side, ' ');
    std::getline(ss, castle, ' ');
    std::getline(ss, en_passant, ' ');
    std::getline(ss, halfmove, ' ');
    std::getline(ss, fullmove, ' ');

    assert(are_valid_fen_component_parts());
  }

  bool is_char_a_valid_piece_char(const char& c) {
    static const std::string possible_pieces_char_value = "KkQqRrBbNnPp";
    return possible_pieces_char_value.find(c) == std::string::npos;
  }

  bool are_valid_fen_component_parts() {
    int piece_count = 0;
    int ranks_sum = 0;
    int slash_count = 0;

    std::string possible_pieces_char_value = "KkQqRrBbNnPp";

    for (char &c : board) {
      if (c >= '1' && c <= '8') {
        ranks_sum += c - '0';
      } else if (c == '/') {
        slash_count++;
      } else if (is_char_a_valid_piece_char(c)) {
        return false;
      } else {
        piece_count++;
        ranks_sum++;
      }
    }

    if (ranks_sum != 64 || piece_count > 32 || slash_count != 7) {
      return false;
    }

    if (side != "w" && side != "b") {
      return false;
    }

    // Check that the castling part of the FEN string is valid
    if (castle[0] != '-' &&
        (castle.find_first_not_of("KQkq") != std::string::npos ||
         castle.size() > 4)) {
      return false;
    }

    // Check that the en passant square part of the FEN string is valid
    if (en_passant != "-" &&
        (en_passant.size() != 2 || en_passant[0] < 'a' || en_passant[0] > 'h' ||
         en_passant[1] < '1' || en_passant[1] > '8')) {
      return false;
    }

    if (!isdigit(halfmove[0])) {
      return false;
    }

    if (!isdigit(fullmove[0])) {
      return false;
    }

    return true;
  }

 private:
};

#endif /* FEN_COMPONENT_PARTS_H */
