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
  U64 forward_one_sq = BLANK;
  U64 forward_two_sq = BLANK;

  forward_one_sq = shift<SOUTH>(from_sq);
  forward_two_sq |= shift<SOUTH>(forward_one_sq & ROWMASK[5]) ;
  result = forward_one_sq | forward_two_sq;
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
  U64 forward_one_sq = BLANK;
  U64 forward_two_sq = BLANK;

  forward_one_sq = shift<NORTH>(from_sq);
  forward_two_sq |= shift<NORTH>(forward_one_sq & ROWMASK[2]) ;
  result = forward_one_sq | forward_two_sq;
  return result;
}

