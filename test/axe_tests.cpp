#include "../src/axe.h"
#include <catch2/catch_all.hpp>

TEST_CASE("An axe has a boundary and can be moved")
{
    Axe axe{50, 200, 100};
    const Bounds& bounds = axe.getBounds();

    REQUIRE(bounds.left == 150);
    REQUIRE(bounds.right == 250);
    REQUIRE(bounds.upper == 50);
    REQUIRE(bounds.lower == 150);

    SECTION("can move up")
    {
        axe.moveUp(10);

        const Bounds& b = axe.getBounds();
        REQUIRE(b.upper == 40);
        REQUIRE(b.lower == 140);
    }

    SECTION("can move down")
    {
        axe.moveDown(25);

        const Bounds& b = axe.getBounds();
        REQUIRE(b.upper == 75);
        REQUIRE(b.lower == 175);
    }

    SECTION("can check position against boundaries")
    {
        REQUIRE(axe.isAbove(51) == true);
        REQUIRE(axe.isAbove(50) == false);

        REQUIRE(axe.isBelow(149) == true);
        REQUIRE(axe.isBelow(150) == false);
    }
}