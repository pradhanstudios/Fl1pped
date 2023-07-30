#include "raylib.h"

int main(void)
{
    // initialization
    const int screen_width = 1200;
    const int screen_height = 800;

    // ground
    Vector2 ground_size = {screen_width / 2, screen_height / 12};
    Vector2 ground_pos = {ground_size.x / 2, (float)(screen_height - ground_size.y)};

    // initialize window
    InitWindow(screen_width, screen_height, "Window Title");

    // frames per second
    SetTargetFPS(60);

    // game loop
    while (!WindowShouldClose())
    {
        // UPDATE
        // ---------------------------------------------------------

        // ---------------------------------------------------------

        // DRAW
        // ---------------------------------------------------------
        BeginDrawing();

        // draw ground
        DrawRectangleV(ground_pos, ground_size, GREEN);

        // refresh background
        ClearBackground(RAYWHITE);

        EndDrawing();
        // ---------------------------------------------------------
    }

    // deinitialize
    CloseWindow();

    return 0;
}
