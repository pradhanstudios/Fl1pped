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

    // initialize platforms
    Platform ground1 = Platform(Vector2{400.0, 720.0}, Vector2{400.0, 50.0}, GREEN);
    Platform ground2 = Platform(Vector2{200.0, 600.0}, Vector2{50.0, 50.0}, GREEN);
    Platform ground3 = Platform(Vector2{600.0, 480.0}, Vector2{160.0, 50.0}, GREEN);
    Platform ground4 = Platform(Vector2{700.0, 720.0 - 500.0}, Vector2{100.0, 500.0}, RED);

    // list of platforms
    Platform platforms[] = {ground1, ground2, ground3, ground4};
    int num_platforms = sizeof(platforms) / sizeof(Platform);

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
        player_one.update(platforms, num_platforms);

        // debug
        // printf("pos: (%f, %f)\n", player_one.get_position().x, player_one.get_position().y);

        // ---------------------------------------------------------

        // DRAW
        // ---------------------------------------------------------
        BeginDrawing();

        // refresh background
        ClearBackground(RAYWHITE);

        // draw ground
        for (Platform plat : platforms)
        {
            plat.draw_tile();
        }

        // draw player
        player_one.draw_player();

        EndDrawing();
        // ---------------------------------------------------------
    }

    // deinitialize
    CloseWindow();

    return 0;
}
