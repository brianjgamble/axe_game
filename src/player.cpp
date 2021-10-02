#include "player.h"

Player::Player(int size, int x, int y) :
    size(size), x(x), y(y) {}

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
