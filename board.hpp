#pragma once

#include <ncurses.h>
#include <utility>

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
    this->refresh();
  }
  inline void clear() {
    wclear(this->board_win);
    this->addBorder();
  }

  inline void refresh() { wrefresh(this->board_win); }

  inline int getHeight() { return this->height; }
  inline int getWidth() { return this->width; }
  inline bool isEmpty(int y, int x) {
    return mvwinch(this->board_win, y, x) == ' ';
  }

  std::pair<int, int> getRandomEmptyPos();

private:
  WINDOW *board_win;
  int height, width;
  chtype border_verch, border_horch;
};
