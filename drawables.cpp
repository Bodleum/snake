#include <ncurses.h>

#include "./drawables.hpp"

Drawable::Drawable(int y, int x, chtype ch) : y(y), x(x), icon(ch) {}

Apple::Apple(int y, int x) : Drawable(y, x, 'A') {}

SnakePiece::SnakePiece(int y, int x) : Drawable(y, x, '#') {}

Snake::Snake() : dir(Direction::down), pieces() {}
