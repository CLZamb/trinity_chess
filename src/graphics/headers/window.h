#ifndef WINDOW_H
#define WINDOW_H

#include <algorithm>
#include <array>
#include <functional>
#include <map>
#include <vector>
#include <string>
#include "pane.h"
#include "section.h"
#include "../headers/Idisplay.h"
#include "../../include/common/headers/common.h"

using std::ostream;
// using std::array;
using std::map;

class Window {
 public:
    enum Pane_pos {
      Left_pane = 0,
      Middle_pane = 1,
      Right_pane = 2,
      Max_panes_size = 3
    };

    Window();
    virtual ~Window();

    void add_pane(Displayable* pane, Pane_pos pos);
    int get_pane_size(int index);
    friend ostream& operator << (ostream &os,  Window &);

 private:
    std::once_flag initOnceFlag;
    std::once_flag destructOnceFlag;
    void _init_();
    void insert_formatted_output
      (map<int, Displayable*, std::less<int>> panes, ostream& os, int index);
    map<int, Displayable*, std::less<int>> panes;
};

#endif /* WINDOW_H */
