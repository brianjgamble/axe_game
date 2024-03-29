#ifndef AXE_GAME_PROJECT_AXE_H
#define AXE_GAME_PROJECT_AXE_H

#include "component.h"

class Axe : public Component {
public:
    Axe(int size, int x, int y);

    [[nodiscard]] Bounds getBounds() const;
    void moveUp(int amount) override;
    void moveDown(int amount) override;

    int size;
    int x;
    int y;
};

#endif
