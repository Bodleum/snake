#include <ncurses.h>

#include "./drawables.hpp"

Drawable::Drawable(int y, int x, chtype ch) : y(y), x(x), icon(ch) {}