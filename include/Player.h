#pragma once

#include "raylib.h"

#define FRICTION (double)-0.001;
#define GRAVITY (double)0.5;
#define ACCELERATION (double)0.5;

class Player
{
private:
    Vector2 position;
    Vector2 velocity;
    Vector2 acceleration;
    Vector2 size;
    Color skin;
    // Texture2D skin;

public:
    Player(Vector2 position, Vector2 size, Color skin); // Texture2D skin
    void draw_player();
    void move();
    void jump();
};