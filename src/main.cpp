#include <raylib.h>

int main() {
    InitWindow(350, 200, "First Window!");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RED);
        EndDrawing();
    }

    return 0;
}
