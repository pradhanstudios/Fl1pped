#include "raylib.h"
#include "config.hpp"
#include "object.hpp"

int main() {
    Object obj = Object(50, 100, 25, 200, BLACK);
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
        
        obj.Draw_Color();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}