#include <ncurses.h>

#include "./board.hpp"

Board::Board(int height, int width) {
  int xMax, yMax;
  getmaxyx(stdscr, yMax, xMax);

  this->board_win =
      newwin(height, width, (yMax - height) / 2, (xMax - width) / 2);
}

void Board::addBorder(chtype verch, chtype horch) {
  this->border_verch = verch;
  this->border_horch = horch;
  box(this->board_win, verch, horch);
}
