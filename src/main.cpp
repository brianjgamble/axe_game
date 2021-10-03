#include "axe.h"
#include "input_handler.h"
#include "player.h"
#include <cmath>
#include <raylib.h>

int width{800};
int height{450};
bool collision_with_axe{false};
int direction{10};

InputHandler handler{width};

void update(Player& player, Command* movement, Axe& axe);
void render(Player& player, Axe& axe);

int main()
{
    InitWindow(width, height, "Axe Game");

    Player player{25, 200, 200};
    Axe axe{50, 400, 0};

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        auto* command = handler.handleInput();
        update(player, command, axe);
        render(player, axe);
    }

    CloseWindow();

    return 0;
}

void update(Player& player, Command* movement, Axe& axe)
{
    if (!collision_with_axe) {
        collision_with_axe = player.collides_with(axe);

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

        if (movement)
            movement->execute(player);
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