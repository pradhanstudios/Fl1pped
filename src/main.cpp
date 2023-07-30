#include "raylib.h"
#include "Player.h"

int main(void)
{
    // initialization
    const int screen_width = 1200;
    const int screen_height = 800;

    // initialize window
    InitWindow(screen_width, screen_height, "Window Title");

    // initialize players
    Player player_one((Vector2){screen_width / 2, screen_height / 2}, (Vector2){25, 75}, MAROON);

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

        // refresh background
        ClearBackground(RAYWHITE);

        player_one.draw_player();

        EndDrawing();
        // ---------------------------------------------------------
    }

    // deinitialize
    CloseWindow();

    return 0;
}
