#pragma once

#include <ncurses.h>

class Drawable {
public:
  Drawable(int y, int x, chtype ch);
  ~Drawable() = default;

  inline int getY() { return this->y; }
  inline int getX() { return this->x; }
  inline chtype getIcon() { return this->icon; }

protected:
  int y, x;
  chtype icon;
};
