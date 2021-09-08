#include "../src/user.h"
#include <catch2/catch.hpp>

TEST_CASE("A user has a boundary and can be moved")
{
    User user{35, 100, 50};
    const Bounds& bounds = user.getBounds();

    REQUIRE(bounds.left == 65);
    REQUIRE(bounds.right == 135);
    REQUIRE(bounds.upper == 15);
    REQUIRE(bounds.lower == 85);

    SECTION("can move left")
    {
        user.moveLeft(10);

        const Bounds& leftBounds = user.getBounds();
        REQUIRE(leftBounds.left == 55);
        REQUIRE(leftBounds.right == 125);
    }

    SECTION("can move right") {
        user.moveRight(25);

        const Bounds& rightBounds = user.getBounds();
        REQUIRE(rightBounds.left == 90);
        REQUIRE(rightBounds.right == 160);
    }

    SECTION("can check position against boundaries") {
        // Check is right boundary is left of a position
        REQUIRE(user.isLeftOf(136) == true);
        REQUIRE(user.isLeftOf(135) == false);

        // Check if left boundary is right of a position
        REQUIRE(user.isRightOf(64) == true);
        REQUIRE(user.isRightOf(65) == false);
    }
}