#include <raylib.h>

int main() {
    int width{350};
    int height{200};
    InitWindow(width, height, "First Window!");

    int circle_x{175};
    int circle_y{100};

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);

        DrawCircle(circle_x, circle_y, 25, BLUE);

        if (IsKeyDown(KEY_D) && circle_x < width) {
            circle_x += 10;
        } else if (IsKeyDown(KEY_A) && circle_x > 0) {
            circle_x -= 10;
        }

        EndDrawing();
    }

    return 0;
}
