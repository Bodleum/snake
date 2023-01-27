#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#include "./board.hpp"

Board::Board(int height, int width)
    : height(height), width(width), border_verch(0), border_horch(0) {
  int xMax, yMax;
  getmaxyx(stdscr, yMax, xMax);

  this->board_win =
      newwin(height, width, (yMax - height) / 2, (xMax - width) / 2);

  srand(time(NULL));
}

void Board::addBorder(chtype verch, chtype horch) {
  this->border_verch = verch;
  this->border_horch = horch;
  box(this->board_win, verch, horch);
}

std::pair<int, int> Board::getRandomEmptyPos() {
  int y, x;
  while (!this->isEmpty(y = rand() % this->height, x = rand() % this->width)) {
  }
  return std::make_pair(y, x);
}
