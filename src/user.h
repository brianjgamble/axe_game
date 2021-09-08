#ifndef AXE_GAME_PROJECT_USER_H
#define AXE_GAME_PROJECT_USER_H

#include "bounds.h"

class User {
public:
    User(int size, int x, int y) :
        size(size), x(x), y(y) {}

    [[nodiscard]] Bounds getBounds() const;

    void moveLeft(int amount);
    void moveRight(int amount);
    [[nodiscard]] bool isLeftOf(int pos) const;
    [[nodiscard]] bool isRightOf(int pos) const;

    int size;
    int x;
    int y;
};

#endif//AXE_GAME_PROJECT_USER_H
