#ifndef BOARD_DRAWINGS_H
#define BOARD_DRAWINGS_H
#pragma once

#include "components/box.h"
#include "utils/string_utils.h"

namespace BoardDrawings {
namespace Pieces {

static const std::unordered_map<PieceType, Box> Kpieces = {
    {PieceType::BISHOP,
     {{
         "   ▗◘▖   ",
         "   ▚/▞   ",
         "    █    ",
         "   ▟█▙   ",
         "         ",
     }}},
    {PieceType::KING,
     {{
         "  ▁ ✜ ▁  ",
         " ( ╲|╱ ) ",
         "  ╲███╱  ",
         " [█████] ",
         "         ",
     }}},
    {PieceType::KNIGHT,
     {{
         "         ",
         "   █ █   ",
         "  ████   ",
         "   ███   ",
         "         ",
     }}},
    {PieceType::PAWN,
     {{
         "   ▗▄▖   ",
         "   ▜█▛   ",
         "   ▗█▖   ",
         "  ▗███▖  ",
         "         ",
     }}},
    {PieceType::QUEEN,
     {{
         "         ",
         "  █ █ █  ",
         "  █████  ",
         "  █████  ",
         "         ",
     }}},
    {PieceType::ROOK,
     {{
         "  ▄ ▄ ▄  ",
         "  ▜███▛  ",
         "   ███   ",
         " ▄█████▄ ",
         "         ",
     }}},
};

}   // namespace Pieces

namespace Squares {
static const std::unordered_map<std::string, Box> Ksq = {
    {StringDrawingName::Square::square,
     {{
         "█████████",
         "█████████",
         "█████████",
         "█████████",
         "█████████",
     }}},
};
}   // namespace Squares

namespace Board {

static const std::string ktop_section = 
  " ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
static const std::vector<std::string> kbottom_section_drawing = {
  " ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃",
  " ┃    A        B        C        D        E        F        G       H     ┃",
  " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛"
};

}   // namespace Board

}   // namespace BoardDrawings

#endif /* BOARD_DRAWINGS_H */
