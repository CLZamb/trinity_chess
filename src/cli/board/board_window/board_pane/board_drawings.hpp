#ifndef BOARD_DRAWINGS_H
#define BOARD_DRAWINGS_H
#pragma once

#include "ui_components/box.h"
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
static const std::unordered_map<std::string, Box> Ksquares = {
    {StringDrawingName::Square::white_square,
     {{
         "\033[38;5;251m█████████\033[0m",
         "\033[38;5;252m█████████\033[0m",
         "\033[38;5;253m█████████\033[0m",
         "\033[38;5;254m█████████\033[0m",
         "\033[38;5;255m█████████\033[0m",
     }}},
    {StringDrawingName::Square::black_square,
     {{
         "\033[38;5;233m█████████\033[0m",
         "\033[38;5;234m█████████\033[0m",
         "\033[38;5;235m█████████\033[0m",
         "\033[38;5;236m█████████\033[0m",
         "\033[38;5;237m█████████\033[0m",
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
