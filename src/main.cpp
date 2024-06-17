#include "raylib.h"
#include "config.hpp"
#include "object.hpp"

int main() {
    Object obj = Object(50, 100, 20, 20, BLACK);
    // init window
    InitWindow(WIDTH, HEIGHT, TITLE);

    // set fps
    SetTargetFPS(FPS);

    // game loop
    while (!WindowShouldClose()) {
        // update
        obj.set_x(obj.bot_right_x());
        obj.set_y(obj.bot_left_y());
        // draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        obj.Draw_Color();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}