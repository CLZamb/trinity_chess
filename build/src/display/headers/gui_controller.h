#ifndef GUI_CONTROLLER_H
#define GUI_CONTROLLER_H

#include <vector>
#include <string>
#include "pane.h"
#include "section.h"

/* TODO:
 * Use components to add to the gui controller
 * ie. add_component(type, etc)
 * */

class GuiController{
 public:
    GuiController();
    virtual ~GuiController();

    void add_pane(string name);
    void add_pane(string name, string default_drawing);
    Pane* get_pane(string name);

 private:
    unordered_map<string, Pane*> panes;
};

#endif /* GUI_CONTROLLER_H */
