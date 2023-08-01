#pragma once
#include "raylib.h"

class SplitScreen
{
private:
    RenderTexture2D screen;
    Rectangle split_screen_rect;

public:
    SplitScreen();
    void start();
    void end();
    void combine(RenderTexture2D screen2);
    void free();
    RenderTexture2D get_texture();
};