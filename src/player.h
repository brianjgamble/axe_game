#ifndef AXE_GAME_PROJECT_PLAYER_H
#define AXE_GAME_PROJECT_PLAYER_H

#include "bounds.h"

class Player {
public:
    Player(int size, int x, int y);

    [[nodiscard]] Bounds getBounds() const;

    void moveLeft(int amount);
    void moveRight(int amount);
    [[nodiscard]] bool isLeftOf(int pos) const;
    [[nodiscard]] bool isRightOf(int pos) const;

    int size;
    int x;
    int y;
};

#endif
