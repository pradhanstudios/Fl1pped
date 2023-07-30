#pragma once

#include "raylib.h"

class Platform
{
private:
    Rectangle rect;
    Color tile;

public:
    Platform(Vector2 position, Vector2 size, Color tile);
    void draw_tile();
    Vector2 get_size();
    Vector2 get_position();
};