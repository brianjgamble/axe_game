#include "user.h"
#include <raylib.h>

class Axe {
public:
    Axe(int size, int x, int y) :
        size(size), x(x), y(y) {}

    int size;
    int x;
    int y;
};

int main()
{
    int width{800};
    int height{450};
    InitWindow(width, height, "Axe Game");

    User user{25, 200, 200};

    Axe axe{50, 400, 0};
    int l_axe_x;
    int r_axe_x;
    int u_axe_y;
    int b_axe_y;

    int direction{10};

    bool collision_with_axe{false};

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);

        if (collision_with_axe) {
            DrawText("Game Over!", 400, 200, 20, RED);
        }
        else {
            // Game logic begins

            // update the edges
            l_axe_x = axe.x;
            r_axe_x = axe.x + axe.size;
            u_axe_y = axe.y;
            b_axe_y = axe.y + axe.size;

            // update collision with axe
            const Bounds& userBounds = user.getBounds();
            collision_with_axe =
                (b_axe_y >= userBounds.upper) &&
                (u_axe_y <= userBounds.lower) &&
                (r_axe_x >= userBounds.left) &&
                (l_axe_x <= userBounds.right);

            DrawCircle(user.x, user.y, (float) user.size, BLUE);
            DrawRectangle(axe.x, axe.y, axe.size, axe.size, RED);

            axe.y += direction;
            if (axe.y > height || axe.y < 0) {
                direction = -direction;
            }

            if (IsKeyDown(KEY_D) && user.isLeftOf(width)) {
                user.moveRight(10);
            }
            else if (IsKeyDown(KEY_A) && user.isRightOf(0)) {
                user.moveLeft(10);
            }

            // Game logic ends
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
