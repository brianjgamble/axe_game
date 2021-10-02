#ifndef AXE_GAME_PROJECT_COLLISIONAL_H
#define AXE_GAME_PROJECT_COLLISIONAL_H

#include "bounds.h"

class Collisional {
public:
    Collisional(int left, int right, int upper, int lower);
    bool collides_with(const Collisional& that);

protected:
    Bounds bounds{};
};

#endif
