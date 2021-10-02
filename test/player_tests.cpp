#include "../src/player.h"
#include <catch2/catch_all.hpp>

TEST_CASE("A player has a boundary and can be moved")
{
    Player player{35, 100, 50};
    const Bounds& bounds = player.getBounds();

    REQUIRE(bounds.left == 65);
    REQUIRE(bounds.right == 135);
    REQUIRE(bounds.upper == 15);
    REQUIRE(bounds.lower == 85);

    SECTION("can move left")
    {
        player.moveLeft(10);

        const Bounds& leftBounds = player.getBounds();
        REQUIRE(leftBounds.left == 55);
        REQUIRE(leftBounds.right == 125);
    }

    SECTION("can move right")
    {
        player.moveRight(25);

        const Bounds& rightBounds = player.getBounds();
        REQUIRE(rightBounds.left == 90);
        REQUIRE(rightBounds.right == 160);
    }

    SECTION("can check position against boundaries")
    {
        // Check is right boundary is left of a position
        REQUIRE(player.isLeftOf(136) == true);
        REQUIRE(player.isLeftOf(135) == false);

        // Check if left boundary is right of a position
        REQUIRE(player.isRightOf(64) == true);
        REQUIRE(player.isRightOf(65) == false);
    }
}