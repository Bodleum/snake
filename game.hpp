#pragma once

/* #include <ncurses.h> */

#include "./board.hpp"

class Game {
public:
  Game(int height, int width);
  ~Game() = default;

  void getInput();
  void update();
  void redraw();

  inline bool isOver() { return this->game_over; }

private:
  Board board;
  bool game_over;
};
