#include "user.h"

Bounds User::getBounds() const
{
    return Bounds{
        x - size,
        x + size,
        y - size,
        y + size};
}
