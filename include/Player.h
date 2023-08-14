#pragma once

#include "Platform.h"
#include "raylib.h"

#include <stdio.h>
#include <vector>
#include <algorithm>

#define FRICTION (double)-0.12;
#define GRAVITY (double)0.5;
#define ACCELERATION (double)1.0;
#define JUMP (double)11.0

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
    int dir;
    int bot_screen_warp;
    int top_screen_warp;
    // Texture2D skin;
    // bool can_jump;
    std::vector<Vector2> collision_points;
    int collided_points[17];
    Vector2 point_1;
    Vector2 point_2;
    Vector2 point_3;
    Vector2 point_4;
    Vector2 point_5;
    Vector2 point_6;
    Vector2 point_7;
    Vector2 point_8;
    Vector2 point_9;
    Vector2 thresh_point_1;
    Vector2 thresh_point_2;
    Vector2 thresh_point_3;
    Vector2 thresh_point_4;
    Vector2 thresh_point_5;
    Vector2 thresh_point_6;
    Vector2 thresh_point_7;
    Vector2 thresh_point_8;

public:
    Player(Vector2 position, Vector2 size, Color skin, int controls[3], int dir);
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
    void collides_with_platform(Platform platform);
    // Platform collides_with_platform(Platform *platforms, int num_platforms);
    void collides_with_platform(std::vector<Platform> platforms, int num_platforms);
    void set_position(Vector2 position);
    int get_dir() { return this->dir; };
    void set_bot_screen_warp(int arg);
    void set_top_screen_warp(int arg);
};