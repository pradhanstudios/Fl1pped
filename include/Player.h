#pragma once

#include "Platform.h"
#include "raylib.h"

#include <stdio.h>
#include <vector>
#include <algorithm>

#define FRICTION (double)-0.12;
#define GRAVITY (double)0.5;
#define ACCELERATION (double)0.5;

class Player
{
private:
    Rectangle rect;
    Vector2 velocity;
    Vector2 acceleration;
    Color skin;
    int controls[3];
    int up;
    int left;
    int right;
    // Texture2D skin;
    // bool can_jump;
    std::vector<Vector2> collision_points;
    Vector2 point_1;
    Vector2 point_2;
    Vector2 point_3;
    Vector2 point_4;
    Vector2 point_5;
    Vector2 point_6;
    Vector2 point_7;
    Vector2 point_8;
    Vector2 point_9;

public:
    Player(Vector2 position, Vector2 size, Color skin, int controls[3]);
    // Player(Vector2 position, Vector2 size, Texture2D skin);
    void update_collision_points();
    Vector2 get_position();
    Vector2 get_velocity();
    Vector2 get_acceleration();
    Vector2 get_size();
    // bool get_jump();
    void draw_player();
    void update(Platform plat);
    void update(std::vector<Platform> platforms, int num_platforms);
    void move(Platform plat);
    void move(std::vector<Platform> platforms, int num_platforms);
    void jump();
    std::vector<Vector2> collides_with_platform(Platform platform);
    // Platform collides_with_platform(Platform *platforms, int num_platforms);
    std::vector<int> collides_with_platform(std::vector<Platform> platforms, int num_platforms);
    void set_position(Vector2 position);
};