#include "raylib.h"
#include "config.hpp"

int main() {
    // init window
    InitWindow(WIDTH, HEIGHT, TITLE);

    // set fps
    SetTargetFPS(FPS);

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