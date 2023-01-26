#pragma once

#include <ncurses.h>

class Board {
public:
  Board(int height, int width);

  void addBorder(chtype verch, chtype horch);
  inline void addBorder() {
    box(this->board_win, this->border_verch, this->border_horch);
  }
  inline void addAt(int y, int x, chtype ch) {
    mvwaddch(this->board_win, y, x, ch);
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
