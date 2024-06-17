#include "raylib.h"

int main() {

    const int screen_width = 1200;
    const int screen_height = 800;

    // init window
    InitWindow(screen_width, screen_height, "Title");

    // set fps
    SetTargetFPS(60);

    // game loop
    while (!WindowShouldClose()) {
        // udpate

        // draw
        BeginDrawing();

        ClearBackground(RAYWHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}