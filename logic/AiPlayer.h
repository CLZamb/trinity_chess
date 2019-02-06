#ifndef AIPLAYER_H
#define AIPLAYER_H
#include "movement.h"

class AiPlayer : public Player {
private:
  Movement::MoveGenerator *moveGenerator;

public:
  explicit AiPlayer(std::string, Movement::MoveGenerator *generator);
  virtual ~AiPlayer();

  std::string getPlayerNextMove() override;
};

#endif /* AIPLAYER_H */
