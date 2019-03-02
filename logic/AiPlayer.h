#ifndef AIPLAYER_H
#define AIPLAYER_H
#include "movement.h"

class AiPlayer : public Player {
private:
  Movement::MoveGenerator *moveGenerator;

public:
  explicit AiPlayer(std::string, Movement::MoveGenerator *generator);
  virtual ~AiPlayer();

  Move getPlayerNextMove() override;
};

#endif /* AIPLAYER_H */
