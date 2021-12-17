#include "headers/move_utils.h"

const std::regex String::format_full_move =
    std::regex("[a-hA-H][1-8]\\s*[a-hA-H][1-8]");

const std::regex String::format_single_position =
    std::regex("([a-hA-H]\\s*[1-8])");
