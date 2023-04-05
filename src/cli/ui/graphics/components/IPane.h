// File: idisplay.h
#ifndef IDISPLAY_H
#define IDISPLAY_H
#pragma once

#include <string>

class IPane {
 public:
  virtual const std::string& operator[] (size_t i) = 0;
  virtual size_t size() = 0;
};

#endif /* IDISPLAY_H */
