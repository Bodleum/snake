#pragma once

#include <ncurses.h>

#include "./drawables.hpp"

class Board {
public:
  Board(int height, int width);
  ~Board() = default;

  void addBorder(chtype verch, chtype horch);
  inline void addBorder() {
    box(this->board_win, this->border_verch, this->border_horch);
  }
  inline void add(Drawable *d) {
    mvwaddch(this->board_win, d->getY(), d->getX(), d->getIcon());
  }

  inline chtype getInput() { return wgetch(this->board_win); }

  inline void init() {
    this->addBorder(this->border_verch, this->border_horch);
    this->clear();
    this->refresh();
  }
  inline void clear() {
    wclear(this->board_win);
    this->addBorder();
  }
  inline void refresh() { wrefresh(this->board_win); }

private:
  WINDOW *board_win;
  chtype border_verch = 0;
  chtype border_horch = 0;
};
