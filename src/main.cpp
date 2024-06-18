#include "raylib.h"
#include "config.hpp"
#include "object.hpp"
#include "player.hpp"

int main() {
    std::vector<Object> global_objects_list;
    Platform obj = build_platform(50, 500, 250, 20, BLACK);
    global_objects_list.push_back(obj);
    Player player1 = Player(100, 50, 50, 100, GREEN);
    // init window
    InitWindow(WIDTH, HEIGHT, TITLE);

    // set fps
    SetTargetFPS(FPS);

    // game loop
    while (!WindowShouldClose()) {
        // update
        player1.update(global_objects_list);
        // draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        obj.Draw_Color();
        player1.Draw_Color();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}