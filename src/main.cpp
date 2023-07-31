#include "raylib.h"
#include "Player.h"
#include "Platform.h"
#include "PlayerCamera.h"

#include <stdio.h>

int main(void)
{
    // initialization
    const int screen_width = 1200;
    const int screen_height = 800;

    // initialize window
    InitWindow(screen_width, screen_height, "Platformer");

    // initialize platforms
    Platform ground1 = Platform(Vector2{400.0, 720.0}, Vector2{1800.0, 50.0}, GREEN);
    Platform ground2 = Platform(Vector2{200.0, 600.0}, Vector2{50.0, 50.0}, GREEN);
    Platform ground3 = Platform(Vector2{600.0, 480.0}, Vector2{160.0, 50.0}, GREEN);
    Platform ground4 = Platform(Vector2{1000.0, 220.0}, Vector2{100.0, 500.0}, RED);

    // list of platforms
    Platform platforms[] = {ground1, ground2, ground3, ground4};
    int num_platforms = sizeof(platforms) / sizeof(Platform);

    // initialize players
    int player_one_controls[3] = {KEY_W, KEY_D, KEY_A}; // jump, right, and left controls
    int player_two_controls[3] = {KEY_UP, KEY_RIGHT, KEY_LEFT};
    Player player_one = Player((Vector2){(screen_width / 2), (screen_height / 2)}, (Vector2){30, 80}, MAROON, player_one_controls);
    Player player_two = Player((Vector2){(screen_width / 2), (screen_height / 2)}, (Vector2){30, 80}, BLUE, player_two_controls);

    // initialize cameras
    PlayerCamera camera1 = PlayerCamera(&player_one);
    PlayerCamera camera2 = PlayerCamera(&player_two);
    // initialize two players rendering stuff
    RenderTexture screenPlayer1 = LoadRenderTexture(screen_width / 2, screen_height);
    RenderTexture screenPlayer2 = LoadRenderTexture(screen_width / 2, screen_height);
    Rectangle splitScreenRect = {0.0f, 0.0f, (float)screenPlayer1.texture.width, (float)-screenPlayer1.texture.height};

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
        BeginTextureMode(screenPlayer1);
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
        camera1.stop_camera();
        EndTextureMode();

        BeginTextureMode(screenPlayer2);
        camera2.start_camera();
        // refresh background
        ClearBackground(RAYWHITE);
        // draw ground
        for (Platform plat : platforms)
        {
            plat.draw_tile();
        }
        // draw player
        player_two.draw_player();
        camera2.stop_camera();
        EndTextureMode();

        BeginDrawing();
        ClearBackground(BLACK);
        DrawTextureRec(screenPlayer1.texture, splitScreenRect, (Vector2){0, 0}, WHITE);
        DrawTextureRec(screenPlayer2.texture, splitScreenRect, (Vector2){screen_width / 2.0f, 0}, WHITE);
        DrawLineV({screen_width / 2, 0.0}, {screen_width / 2, screen_height}, BLACK);
        EndDrawing();
        // ---------------------------------------------------------
    }

    // deinitialize
    UnloadRenderTexture(screenPlayer1); // Unload render texture
    UnloadRenderTexture(screenPlayer2); // Unload render texture
    CloseWindow();

    return 0;
}
