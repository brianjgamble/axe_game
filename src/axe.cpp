#include "axe.h"

Axe::Axe(int size, int x, int y) :
    size(size), x(x), y(y) {}

Bounds Axe::getBounds() const
{
    return Bounds{
        x - size,
        x + size,
        y - size,
        y + size};
}

void Axe::moveUp(int amount)
{
    y -= amount;
}

void Axe::moveDown(int amount)
{
    y += amount;
}

bool Axe::isAbove(int pos) const
{
    return (y - size) < pos;
}

bool Axe::isBelow(int pos) const
{
    return (y + size) > pos;
}
