// File: idisplay.h
#ifndef IDISPLAY_H
#define IDISPLAY_H
#pragma once

#include <string>
#include "pane.h"

class Displayable {
 public:
    explicit Displayable(size_t size = 44);
    virtual void draw() = 0;
    const string& operator[] (int i);
    size_t size();

 protected:
    Pane m_pane;
};

#endif /* IDISPLAY_H */
