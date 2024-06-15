#pragma once
#include "raylib.h"

class Screen
{
private:
    RenderTexture2D screen;
    Rectangle split_screen_rect;

public:
    Screen();
    void start();
    void end();
    void combine(RenderTexture2D screen2);
    void free();
    RenderTexture2D get_texture();
};