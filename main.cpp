// J.J.
// Copyright 2023 Daniel Laing
#include <ncurses.h>

#include "./board.hpp"
#include "./game.hpp"

#define BOARD_DIM 25
#define BOARD_ROWS BOARD_DIM
#define BOARD_COLS BOARD_DIM * 2.5

int main(int argc, char **argv) {
  initscr();
  refresh();

  Game g(BOARD_ROWS, BOARD_COLS);

  while (!g.isOver()) {
    // 1. Get inupt
    g.getInput();

    // 2. Update state
    g.update();

    // 3. Redraw
    g.redraw();

    // 4. Go back to 1. unless game over
  }

  getch();
  endwin();

  return 0;
}

// S.D.G.
