#ifndef IMOVE_VALIDATION_H
#define IMOVE_VALIDATION_H

#pragma once
#include "../../headers/move.h"

class IMoveValidation {
 public:
  virtual bool is_valid_move(const Move& m) = 0;
};

#endif /* IMOVE_VALIDATION_H */
