#include <ncurses.h>

#include "./game.hpp"

Game::Game(int height, int width) : board(height, width), game_over(false) {
  this->board.init();
}

void Game::getInput() {
  // chtype input = this->board.getInput();
}

void Game::update() {}

void Game::redraw() { this->board.refresh(); }
