#include "headers/pawn.h"

// Black pawn
U64 BlackPawn::pawn_attack(int sq) {
    U64 from_sq = ONE << sq;
    U64 result = BLANK;

    result = shift<SOUTH_EAST>(from_sq);
    result |= shift<SOUTH_WEST>(from_sq);
    return result;
}

U64 BlackPawn::pawn_non_attack(int sq) {
    U64 from_sq = ONE << sq;
    U64 result = BLANK;

    result = shift<SOUTH>(from_sq);
    result |= shift<SOUTH>(result & ROWMASK[5]);
    return result;
}

// White Pawn
U64 WhitePawn::pawn_attack(int sq) {
    U64 from_sq = ONE << sq;
    U64 result = BLANK;
    result = shift<NORTH_WEST>(from_sq);
    result |= shift<NORTH_EAST>(from_sq);
    return result;
}

U64 WhitePawn::pawn_non_attack(int sq) {
    U64 from_sq = ONE << sq;
    U64 result = BLANK;

    result = shift<NORTH>(from_sq);
    result |= shift<NORTH>(result & ROWMASK[2]);
    return result;
}

