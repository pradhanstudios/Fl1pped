#include "raylib.h"
#include "Player.h"
#include "Platform.h"

#include <stdio.h>

int main(void)
{
    // initialization
    const int screen_width = 1200;
    const int screen_height = 800;

    // initialize window
    InitWindow(screen_width, screen_height, "Platformer");

    // ground
    Platform ground = Platform(Vector2{screen_width / 2, screen_height - 80.0}, Vector2{80.0, 80.0}, GREEN);

    // list of platforms
    // Platform p_screen[1] = ground;
    // int num_platforms = 1;

    // initialize players
    Player player_one = Player((Vector2){(screen_width / 2), (screen_height / 2)}, (Vector2){30, 80}, MAROON);

    // frames per second
    SetTargetFPS(60);

    // debug
    // printf("Position: %f, %f; Size: %f, %f;", ground.get_position().x, ground.get_position().y, ground.get_size().x, ground.get_size().y);
    // printf("pos: (%f, %f)\n", player_one.get_position().x, player_one.get_position().y);

    // game loop
    while (!WindowShouldClose())
    {
        // UPDATE
        // ---------------------------------------------------------

        // update player
        player_one.update(ground);

        // debug
        // printf("pos: (%f, %f)\n", player_one.get_position().x, player_one.get_position().y);

        // ---------------------------------------------------------

        // DRAW
        // ---------------------------------------------------------
        BeginDrawing();

        // refresh background
        ClearBackground(RAYWHITE);

        // draw ground
        ground.draw_tile();

        // draw player
        player_one.draw_player();

        EndDrawing();
        // ---------------------------------------------------------
    }

    // deinitialize
    CloseWindow();

    return 0;
}
