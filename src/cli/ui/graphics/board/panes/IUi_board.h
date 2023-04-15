#ifndef UI_BOARD_H
#define UI_BOARD_H

#include "ui/graphics/components/pane.h"

class IUiPaneComponent : public Pane {
 public:
  virtual ~IUiPaneComponent() {}
  virtual void update() = 0;
};

#endif /* UI_BOARD_H */
