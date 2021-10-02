#ifndef AXE_GAME_PROJECT_AXE_H
#define AXE_GAME_PROJECT_AXE_H


#include "bounds.h"
class Axe {
public:
    Axe(int size, int x, int y);

    [[nodiscard]] Bounds getBounds() const;

    void moveUp(int amount);
    void moveDown(int amount);
    [[nodiscard]] bool isAbove(int pos) const;
    [[nodiscard]] bool isBelow(int pos) const;

    int size;
    int x;
    int y;
};

#endif
