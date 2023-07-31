#pragma once
#include "raylib.h"
#include "Player.h"

class PlayerCamera
{
private:
    Camera2D camera;
    Player *player;
    Vector2 target;
    Vector2 offset;
    float rotation;
    float zoom;

public:
    // init (c.o, c.r, c.z) --> camera
    PlayerCamera(Player *player);
    void start_camera();
    void target_player();
    void stop_camera();
};