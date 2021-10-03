#include "player.h"

Player::Player(int s, int x, int y) :
    Component(x - s, x + s, y - s, y + s),
    size(s), x(x), y(y) {}

Bounds Player::getBounds() const
{
    return bounds;
}

void Player::moveLeft(int amount)
{
    x -= amount;
    bounds.left  = x - size;
    bounds.right = x + size;
}

void Player::moveRight(int amount)
{
    x += amount;
    bounds.left  = x - size;
    bounds.right = x + size;
}
