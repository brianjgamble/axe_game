#include "component.h"

Component::Component(int left, int right, int upper, int lower)
{
    bounds.left  = left;
    bounds.right = right;
    bounds.upper = upper;
    bounds.lower = lower;
}

bool Component::collides_with(const Component& that)
{
    return (this->bounds.lower >= that.bounds.upper) &&
           (this->bounds.upper <= that.bounds.lower) &&
           (this->bounds.right >= that.bounds.left) &&
           (this->bounds.left <= that.bounds.right);
}

bool Component::isAbove(int pos) const
{
    return bounds.upper < pos;
}

bool Component::isBelow(int pos) const
{
    return bounds.lower > pos;
}

bool Component::isLeftOf(int pos) const
{
    return bounds.right < pos;
}

bool Component::isRightOf(int pos) const
{
    return bounds.left > pos;
}
