#include "user.h"

Bounds User::getBounds() const
{
    return Bounds{
        x - size,
        x + size,
        y - size,
        y + size};
}

void User::moveLeft(int amount)
{
    x -= amount;
}

void User::moveRight(int amount)
{
    x += amount;
}

bool User::isLeftOf(int pos) const
{
    return (x + size) < pos;
}

bool User::isRightOf(int pos) const
{
    return (x - size) > pos;
}
