#pragma once

#include "Platform.h"
#include "raylib.h"

#define FRICTION (double)-0.12;
#define GRAVITY (double)0.5;
#define ACCELERATION (double)0.5;

class Player
{
private:
    Vector2 size;
    Vector2 position;
    Vector2 velocity;
    Vector2 acceleration;
    Color skin;
    // Texture2D skin;
    bool can_jump;

public:
    Player(Vector2 position, Vector2 size, Color skin); // Texture2D skin
    void draw_player();
    void update(Platform plat);
    void update(Platform *platforms, int num_platforms);
    void move(Platform plat);
    void jump();
    bool collides_with_platform(Platform platform);
    Vector2 get_position();
    Vector2 get_velocity();
    Vector2 get_size();
    bool get_jump();
};