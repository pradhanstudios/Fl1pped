#include "raylib.h"
#include "config.hpp"
#include "object.hpp"

int main() {
    Platform obj = build_platform(50, 100, 20, 20, BLACK);
    // init window
    InitWindow(WIDTH, HEIGHT, TITLE);

    // set fps
    SetTargetFPS(FPS);

    // game loop
    while (!WindowShouldClose()) {
        // update
        // draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        obj.Draw_Color();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}