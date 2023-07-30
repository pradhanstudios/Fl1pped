#pragma once

#include "raylib.h"

class Platform
{
private:
    float size;
    Vector2 position;
    Color tile;
    // Texture2D tile;
    Rectangle rect;

public:
    Platform(Vector2 position, Color tile);
    void draw_tile();
    float get_size();
    Vector2 get_position();
    // Color get_tile();
};