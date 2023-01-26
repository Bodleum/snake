// J.J.
// Copyright 2023 Daniel Laing
#include <ncurses.h>

#include "./board.hpp"

#define BOARD_DIM 25
#define BOARD_ROWS BOARD_DIM
#define BOARD_COLS BOARD_DIM * 2.5

int main(int argc, char **argv) {
  initscr();
  refresh();

  Board board(BOARD_ROWS, BOARD_COLS);
  board.init();

  board.addAt(5, 5, '#');
  board.refresh();

  getch();
  endwin();

  return 0;
}

// S.D.G.
