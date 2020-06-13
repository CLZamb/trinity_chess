// File: idisplay.h
#ifndef IDISPLAY_H
#define IDISPLAY_H
#pragma once

class IDisplay {
  public:
    virtual void print() = 0;
    virtual ~IDisplay() = 0;
};
#endif /* IDISPLAY_H */
