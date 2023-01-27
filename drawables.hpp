#pragma once

#include <ncurses.h>
#include <queue>

enum class Direction : char { up, down, left, right };

class Drawable {
public:
  Drawable(int y, int x, chtype ch);
  ~Drawable() = default;

  inline int getY() { return this->y; }
  inline int getX() { return this->x; }
  inline chtype getIcon() { return this->icon; }
  inline void setPos(int y, int x) {
    this->y = y;
    this->x = x;
  }

protected:
  int y, x;
  chtype icon;
};

class Apple : public Drawable {
public:
  Apple(int y, int x);
  ~Apple() = default;
};

class SnakePiece : public Drawable {
public:
  SnakePiece(int y, int x);
  ~SnakePiece() = default;
};

class Snake {
public:
  Snake();
  ~Snake() = default;

  inline void addPiece(SnakePiece p) { this->pieces.push(p); }
  inline void removePiece() { this->pieces.pop(); }
  inline SnakePiece tail() { return this->pieces.back(); }
  inline SnakePiece head() { return this->pieces.front(); }

private:
  Direction dir;
  std::queue<SnakePiece> pieces;
};
