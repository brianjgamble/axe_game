#include "../src/collisional.h"
#include <catch2/catch_all.hpp>

TEST_CASE("Two objects can collide")
{
    Collisional player{100, 130, 120, 160};

    SECTION("on the left/right")
    {
        Collisional enemy1{90, 100, 20, 30};
        CHECK(player.collides_with(enemy1) == false);

        Collisional enemy2{90, 100, 140, 150};
        CHECK(player.collides_with(enemy2));
    }

    SECTION("on the right/left")
    {
        Collisional enemy1{130, 140, 20, 30};
        CHECK(player.collides_with(enemy1) == false);

        Collisional enemy2{130, 140, 140, 150};
        CHECK(player.collides_with(enemy2));
    }

    SECTION("on the upper/lower")
    {
        Collisional enemy1{125, 135, 20, 30};
        CHECK(player.collides_with(enemy1) == false);

        Collisional enemy2{125, 135, 110, 120};
        CHECK(player.collides_with(enemy2));
    }

    SECTION("on the lower/upper")
    {
        Collisional enemy1{125, 135, 20, 30};
        CHECK(player.collides_with(enemy1) == false);

        Collisional enemy2{125, 135, 160, 170};
        CHECK(player.collides_with(enemy2));
    }
}
