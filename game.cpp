#include <ncurses.h>
#include <utility>

#include "./drawables.hpp"
#include "./game.hpp"

Game::Game(int height, int width)
    : board(height, width), game_over(false), apple(nullptr) {

  this->board.init();

  std::pair<int, int> pos = this->board.getRandomEmptyPos();
  this->apple = new Apple(pos.first, pos.second);

  this->redraw();
}

Game::~Game() { delete this->apple; }

void Game::getInput() { this->board.getInput(); }

void Game::update() {
  std::pair<int, int> pos = this->board.getRandomEmptyPos();
  this->apple->setPos(pos.first, pos.second);
}

void Game::redraw() {
  this->board.clear();
  this->board.add(this->apple);
  this->board.refresh();
}
