// File: idisplay.h
#ifndef IDISPLAY_H
#define IDISPLAY_H
#pragma once

#include <ostream>
#include <string>
#include "pane.h"

using std::ostream;

class Displayable {
 public:
    explicit Displayable(size_t size);
    virtual void draw() = 0;
    const string& operator[] (int i);
    int size();

 protected:
    Pane m_drawing;
};
#endif /* IDISPLAY_H */
