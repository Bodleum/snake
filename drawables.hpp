#pragma once

#include <ncurses.h>

class Drawable {
public:
  Drawable(int y, int x, chtype ch);
  ~Drawable() = default;

  inline int getY() { return this->y; }
  inline int getX() { return this->x; }
  inline chtype getIcon() { return this->icon; }
  inline void setPos(int y, int x) {
    this->y = y;
    this->x = x;
  }

protected:
  int y, x;
  chtype icon;
};

class Apple : public Drawable {
public:
  Apple(int y, int x);
  ~Apple() = default;
};
