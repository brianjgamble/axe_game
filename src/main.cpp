#include <raylib.h>

int main() {
    int width{800};
    int height{450};
    InitWindow(width, height, "First Window!");

    int circle_x{200};
    int circle_y{200};

    int axe_x{400};
    int axe_y{};

    int direction{10};

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);

        DrawCircle(circle_x, circle_y, 25, BLUE);
        DrawRectangle(axe_x, axe_y, 50, 50, RED);

        axe_y += direction;
        if (axe_y > height || axe_y < 0) {
            direction = -direction;
        }

        if (IsKeyDown(KEY_D) && circle_x < width) {
            circle_x += 10;
        } else if (IsKeyDown(KEY_A) && circle_x > 0) {
            circle_x -= 10;
        }

        EndDrawing();
    }

    return 0;
}
