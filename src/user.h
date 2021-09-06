#ifndef AXE_GAME_PROJECT_USER_H
#define AXE_GAME_PROJECT_USER_H

#include "bounds.h"

class User {
public:
    User(int size, int x, int y) :
        size(size), x(x), y(y) {}

    [[nodiscard]] Bounds getBounds() const;

    int size;
    int x;
    int y;
};

#endif//AXE_GAME_PROJECT_USER_H
