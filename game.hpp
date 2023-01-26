#pragma once

/* #include <ncurses.h> */

#include "./board.hpp"

class Game {
public:
  Game(int height, int width);
  ~Game() = default;

  inline Board getBoard() { return this->board; }

  void getInput();
  void update();
  void redraw();

  inline bool isOver() { return this->game_over; }

private:
  Board board;
  bool game_over;
};
