#include "../src/move_left_command.h"
#include "../src/move_right_command.h"
#include "../src/player.h"
#include <catch2/catch_all.hpp>

TEST_CASE("Can move a component left")
{
    MoveLeftCommand command{0};
    Player p{10, 30, 20};

    command.execute(p);
    CHECK(p.getBounds().left == 10);

    command.execute(p);
    CHECK(p.getBounds().left == 0);

    command.execute(p);
    CHECK(p.getBounds().left == 0);
}

TEST_CASE("Can move a component right")
{
    MoveRightCommand command{60};
    Player p{10, 30, 20};

    command.execute(p);
    CHECK(p.getBounds().right == 50);

    command.execute(p);
    CHECK(p.getBounds().right == 60);

    command.execute(p);
    CHECK(p.getBounds().right == 60);
}