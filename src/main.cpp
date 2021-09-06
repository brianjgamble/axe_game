#include <raylib.h>

class User {
public:
    User(int size, int x, int y) :
        size(size), x(x), y(x) {}

    int size;
    int x;
    int y;
};

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
    int l_circle_x{};
    int r_circle_x{};
    int u_circle_y{};
    int b_circle_y{};

    Axe axe{50, 400, 0};
    int l_axe_x{};
    int r_axe_x{};
    int u_axe_y{};
    int b_axe_y{};

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
            l_circle_x = user.x - user.size;
            r_circle_x = user.x + user.size;
            u_circle_y = user.y - user.size;
            b_circle_y = user.y + user.size;
            l_axe_x    = axe.x;
            r_axe_x    = axe.x + axe.size;
            u_axe_y    = axe.y;
            b_axe_y    = axe.y + axe.size;

            // update collision with axe
            collision_with_axe =
                (b_axe_y >= u_circle_y) &&
                (u_axe_y <= b_circle_y) &&
                (r_axe_x >= l_circle_x) &&
                (l_axe_x <= r_circle_x);

            DrawCircle(user.x, user.y, (float) user.size, BLUE);
            DrawRectangle(axe.x, axe.y, axe.size, axe.size, RED);

            axe.y += direction;
            if (axe.y > height || axe.y < 0) {
                direction = -direction;
            }

            if (IsKeyDown(KEY_D) && user.x < width) {
                user.x += 10;
            }
            else if (IsKeyDown(KEY_A) && user.x > 0) {
                user.x -= 10;
            }

            // Game logic ends
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
