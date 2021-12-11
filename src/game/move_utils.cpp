#include "headers/move_utils.h"

const std::regex StringMove::format_full_move =
    std::regex("[a-hA-H][1-8]\\s*[a-hA-H][1-8]");

const std::regex StringMove::format_single_position =
    std::regex("([a-hA-H]\\s*[1-8])");
