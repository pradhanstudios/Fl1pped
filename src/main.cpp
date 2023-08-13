#include "raylib.h"
#include "Player.h"
#include "Platform.h"
#include "PlayerCamera.h"
#include "Screen.h"
#include "Scene.h"

#include <stdio.h>

int main(void)
{
    // initialization
    const int screen_width = 1200;
    const int screen_height = 800;

    // initialize window
    InitWindow(screen_width, screen_height, "Platformer");

    // initialize players
    int player_one_controls[3] = {KEY_W, KEY_D, KEY_A}; // jump, right, and left controls
    int player_two_controls[3] = {KEY_UP, KEY_LEFT, KEY_RIGHT};
    Player player_one = Player((Vector2){(screen_width / 2), (screen_height / 2)}, (Vector2){30, 80}, (Color){229, 37, 33, 255}, player_one_controls, 1);
    Player player_two = Player((Vector2){(screen_width / 2), (screen_height / 2)}, (Vector2){30, 80}, (Color){67, 176, 71, 255}, player_two_controls, 0);

    // initialize platforms
    Scene level_0 = Scene('0', '1', &player_one, &player_two);
    level_0.load_scene();

    // list of platforms
    std::vector<Platform> platforms = level_0.get_platforms();
    int num_platforms = platforms.size();
    // fprintf(stderr, "%i", num_platforms);

    // initialize cameras
    PlayerCamera camera1 = PlayerCamera(&player_one);
    PlayerCamera camera2 = PlayerCamera(&player_two);
    // initialize two players rendering stuff
    Screen screenPlayer1 = Screen();
    Screen screenPlayer2 = Screen();
    // Rectangle Rect = {0.0f, 0.0f, (float)screenPlayer1.get_texture().texture.width, (float)-screenPlayer1.get_texture().texture.height};

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
        player_two.update(platforms, num_platforms);
        // fprintf(stderr, "p1: %f, %f p2: %f, %f \n", player_one.get_position().x, player_one.get_position().y, player_two.get_position().x, player_two.get_position().y);

        if (IsKeyReleased(KEY_EQUAL))
        {
            camera1.zoom_out();
            camera2.zoom_out();
        }
        if (IsKeyReleased(KEY_MINUS))
        {
            camera1.zoom_in();
            camera2.zoom_in();
        }

        if (IsKeyReleased(KEY_ZERO))
        {
            camera1.reset_zoom();
            camera2.reset_zoom();
        }

        // update camera
        camera1.target_player();
        camera2.target_player();

        // debug
        // printf("pos: (%f, %f)\n", player_one.get_position().x, player_one.get_position().y);

        // FPS tracker
        SetWindowTitle(TextFormat("Platformer (FPS: %d)", GetFPS()));

        // ---------------------------------------------------------

        // DRAW
        // ---------------------------------------------------------
        screenPlayer1.start();
        camera1.start_camera();
        // refresh background
        ClearBackground(RAYWHITE);
        // draw ground
        for (Platform plat : platforms)
        {
            plat.draw_tile();
        }
        // draw player
        player_one.draw_player();
        player_two.draw_player();
        camera1.stop_camera();
        screenPlayer1.end();

        screenPlayer2.start();
        camera2.start_camera();
        // refresh background
        ClearBackground(RAYWHITE);
        // draw ground
        for (Platform plat : platforms)
        {
            plat.draw_tile();
        }
        // draw player
        player_one.draw_player();
        player_two.draw_player();
        camera2.stop_camera();
        screenPlayer2.end();

        BeginDrawing();
        ClearBackground(BLACK);
        screenPlayer1.combine(screenPlayer2.get_texture());
        // DrawLineV({screen_width / 2, 0.0}, {screen_width / 2, screen_height}, BLACK);
        EndDrawing();
        // ---------------------------------------------------------
    }

    // deinitialize
    screenPlayer1.free(); // Unload render texture
    screenPlayer2.free(); // Unload render texture
    CloseWindow();

    return 0;
}
