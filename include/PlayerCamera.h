#pragma once
#include "raylib.h"
#include "Player.h"

class PlayerCamera
{
private:
    Camera2D camera;
    Player *player;
    // not needed
    // Vector2 target;
    // Vector2 offset;
    // float rotation;
    // float zoom;

public:
    // init (c.o, c.r, c.z) --> camera
    PlayerCamera(Player *player);
    void start_camera();
    void target_player();
    void stop_camera();
    void zoom_in();
    void zoom_out();
    void reset_zoom();
};