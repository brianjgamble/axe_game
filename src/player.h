#ifndef AXE_GAME_PROJECT_PLAYER_H
#define AXE_GAME_PROJECT_PLAYER_H

#include "component.h"

class Player : public Component {
public:
    Player(int s, int x, int y);

    [[nodiscard]] Bounds getBounds() const;
    void moveLeft(int amount);
    void moveRight(int amount);

    int size;
    int x;
    int y;
};

#endif
