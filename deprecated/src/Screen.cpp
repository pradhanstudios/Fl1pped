#include "Screen.h"

Screen::Screen()
{

    this->screen = LoadRenderTexture(GetScreenWidth() / 2, GetScreenHeight());
    this->split_screen_rect = {0.0f,
                               0.0f,
                               (float)this->screen.texture.width,
                               (float)-this->screen.texture.height};
}

RenderTexture2D Screen::get_texture()
{
    return this->screen;
}

void Screen::start()
{
    BeginTextureMode(this->screen);
}
void Screen::end()
{
    EndTextureMode();
}
void Screen::combine(RenderTexture2D screen2)
{
    DrawTextureRec(this->screen.texture, this->split_screen_rect, (Vector2){0, 0}, WHITE);
    DrawTextureRec(screen2.texture, this->split_screen_rect, (Vector2){GetScreenWidth() / 2.0f, 0}, WHITE);
    DrawLineV({(float)GetScreenWidth() / 2, 0.0}, {(float)GetScreenWidth() / 2, (float)GetScreenHeight()}, BLACK);
}
void Screen::free()
{
    UnloadRenderTexture(this->screen);
}