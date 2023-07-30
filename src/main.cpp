#include "raylib.h"
#include "Player.h"
#include "Platform.h"

int main(void)
{
    // initialization
    const int screen_width = 1200;
    const int screen_height = 800;

    // ground
    Vector2 ground_size = {screen_width / 2, screen_height / 12};
    Vector2 ground_pos = {ground_size.x / 2, (float)(screen_height - ground_size.y)};
    Color ground_color = GREEN;
    Platform ground = Platform(ground_pos, ground_size, ground_color);

    // initialize window
    InitWindow(screen_width, screen_height, "Platformer");

    // initialize players
    Player player_one((Vector2){screen_width / 2, screen_height / 2}, (Vector2){25, 75}, MAROON);

    // frames per second
    SetTargetFPS(60);

    // game loop
    while (!WindowShouldClose())
    {
        // UPDATE
        // ---------------------------------------------------------

        // update player
        player_one.move();

        // ---------------------------------------------------------

        // DRAW
        // ---------------------------------------------------------
        BeginDrawing();

        // draw ground
        ground.draw_tile();

        // refresh background
        ClearBackground(RAYWHITE);

        // draw player
        player_one.draw_player();

        EndDrawing();
        // ---------------------------------------------------------
    }

    // deinitialize
    CloseWindow();

    return 0;
}
