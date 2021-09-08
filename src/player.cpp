#include "player.h"

Bounds Player::getBounds() const
{
    return Bounds{
        x - size,
        x + size,
        y - size,
        y + size};
}

void Player::moveLeft(int amount)
{
    x -= amount;
}

void Player::moveRight(int amount)
{
    x += amount;
}

bool Player::isLeftOf(int pos) const
{
    return (x + size) < pos;
}

bool Player::isRightOf(int pos) const
{
    return (x - size) > pos;
}
