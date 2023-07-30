#include "raylib.h"
#include "Player.h"
#include "Platform.h"

#include <stdio.h>

int main(void)
{
    // initialization
    const int screen_width = 1200;
    const int screen_height = 800;

    // ground
    // Texture2D tile_types[??] = { // tiles // };
    Color tile_types[4] = {GREEN, BLUE, RED, BLACK};
    // Vector2 ground_size = {screen_width / 2, screen_height / 12};
    Platform ground = Platform(Vector2{screen_width / 2, screen_height - 80.0}, tile_types[0]);

    // list of platforms
    // Platform p_screen[1] = ground;
    // int num_platforms = 1;

    // initialize window
    InitWindow(screen_width, screen_height, "Platformer");

    // initialize players
    Player player_one = Player((Vector2){screen_width / 2, screen_height / 2}, (Vector2){30, 80}, MAROON);

    // frames per second
    SetTargetFPS(60);

    // debug
    // printf("Position: %f, %f; Size: %f, %f;", ground.get_position().x, ground.get_position().y, ground.get_size().x, ground.get_size().y);

    // game loop
    while (!WindowShouldClose())
    {
        // UPDATE
        // ---------------------------------------------------------

        // update player
        player_one.update(ground);
        // more debug :(
        // printf("pos: %f, %f; vel: %f, %f; size: %f %f, can_jump: %d", player_one.get_position().x, player_one.get_position().y, player_one.get_velocity().x, player_one.get_velocity().y, player_one.get_size().x, player_one.get_size().y, player_one.get_jump() ? 1 : 0);

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
