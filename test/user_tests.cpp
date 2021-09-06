#include "../src/user.h"
#include <catch2/catch.hpp>

TEST_CASE("A user has a boundary") {
    User user{35, 100, 50};
    const Bounds& bounds = user.getBounds();

    REQUIRE(bounds.left == 65);
    REQUIRE(bounds.right == 135);
    REQUIRE(bounds.upper == 15);
    REQUIRE(bounds.lower == 85);
}