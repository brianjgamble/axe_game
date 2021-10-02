#include "axe.h"
#include "player.h"
#include <cmath>
#include <raylib.h>

int width{800};
int height{450};
bool collision_with_axe{false};
int direction{10};

enum Movement { Left,
                Right,
                Stop };

Movement processInput();
void update(Player& player, Movement movement, Axe& axe);
void render(Player& player, Axe& axe);

int main()
{
    InitWindow(width, height, "Axe Game");

    Player player{25, 200, 200};
    Axe axe{50, 400, 0};

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        Movement movement = processInput();
        update(player, movement, axe);
        render(player, axe);
    }

    CloseWindow();

    return 0;
}

Movement processInput()
{
    if (IsKeyDown(KEY_D))
        return Right;
    else if (IsKeyDown(KEY_A))
        return Left;
    else
        return Stop;
}

void update(Player& player, Movement movement, Axe& axe)
{
    if (!collision_with_axe) {
        const Bounds& playerBounds = player.getBounds();
        const Bounds& axeBounds    = axe.getBounds();
        collision_with_axe =
            (axeBounds.lower >= playerBounds.upper) &&
            (axeBounds.upper <= playerBounds.lower) &&
            (axeBounds.right >= playerBounds.left) &&
            (axeBounds.left <= playerBounds.right);

        if (direction > 0) {
            axe.moveDown(direction);
            if (axe.isBelow(height))
                direction = -direction;
        }
        else {
            axe.moveUp(abs(direction));
            if (axe.isAbove(0))
                direction = -direction;
        }

        if (movement == Right && player.isLeftOf(width)) {
            player.moveRight(10);
        }
        else if (movement == Left && player.isRightOf(0)) {
            player.moveLeft(10);
        }
    }
}

void render(Player& player, Axe& axe)
{
    BeginDrawing();
    ClearBackground(WHITE);

    if (collision_with_axe) {
        DrawText("Game Over!", 400, 200, 20, RED);
    }
    else {
        DrawCircle(player.x, player.y, (float) player.size, BLUE);
        DrawRectangle(axe.x, axe.y, axe.size, axe.size, RED);
    }
    EndDrawing();
}