#include "../src/axe.h"
#include <catch2/catch_all.hpp>

TEST_CASE("An axe has a boundary and can be moved")
{
    Axe axe{50, 200, 100};
    const Bounds& bounds = axe.getBounds();

    REQUIRE(bounds.left == 200);
    REQUIRE(bounds.right == 250);
    REQUIRE(bounds.upper == 100);
    REQUIRE(bounds.lower == 150);

    SECTION("can move up")
    {
        axe.moveUp(10);

        const Bounds& b = axe.getBounds();
        REQUIRE(b.upper == 90);
        REQUIRE(b.lower == 140);
    }

    SECTION("can move down")
    {
        axe.moveDown(25);

        const Bounds& b = axe.getBounds();
        REQUIRE(b.upper == 125);
        REQUIRE(b.lower == 175);
    }

    SECTION("can check position against boundaries")
    {
        REQUIRE(axe.isAbove(101) == true);
        REQUIRE(axe.isAbove(100) == false);

        REQUIRE(axe.isBelow(149) == true);
        REQUIRE(axe.isBelow(150) == false);
    }
}