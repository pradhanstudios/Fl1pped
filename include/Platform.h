#pragma once

#include "raylib.h"

class Platform
{
private:
    Vector2 size;
    Vector2 position;
    Color tile;
    // Texture2D tile;
public:
    Platform(Vector2 position, Vector2 size, Color tile);
    void draw_tile();
};