#ifndef AIPLAYER_H
#define AIPLAYER_H
#include "movement.h"

class AiPlayer : public Player {
private:
  Movement::MoveGenerator* p_move_generator;

public:
  explicit AiPlayer(bool has_black_pieces, Movement* movement_controller);
  virtual ~AiPlayer();

  PlayerMove get_next_move() override;
};

#endif /* AIPLAYER_H */
