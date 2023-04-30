#ifndef FEN_COMPONENT_PARTS_H
#define FEN_COMPONENT_PARTS_H

#include <cassert>
#include <string>

struct FenComponentParts {
  std::string board;
  std::string side;
  std::string castle;
  std::string en_passant;
  std::string halfmove;
  std::string fullmove;


  bool are_valid_fen_component_parts() {
  int piece_count = 0;
  int ranks_sum = 0;
  int slash_count = 0;

  for (char &c : board) {
    if (c >= '1' && c <= '8') {
      ranks_sum += c - '0';
    } else if (c == '/') {
      slash_count++;
    } else if (!(c == 'K' || c == 'k' || c == 'Q' || c == 'q' || c == 'R' ||
                 c == 'r' || c == 'B' || c == 'b' || c == 'N' || c == 'n' ||
                 c == 'P' || c == 'p')) {
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
    (en_passant.size() != 2 || en_passant[0] < 'a' ||
    en_passant[0] > 'h' || en_passant[1] < '1' || en_passant[1] >
    '8')) { return false;
  }


  if (!isdigit(halfmove[0])) {
    return false;
  }

  if (!isdigit(fullmove[0])) {
    return false;
  }

  return true;
  }

};

#endif /* FEN_COMPONENT_PARTS_H */
