#pragma once

#include "raylib.h"

#define FRICTION (double)-0.12;

class Player
{
private:
    Vector2 size;
    Vector2 position;
    Vector2 velocity;
    Vector2 acceleration;
    // Texture2D skin;

public:
    Player(Vector2 position, Vector2 velocity, Vector2 acceleration, Vector2 size); // TODO: implement Texture2D skin
    void move();
    void jump();
};