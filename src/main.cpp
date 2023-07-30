#include "raylib.h"
//123
int main(void)
{
    // initialization
    const int screen_width = 1200;
    const int screen_height = 800;

    // initialize window
    InitWindow(screen_width, screen_height, "Window Title");

    // frames per second
    SetTargetFPS(60);

    // game loop
    while (!WindowShouldClose())
    {
        // UPDATE
        // ---------------------------------------------------------

        // toggle fullscreen
        if (IsKeyDown(KEY_F))
        {
            ToggleFullscreen();
        }
        // ---------------------------------------------------------

        // DRAW
        // ---------------------------------------------------------
        BeginDrawing();

        // refresh background
        ClearBackground(RAYWHITE);

        EndDrawing();
        // ---------------------------------------------------------
    }

    // deinitialize
    CloseWindow();

    return 0;
}
