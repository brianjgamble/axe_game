#include "collisional.h"

Collisional::Collisional(int left, int right, int upper, int lower)
{
    bounds.left  = left;
    bounds.right = right;
    bounds.upper = upper;
    bounds.lower = lower;
}

bool Collisional::collides_with(const Collisional& that)
{
    return (this->bounds.lower >= that.bounds.upper) &&
           (this->bounds.upper <= that.bounds.lower) &&
           (this->bounds.right >= that.bounds.left) &&
           (this->bounds.left <= that.bounds.right);
}
