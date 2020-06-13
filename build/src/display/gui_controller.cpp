#include "headers/gui_controller.h"

GuiController::GuiController() {}
GuiController::~GuiController() {}

// defatult size 44
void GuiController::add_pane(string name, string default_drawing) {
  panes[name] = new Pane(default_drawing);
}

void GuiController::add_pane(string name) {
  panes[name] = new Pane();
}

Pane* GuiController::get_pane(string name) {
  if (panes.count(name) == 0)
    throw "pane does not exist with that key";

  return panes[name];
}
