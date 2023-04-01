#ifndef BOARD_DRAWINGS_H
#define BOARD_DRAWINGS_H

// #include "graphics/components/box.h"
#include "box.h"
#include "string_utils.h"

namespace BoardDrawings {
namespace Pieces {

static const std::unordered_map<std::string, Box> Kpieces = {
  {
    StringDrawingName::Pieces::bishop, {{
       "   ▗◘▖   ",
       "   ▚/▞   ",
       "    █    ",
       "   ▟█▙   ",
       "         ",
     }}
  },
  {
    StringDrawingName::Pieces::king,
    {{
       "  ▁ ✜ ▁  ",
       " ( ╲|╱ ) ",
       "  ╲███╱  ",
       " [█████] ",
       "         ",
     }}
  },
  {
    StringDrawingName::Pieces::knight,
    {{
       "         ",
       "   █ █   ",
       "  ████   ",
       "   ███   ",
       "         ",
     }}
  },
  {
    StringDrawingName::Pieces::pawn,
    {{
       "   ▗▄▖   ",
       "   ▜█▛   ",
       "   ▗█▖   ",
       "  ▗███▖  ",
       "         ",
     }}
  },
  {
    StringDrawingName::Pieces::queen,
    {{
       "         ",
       "  █ █ █  ",
       "  █████  ",
       "  █████  ",
       "         ",
     }}
  },
  {
    StringDrawingName::Pieces::rook,
    {{
       "  ▄ ▄ ▄  ",
       "  ▜███▛  ",
       "   ███   ",
       " ▄█████▄ ",
       "         ",
     }}
  },
};
}

namespace Squares {
static const std::unordered_map<std::string, Box> Ksquares = {
  {
    StringDrawingName::Square::white_square,
    {{
       "\033[38;5;251m█████████\033[0m",
       "\033[38;5;252m█████████\033[0m",
       "\033[38;5;253m█████████\033[0m",
       "\033[38;5;254m█████████\033[0m",
       "\033[38;5;255m█████████\033[0m",
     }}
  },
  {
    StringDrawingName::Square::black_square,
    {{
       "\033[38;5;233m█████████\033[0m",
       "\033[38;5;234m█████████\033[0m",
       "\033[38;5;235m█████████\033[0m",
       "\033[38;5;236m█████████\033[0m",
       "\033[38;5;237m█████████\033[0m",
     }}
  },
};
}
}

#endif /* BOARD_DRAWINGS_H */
