#include "axe.h"

Axe::Axe(int size, int x, int y) :
    Collisional(x, x + size, y, y + size),
    size(size), x(x), y(y) {}

Bounds Axe::getBounds() const
{
    return bounds;
}

void Axe::moveUp(int amount)
{
    y -= amount;
    bounds.upper = y;
    bounds.lower = y + size;
}

void Axe::moveDown(int amount)
{
    y += amount;
    bounds.upper = y;
    bounds.lower = y + size;
}

bool Axe::isAbove(int pos) const
{
    return bounds.upper < pos;
}

bool Axe::isBelow(int pos) const
{
    return bounds.lower > pos;
}